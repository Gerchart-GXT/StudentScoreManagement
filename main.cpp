#include "optionHandle.h"

void menu()
{
    puts("——————————");
    puts("Welcome to Student achievement management system!!!");
    puts("——————————");
    puts("1--Print all students; details");
    puts("2--Insert a new member");
    puts("3--Delete a student with its name");
    puts("4--Sort all students with score");
    puts("0--Exit");
    puts("——————————");
}

int main()
{
    menu();
    puts("@build by Gerchart");
    int op = 0;
    auto list = buildlinklist();
    while (std::cin >> op) {
        if (op == 1) {
            printAllStudent(list);
        } else if (op == 2) {
            std::string name;
            double score = 0;
            puts("Input new name:");
            std::cin >> name;
            puts("Input its score:");
            std::cin >> score;
            auto tval = new Student(name, score);
            tval->print();
            if (insertStudent(list, tval))
                puts("Insert Successful!");
            else
                puts("Insert erro");
        } else if (op == 3) {
            std::string name;
            puts("Input its name you want to delete:");
            std::cin >> name;
            if (deleteStudent(list, name))
                puts("delete successful!");
            else
                puts("delete erro!");
        } else if (op == 4) {
            auto end = list;
            while (end->getNext() != nullptr) {
                end = end->getNext();
            }
            int sop = 0;
            puts("In ascending (descending) order of grades? (0/1)?");
            while (std::cin >> sop) {
                if (sop == 0) {
                    if (list->getNext() != nullptr) {
                        auto nlist = mergeSort(list->getNext(), end, 0);
                        list->changeNext(nlist);
                    }
                    break;
                }
                if (sop == 1) {
                    if (list->getNext() != nullptr) {
                        auto nlist = mergeSort(list->getNext(), end, 1);
                        list->changeNext(nlist);
                    }
                    break;
                }
                puts("In ascending (descending) order of grades? (0/1)?");
            }
        } else if (op == 0)
            break;
        else
            puts("Input erro!");
        puts("Press any key to return the menu!");
        getchar();
        getchar();
        menu();
    }
    puts("Press any key to exit!");
    getchar();
    getchar();
    return 0;
}
