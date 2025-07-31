#include <iostream>
using namespace std;

class Student
{
	int roll;
	float marks;

public:
	void input(int r, float m)
	{
		roll = r;
		marks = m;
	}

	void display()
	{
		cout << "Roll: " << roll << ", Marks: " << marks << endl;
	}
};

int main()
{
	Student s[3]; // Array of 3 Student objects

	for (int i = 0; i < 3; i++)
	{
		int r;
		float m;
		cout << "Enter roll and marks for student " << i + 1 << ": ";
		cin >> r >> m;
		s[i].input(r, m);
	}

	for (int i = 0; i < 3; i++)
	{
		s[i].display();
	}

	return 0;
}
