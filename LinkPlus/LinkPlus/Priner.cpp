#include<iostream>
#include<string>
using namespace std;

#include "Printer.h"

Priner* Priner::pPriner = new Priner();

Priner::Priner()
{
}

Priner::~Priner()
{
}

Priner* Priner::getPriner()
{
	return pPriner;
}

void Priner::printLink(LinkPlus<Student>*& Obj) const
{
	if (Obj == NULL)return;

	LinkUnit<Student>* tmp = Obj->getHeader()->getNext();

	while (tmp != NULL)
	{
		cout << "姓名:" << tmp->getData()->getName() << " 年龄:" << tmp->getData()->getAge() << endl;
		tmp = tmp->getNext();
	}

	return;
}

void Priner::printLink(LinkPlus<int>*& Obj) const
{
	if (Obj == NULL)return;

	LinkUnit<int> * tmp = Obj->getHeader()->getNext();

	while (tmp != NULL)
	{
		cout << "Value: " << *(tmp->getData()) << endl;
		tmp = tmp->getNext();
	}

	return;
}
