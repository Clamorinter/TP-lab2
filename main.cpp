#include "fsstreams.h"
#include "student.h"
#include <iostream>

double get_arithm_score(Student stud);

void student_merge_sort(vector<Student>& studs);

int main(void)
{
	
	return 0;
}

double get_arithm_score(Student stud)
{
	vector<int> scores = stud.getScore();
	int sr = 0, N = scores.length();
	double ret;
	for (int i = 0; i < N; i++)
	{
		sr += scores[i];
	}
	ret = (double)sr / (double)N;
	return ret;
}