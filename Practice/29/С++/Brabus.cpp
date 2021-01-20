#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>


using namespace std;
using std::to_string;

//...БОЗОСОРТ ЧАСТЬ...
template <class T>
using vector_t = vector<T>;

template <class T>
bool is_more(const T& first, const T& second)
{
    return first > second;
}

template <class T>
bool is_less(const T& first, const T& second)
{
    return first < second;
}

template <class T>
bool is_sorted(const vector_t<T>& vector, const bool& asc)
{
    const auto sort = asc ? is_more<T> : is_less<T>;

    for (size_t i = 1; i < vector.size(); ++i)
    {
        if (sort(vector[i - 1], vector[i]))
        {
            return false;
        }
    }

    return true;
}

template <class T>
vector_t<T> BozoSort(const vector_t<T>& vector, const bool& asc)
{
    vector_t<T> result = vector;
    if (vector.size() < 2)
    {
        return result;
    }

    const size_t size = result.size();
    while (!is_sorted(result, asc))
    {
        swap(result[rand() % size], result[rand() % size]);
    }
    return result;
}

//...Структура студентов...
struct Student
{
    map<string, int> examsU; //создается контейнер для хранения отметок по экзаменам
    string nameU;//переменная имени
    int groupU;// и группы

    Student(string name, int group, int math, int phys, int hist, int prog)
    {
   
        if (group < 1 or group > 9)
            
            throw invalid_argument("Неверная группа, этот парень заблудился похоже " + to_string(group));
       
        if (math < 0 or math > 9 or phys < 0 or phys > 9 or hist < 0 or hist > 9 or prog < 0 or prog > 9)
            
            throw invalid_argument("Как ты такую отметку получил то? Ограничения не видел? " + to_string(math) + ", " + to_string(phys) + ", " 
                + to_string(hist) + ", " + to_string(prog));

        examsU = { {"math", math}, {"phys", phys}, {"hist", hist}, {"prog", prog} };
        nameU = name;
        groupU = group;
    }

friend ostream& operator << (ostream& out, const Student& student) //это дружественный элемент который имеет доступ к элементам структуры Student
    {
        auto NameLen = max(int(student.nameU.length()), 4);
        auto NameDelim = string(NameLen, '-');
        out << "+-" << NameDelim << "-+-------+------+------+------+------+\n"
            << "| Name " << string(NameLen - 4, ' ')
            << "| Group | Math | Phys | Hist | Prog |\n"
            << "+-" << NameDelim << "-+-------+------+------+------+------+\n"
            << "| " << student.nameU << " | " << student.groupU
            << "     | " << student.examsU.at("math")
            << "    | " << student.examsU.at("phys")
            << "    | " << student.examsU.at("hist")
            << "    | " << student.examsU.at("prog")
            << "    |\n"
            << "+-" << NameDelim << "-+-------+------+------+------+------+\n";
        return out;
    }
};

ostream& operator << (ostream& out, const vector<Student>& StudentVect)
{
    auto NameLen = StudentVect.at(0).nameU.length();
    for (auto cur = StudentVect.begin() + 1; cur != StudentVect.end(); ++cur)
    {
        if (cur->nameU.length() > NameLen)
        {
            NameLen = cur->nameU.length();
        }
    }
    auto NameDelim = string(NameLen, '-');
    out << "+-" << NameDelim << "-+-------+------+------+------+------+\n"
        << "| Name " << string(NameLen - 4, ' ')
        << "| Group | Math | Phys | Hist | Prog |\n"
        << "+-" << NameDelim << "-+-------+------+------+------+------+\n";

    for (auto& student : StudentVect) {
        out << "| " << student.nameU
            << string(NameLen - student.nameU.length(), ' ')
            << " | " << student.groupU
            << "     | " << student.examsU.at("math")
            << "    | " << student.examsU.at("phys")
            << "    | " << student.examsU.at("hist")
            << "    | " << student.examsU.at("prog")
            << "    |\n"
            << "+-" << NameDelim << "-+-------+------+------+------+------+\n";
    }
    return out;
};

int main()
{ 
    srand(time(0));
  
    vector<Student> students = {
        Student("Blizinsky",5, 2, 3, 2, 4),
        Student("Chumba",    2, 2, 3, 3, 4),
        Student("Brabus",      4, 5, 5, 3, 5),
        Student("Sanya",   3, 3, 3, 4, 2),
        Student("Korsanya",     3, 3, 3, 3, 5),
        Student("Popersanya",     5, 4, 2, 4, 5),
        Student("Robert",         4, 3, 2, 3, 5),
        Student("Gordon Freeman",       5, 4, 5, 5, 5),
        Student("Balbes",     2, 3, 3, 4, 5),
        Student("Bozoso",        4, 3, 3, 4, 5),
    };

    auto has_failed = [](Student& student) -> bool {
        for (auto& pair : student.examsU)
        {
            if (pair.second == 2)
            {
                return true;
            }
        }
        return false;
    };


    vector<Student> failed;
    for (auto& student : students)
    {
        if (has_failed(student))
        {
            failed.push_back(student);
        }
    }
    if (failed.size() > 0)
    {
        cout << failed <<"\n";

        cout << "\nExplusion\n"
            << failed.at(rand() % failed.size()) << "\n";
    }
    else
    {
        cout << "Not found\n";
    }
}