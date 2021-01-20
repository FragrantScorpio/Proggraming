#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cctype>

using namespace std;

enum class ItemType
{
	WEAPON, ARMOR, COIN, RUNE,
};

struct Weapon
{
	size_t damage;
	size_t critical;
	size_t durability;
};

struct Armor
{
	size_t guard;
	size_t durability;
};


struct Coin
{
	size_t count;
};

enum class Element
{
	FIRE, WATER, EARTH, AIR
};

struct Rune
{
	 Element element;
	size_t level;
};

string to_string(Rune& rune)
{
	string result;

	switch (rune.element)
	{
	case Element::FIRE:
		result = "fire";
		break;
	case Element::WATER:
		result = "water";
		break;
	case Element::EARTH:
		result = "earth";
		break;
	case Element::AIR:
		result = "air";
		break;
	}

	return result;
}



union ItemTypeUnion
{
	Coin coin;
	Rune rune;
	Weapon weapon;
	Armor armor;

	ItemTypeUnion(const Coin& coin)
	{
		this->coin = coin;
	}

	ItemTypeUnion(const Rune& rune)
	{
		this->rune = rune;
	}

	ItemTypeUnion(const Weapon& weapon)
	{
		this->weapon = weapon;
	}

	ItemTypeUnion(const Armor& armor)
	{
		this->armor = armor;
	}
};

struct Item
{
	ItemType type;

	ItemTypeUnion value;

	static Item GetCoin(const unsigned int count)
	{
		return {
			Item{
				ItemType::COIN,
				ItemTypeUnion{Coin{count}}
			}
		};
	}

	static Item GetRune(const Element element, const size_t level)
	{
		return
		{
			Item{
				ItemType::RUNE,
				ItemTypeUnion{Rune{element, level}}
			}
		};
	}

	static Item GetWeapon(const unsigned int damage, const size_t critical, const size_t durability)
	{
		return {
			Item{
				ItemType::WEAPON,
				ItemTypeUnion{Weapon{damage, critical, durability}}
			}
		};
	}

	static Item GetArmor(const unsigned int guard, const size_t durability)
	{
		return {
			Item{
				ItemType::ARMOR,
				ItemTypeUnion{Armor{guard, durability}}
			}
		};
	}

	Item& operator++()
	{
		return *this;
	}
};

using LootBox = std::vector<Item>;

ostream& operator <<(ostream& stream, const Item& item)
{
	const ItemType type = item.type;

	if (type == ItemType::COIN)
	{
		stream << item.value.coin.count << " gold\n" ;
	}
	else if (type == ItemType::RUNE)
	{
		Rune rune = item.value.rune;
		stream << "Rune of " << to_string(rune) << " level " << rune.level << "\n";
	}
	else if (type == ItemType::WEAPON)
	{
		Weapon weapon = item.value.weapon;
		stream << "Weapon {damage: " << weapon.damage << ", critical: " << weapon.critical << ", durability: " << weapon.durability << "}\n" ;
	}
	else if (type == ItemType::ARMOR)
	{
		const Armor armor = item.value.armor;
		stream << "Armor {guard: " << armor.guard << ", durability: " << armor.durability << "}\n" ;
	}
	else
	{
		cout << "Предмет зачарован таинственной магией, которая человечеству еще не известна";
	}

	return stream;
}

ostream& operator <<(ostream& stream, const LootBox& box)
{
	for (const Item& item : box)
	{
		stream << item;
	}

	return stream << flush;//flush освобождает буфер
}

LootBox& operator<<(LootBox& box, Item& item)
{
	box.push_back(item);
	return box;
}

vector<pair<Item, double>> bag
{
	{Item::GetCoin(1000), 50.0},
	{Item::GetWeapon(100, 0, 100), 1.4},
	{Item::GetWeapon(75, 50, 100), 1.4},
	{Item::GetArmor(50, 100), 2.8},
	{Item::GetRune(Element::FIRE, 1), 6.0},
	{Item::GetRune(Element::WATER, 1), 13.0},
	{Item::GetRune(Element::EARTH, 1), 7.0},
	{Item::GetRune(Element::AIR, 1), 14.0},
	{Item::GetRune(Element::FIRE, 5), 0.6},
	{Item::GetRune(Element::WATER, 5), 1.3},
	{Item::GetRune(Element::EARTH, 5), 0.7},
	{Item::GetRune(Element::AIR, 5), 1.4},
	{Item::GetRune(Element::FIRE, 5), 0.06},
	{Item::GetRune(Element::WATER, 5), 0.13},
	{Item::GetRune(Element::EARTH, 5), 0.07},
	{Item::GetRune(Element::AIR, 5), 0.14},
};

LootBox generateLootBox()
{
	LootBox box;
	srand(time(nullptr));

	for (int i = 0; i < 3; ++i)
	{
		// [0.00; 100.00)
		const double random = static_cast<double>(rand() % 10000) / 100;
		double sum = 0;

		for (const auto& pair : bag)
		{
			if (sum <= random && random < sum + pair.second)
			{
				box.push_back(pair.first);
				break;
			}

			sum += pair.second;
		}
	}

	return box;
}

char to_lower(const char chr)
{
	return static_cast<char>(tolower(static_cast<unsigned char>(chr)));
}

void to_lower(string& str)
{
	transform(str.begin(), str.end(), str.begin(),
		[](const unsigned char chr) { return to_lower(chr); }
	);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	do
	{
		cout << "Открыть лутбокс? Yes/No\n";

		string input;
		cin >> input;
		to_lower(input);

		if (input == "yes" or input == "y")
		{
			auto box = generateLootBox();
			cout << box;
		}
		else if (input == "no" or input == "n")
		{
			break;
		}


	} while (true);
};