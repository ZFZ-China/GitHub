#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student
{
public:

	Student();
	Student(string name,int age);
	~Student();

	string getName();
	void setName(string name);

	int getAge();
	void setAge(int age);

private:

	string name;
	int age;

};