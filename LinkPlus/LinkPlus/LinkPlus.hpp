#pragma once
#include<iostream>
#include<string>
using namespace std;

#include "LinkUnit.hpp"

template<class Object>
class LinkPlus
{
public:

	//Ĭ�Ϲ��캯���Զ����Ѵ���ͷ�ڵ���󣬽ڵ�����Զ���ʼ��������ΪNULL
	 LinkPlus();

	 //���������ظ�ֵ����ǳ������
	 LinkPlus(const LinkPlus&);
	 LinkPlus& operator=(const LinkPlus&);

	 //��������Ĭ�ϲ������������ݣ�ֻ�������нڵ����Ϊͷ������
	~ LinkPlus();

	//��ȡͷ��λ
	LinkUnit<Object>* getHeader();

	//��ȡ����
	int getSize();


	//---��Ϊ���������Ա---

	//�������� ����ָ��λ��
	Object& getValue_LinkList(int Index);

	//�������� ����ָ��λ��
	void insert_LinkList(Object*& entry,int Index);

	//�������� ����ǰֵ
	void insert_LinkList(Object*& pre, Object*& entry);

	//�޸����� ����ָ���±� Flag����TRUE�����ԭ��λ�����ݣ��෴�������ڴ���
	void modify_LinkList(Object*& entry, int Index, bool flag);

	//�޸����� ������ֵ֪ Flag����TRUE�����ԭ��λ�����ݣ��෴�������ڴ���
	void modify_LinkList(Object*& OpsObj, Object*& entry, bool flag);

	//ɾ���ڵ� ����ָ���±� Flag����TRUE�����ԭ��λ�����ݣ��෴�������ڴ���
	void delete_LinkList(int Index, bool flag);

	//ɾ���ڵ� ������ֵ֪ Flag����TRUE�����ԭ��λ�����ݣ��෴�������ڴ���
	void delete_LinkList(Object*& OpsObj, bool flag);

	//�������� ����ڵ� ��������ڴ浱������
	void reset_LinkList();

	//�������� ����ڵ���ڴ�����
	void clear_LinkList();

private:

	LinkUnit<Object>* header;
	int size;
	
};


template<class Object>
LinkPlus<Object>::LinkPlus()
{
	this->header = new LinkUnit<Object>();
	this->size = 0;

}

template<class Object>
LinkPlus<Object>::LinkPlus(const LinkPlus& entry)
{
	reset_LinkList();

	this->header = new LinkUnit<Object>();
	this->header->next = entry.getHeader()->getNext();
	this->size = entry.getSize();

}

template<class Object>
LinkPlus<Object>& LinkPlus<Object>::operator=(const LinkPlus& entry)
{
	reset_LinkList();

	if (this->header != NULL)
	{
		delete this->header;
		this->header = NULL;
	}

	this->header = new LinkUnit<Object>();
	this->header->next = entry.getHeader()->getNext();
	this->size = entry.getSize();

	return *this;
}

template<class Object>
LinkPlus<Object>::~LinkPlus()
{
	reset_LinkList();
	delete this->header;
	this->header = NULL;
}

template<class Object>
LinkUnit<Object>* LinkPlus<Object>::getHeader()
{
	return this->header;
}

template<class Object>
int LinkPlus<Object>::getSize()
{
	return this->size;
}

template<class Object>
Object& LinkPlus<Object>::getValue_LinkList(int Index)
{
	if (Index < 0 || Index >(this->size - 1))return;

	LinkUnit<Object>* tmp = this->getHeader()->getNext();
	if (tmp == NULL)return;

	int i = 0;
	while (i < Index)
	{
		tmp = tmp->getNext();
		i++;
	}

	if (i == Index && tmp != NULL)
	{
		return tmp->getData();
	}

	return NULL;
}

template<class Object>
void LinkPlus<Object>::insert_LinkList(Object*& entry, int Index)
{
	if (entry == NULL)return;
	if (Index < 0 || Index >(this->size - 1))
	{
		Index = this->size;
	}

	LinkUnit<Object>* tmp = this->getHeader()->getNext();

	int i = 0;
	if (tmp != NULL)
	{
		while (i != Index)
		{
			tmp = tmp->getNext();
			++i;
		}
	}

	if (i == Index && tmp != NULL)
	{
		LinkUnit<Object>* newUnit = new LinkUnit<Object>();

		newUnit->setData(entry);
		newUnit->setNext(tmp->getNext());
		tmp->setNext(newUnit);

		++this->size;
	}
	else if (i == Index && tmp == NULL)
	{
		LinkUnit<Object>* newUnit = new LinkUnit<Object>();

		this->header->setNext(newUnit);
		newUnit->setData(entry);
		newUnit->setNext(NULL);

		++this->size;
	}
	
	return;
}

template<class Object>
void LinkPlus<Object>::insert_LinkList(Object*& pre, Object*& entry)
{
	if (pre == NULL)return;
	if (entry == NULL)return;

	LinkUnit<Object>* preTmp = this->getHeader()->getNext();
	if (preTmp == NULL)return;

	while (preTmp->getData() != pre && preTmp != NULL)
	{
		preTmp = preTmp->getNext();
	}

	if (preTmp->getData() == pre && preTmp != NULL)
	{
		LinkUnit<Object>* newUnit = new LinkUnit<Object>();

		newUnit->setData(entry);
		newUnit->setNext(preTmp->getNext());
		preTmp->setNext(newUnit);

		++this->size;
	}

	return;
}

template<class Object>
void LinkPlus<Object>::modify_LinkList(Object*& entry, int Index,bool flag)
{
	if (entry == NULL)return;
	if (Index < 0 || Index >(this->size - 1))return;

	LinkUnit<Object>* tmp = this->getHeader()->getNext();
	if (tmp == NULL)return;

	int i = 0;
	if (tmp != NULL)
	{
		while (i < Index)
		{
			tmp = tmp->getNext();
			++i;
		}
	}

	if (i == Index && tmp != NULL)
	{
		if (flag)
		{
			delete tmp->getData();
			tmp->setData(entry);
		}
		else
		{
			tmp->setData(entry);
		}
	}

	return;
}

template<class Object>
void LinkPlus<Object>::modify_LinkList(Object*& OpsObj, Object*& entry, bool flag)
{
	if (OpsObj == NULL)return;
	if (entry == NULL)return;

	LinkUnit<Object>* tmp = this->getHeader()->getNext();
	if (tmp == NULL)return;

	while (tmp->getData() != OpsObj && tmp != NULL)
	{
		tmp = tmp->getNext();
	}

	if (tmp->getData() == OpsObj && tmp != NULL)
	{
		if (flag)
		{
			delete tmp->getData();
			tmp->setData(entry);
		}
		else
		{
			tmp->setData(entry);
		}
	}

	return;
}

template<class Object>
void LinkPlus<Object>::delete_LinkList(int Index, bool flag)
{
	if (Index < 0 || Index >(this->size - 1))return;

	LinkUnit<Object> * tmp = this->getHeader()->getNext();
	if (tmp == NULL)return;

	LinkUnit<Object>* record = tmp;

	int i = 0;
	while (i < Index && tmp != NULL)
	{
		record = tmp;
		tmp = tmp->getNext();
		++i;
	}

	if (i == Index && tmp != NULL)
	{
		if (flag)
		{
			delete tmp->getData();
			record->setNext(tmp->getNext());
			delete tmp;
			tmp = NULL;

			--this->size;
		}
		else
		{
			record->setNext(tmp->getNext());
			delete tmp;
			tmp = NULL;

			--this->size;
		}
	}

	return;
}

template<class Object>
void LinkPlus<Object>::delete_LinkList(Object*& OpsObj, bool flag)
{
	if (OpsObj == NULL)return;

	LinkUnit<Object>* tmp = this->getHeader()->getNext();
	if (tmp == NULL)return;

	LinkUnit<Object> * record = tmp;

	while (tmp->getData() != OpsObj && tmp != NULL)
	{
		record = tmp;
		tmp = tmp->getNext();
	}

	if (tmp->getData() == OpsObj && tmp != NULL)
	{
		if (flag)
		{
			delete tmp->getData();
			record->setNext(tmp->getNext());
			delete tmp;
			tmp = NULL;

			--this->size;
		}
		else
		{
			record->setNext(tmp->getNext());
			delete tmp;
			tmp = NULL;

			--this->size;
		}
	}

	return;
}

template<class Object>
void LinkPlus<Object>::reset_LinkList()
{
	LinkUnit<Object>* tmp = this->header->getNext();

	while (tmp != NULL)
	{
		LinkUnit<Object>* cache = tmp->getNext();
		delete tmp;
		tmp = cache;
	}
	tmp = NULL;

	this->header->setNext(NULL);
	this->size = 0;

	return;
}

template<class Object>
void LinkPlus<Object>::clear_LinkList()
{

	LinkUnit<Object>* tmp = this->header->getNext();

	while (tmp != NULL)
	{
		LinkUnit<Object>* cache = tmp->getNext();
		delete tmp->getData();
		delete tmp;
		tmp = cache;
	}
	tmp = NULL;

	this->header->setNext(NULL);
	this->size = 0;

	return;
}