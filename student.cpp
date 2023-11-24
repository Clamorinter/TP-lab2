#include "student.h"

Student::Student() {}
Student::Student(std::string FIO, int group, vector<int> score)
{
	this->FIO = FIO;
	this->group = group;
	
}
Student::Student(const Student& original)
{

}

Student::~Student()
{

}

std::string Student::getFIO() const
{

}
int Student::getGroup() const
{

}
vector<int> Student::getScore() const 
{

}

void Student::setFIO(std::string FIO)
{

}
void Student::setGroup(int group)
{

}
void Student::setScore(vector<int> score)
{

}

void Student::add_score(int grade)
{

}
int Student::delete_score(int number)
{

}

std::ostream& operator<< (std::ostream& os, const Student& stud)
{

}
std::istream& operator>> (std::istream& is, const Student& stud)
{

}

Student& operator>> (Student& stud, std::string FIO)
{

}
Student& operator>> (Student& stud, int group)
{

}
Student& operator>> (Student& stud, int* score)
{

}