#pragma once
#include <string>
#include <iostream>

class Student {
public:
	Student();
	Student(std::string FIO, int group, int* score);
	Student(const Student& original);

	std::string getFIO() const;
	int getGroup() const;
	int* getScore() const;

	void setFIO(std::string FIO);
	void setGroup(int group);
	void setScore(int* score);

	void add_score(int grade);
	int delete_score(int number);
	int length_of_score() const;

	friend std::ostream& operator<< (std::ostream& os, const Student& stud);
	friend std::istream& operator>> (std::istream& is, const Student& stud);

	friend Student& operator>> (Student& stud, std::string FIO);
	friend Student& operator>> (Student& stud, int group);
	friend Student& operator>> (Student& stud, int* score);
private:
	std::string FIO;
	int group;
	int* score;
};
