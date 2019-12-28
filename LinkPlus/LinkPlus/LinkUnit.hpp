#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class Object>
class LinkUnit
{
public:

	LinkUnit();
	~LinkUnit();

	Object* getData();
	void setData(Object* entry);

	LinkUnit<Object>* getNext();
	void setNext(LinkUnit* next);

private:

	Object* data;
	LinkUnit* next;

};

template<class Object>
LinkUnit<Object>::LinkUnit()
{
	this->data = NULL;
	this->next = NULL;
}

template<class Object>
LinkUnit<Object>::~LinkUnit()
{

}

template<class Object>
Object* LinkUnit<Object>::getData()
{
	return this->data;
}

template<class Object>
void LinkUnit<Object>::setData(Object* entry)
{
	this->data = entry;
	return;
}

template<class Object>
LinkUnit<Object>* LinkUnit<Object>::getNext()
{
	return this->next;
}

template<class Object>
void LinkUnit<Object>::setNext(LinkUnit<Object>* next)
{
	this->next = next;
	return;
}