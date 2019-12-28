#pragma once
#include<iostream>
#include<string>
using namespace std;

#include "LinkPlus.hpp"
#include "LinkUnit.hpp"
#include "Student.h"

class Priner
{
public:


	static Priner* getPriner();

	void printLink(LinkPlus<Student>*& Obj) const;
	void printLink(LinkPlus<int>*& Obj) const;

private:

	Priner();
	~Priner();

	static Priner* pPriner;

};