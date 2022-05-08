#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    double score;

public:
    Student();
    Student(std::string name, double score);
    std::string getName();
    double getScore();
    bool equal(Student* e);
    void print();
    const bool operator<(const Student* e) const;
    const bool operator>(const Student* e) const;
};

Student::Student(std::string name, double score)
{
    this->name = name;
    this->score = score;
}
Student::Student()
{
    this->name = nullptr;
    this->score = 0.0;
}
std::string Student::getName()
{
    return this->name;
}
double Student::getScore()
{
    return this->score;
}
bool Student::equal(Student* e)
{
    return e->getName() == this->name && e->getScore() == this->score;
}
void Student::print()
{
    puts("——————————");
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Score: " << this->score << std::endl;
    puts("——————————");
}
const bool Student::operator<(const Student* e) const
{
    return this->score > e->score;
}
const bool Student::operator>(const Student* e) const
{
    return this->score > e->score;
}