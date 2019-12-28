#include<iostream>
#include<string>
using namespace std;

#include "Student.h"



Student::Student()
{
	
}

Student::Student(string name, int age)
{
	this->name = name;
	this->age = age;
}

Student::~Student()
{

}

string Student::getName()
{
	return this->name;
}

void Student::setName(string name)
{
	this->name = name;
}

int Student::getAge()
{
	return this->age;
}

void Student::setAge(int age)
{
	this->age = age;
}
