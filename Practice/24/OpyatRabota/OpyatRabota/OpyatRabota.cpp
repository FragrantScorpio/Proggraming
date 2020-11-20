#include <iostream>;
#include <iomanip>;
#include <fstream>;
#include "DLC/json.hpp";
using namespace std;
using json = nlohmann::json;

int main() {
    // Стрим чтения в и из файла
    ifstream input("in.json");
    ofstream output("out.json");

    json jinput;
    input >> jinput;
    json joutput;

    for (auto& task : jinput) {
        // получаем id пользователя и статус выполнения задания
        int userId = task["userId"];
        bool completed = task["completed"];
        json temp;
     // ссылка на пользователя и в итоге ссылка на объект вывода будет.
        json* user = &temp;
     // Ищем в выводе пользователя с id и userId
        for (auto& element : joutput) {
            if (element["userId"] == userId) {
                user = &element;
                break;
            }
        }
        //не нашли? тогда объект будет пустой и добавим новый объект в вывод
        if (user->empty()) {
            joutput.push_back({
                {
                    "userId",
                    userId
                },
                {
                    "task_completed",
                    0
                }
                });
            // сделаем user ссылкой на новосозданный файл
            user = &joutput[joutput.size() - 1];
        }
        // Если задание было выполнено увеличим счетчик выполнения задания на 1
        if (completed) {
            (*user)["task_completed"] = static_cast <int> ((*user)["task_completed"]) + 1;
        }
    }
    // Вывод 
    output << setw(2) << joutput << endl;
}
