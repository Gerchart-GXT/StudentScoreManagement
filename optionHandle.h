#include "Linklist.h"
#include "Student.h"

Linklist* buildlinklist()
{
    auto list = new Linklist();
    return list;
}

bool insertStudent(Linklist* list, Student* val)
{
    auto tlist = list;
    bool hasname = false;
    while (tlist->getNext() != nullptr) {
        tlist = tlist->getNext();
        auto tval = (Student*)tlist->getVal();
        if (tval->getName() == val->getName()) {
            hasname = true;
            break;
        }
    }
    if (hasname) {
        std::cout << val->getName() << " has include!\n";
        return false;
    }
    auto nlist = new Linklist(val, list->getNext());
    list->changeNext(nlist);
    return true;
}
bool deleteStudent(Linklist* list, std::string name)
{
    while (list->getNext() != nullptr) {
        auto tlist = list->getNext();
        auto tval = (Student*)(tlist->getVal());
        if (tval->getName() == name) {
            std::cout << "Found!!\nThe details are as follow:\n";
            tval->print();
            std::string op;
            puts("Do you want to delete it(Y/N)?");
            while (std::cin >> op) {
                if (op == "Y") {
                    list->changeNext(list->getNext()->getNext());
                    delete tlist;
                    return true;
                }
                if (op == "N") {
                    return false;
                }
                puts("Input illegal,please try again!");
                puts("Do you want to delete it(Y/N)?");
            }
        }
        list = list->getNext();
    }
    puts("Student Not Found!");
    puts("Now return to the menu!");
    return false;
}

Linklist* mergeSort(Linklist* left, Linklist* right, int op)
{
    if (left == right) {
        return new Linklist(left->getVal(), nullptr);
    }
    int len = 0;
    auto tleft = left;
    while (tleft != right) {
        tleft = tleft->getNext();
        len++;
    }
    auto tmid = left;
    int cnt = len / 2;
    while (cnt--) {
        tmid = tmid->getNext();
    }
    left = mergeSort(left, tmid, op);
    auto mid = mergeSort(tmid->getNext(), right, op);
    auto i = left, j = mid;

    while (left->getNext() != nullptr)
        left = left->getNext();
    left->changeNext(mid);

    auto thead = buildlinklist();
    auto now = thead;
    while (i != nullptr && j != nullptr && i != mid && j != right->getNext()) {
        auto ival = (Student*)i->getVal();
        auto jval = (Student*)j->getVal();
        if (op == 0) {
            if (ival > jval) {
                auto node = new Linklist(ival, nullptr);
                now->changeNext(node);
                now = node;
                i = i->getNext();
            } else {
                auto node = new Linklist(jval, nullptr);
                now->changeNext(node);
                now = node;
                j = j->getNext();
            }
        }
        if (op == 1) {
            if (ival < jval) {
                auto node = new Linklist(ival, nullptr);
                now->changeNext(node);
                now = node;
                i = i->getNext();
            } else {
                auto node = new Linklist(jval, nullptr);
                now->changeNext(node);
                now = node;
                j = j->getNext();
            }
        }
    }
    while (i != nullptr && i != mid) {
        auto ival = (Student*)i->getVal();
        auto node = new Linklist(ival, nullptr);
        now->changeNext(node);
        now = node;
        i = i->getNext();
    }
    while (j != nullptr && j != right->getNext()) {
        auto jval = (Student*)j->getVal();
        auto node = new Linklist(jval, nullptr);
        now->changeNext(node);
        now = node;
        j = j->getNext();
    }
    return thead->getNext();
}

void printAllStudent(Linklist* list)
{
    if (list->getNext() == nullptr) {
        puts("List is empty!");
        puts("Return to the menu!");
        return;
    }
    puts("Now print all students' details:");
    while (list->getNext() != nullptr) {
        list = list->getNext();
        auto tval = (Student*)list->getVal();
        tval->print();
    }
    puts("Print over!");
    return;
}