#pragma once
#include<iostream>
#include<string>
using namespace std;

#include "LinkUnit.hpp"

template<class Object>
class LinkPlus
{
public:

	//默认构造函数自动开堆创建头节点对象，节点对象自动初始化两个域为NULL
	 LinkPlus();

	 //拷贝和重载赋值做防浅拷处理
	 LinkPlus(const LinkPlus&);
	 LinkPlus& operator=(const LinkPlus&);

	 //析构函数默认不清除管理的数据，只销毁所有节点和作为头的自身
	~ LinkPlus();

	//获取头单位
	LinkUnit<Object>* getHeader();

	//获取长度
	int getSize();


	//---下为链表操作成员---

	//查找数据 根据指定位置
	Object& getValue_LinkList(int Index);

	//插入数据 根据指定位置
	void insert_LinkList(Object*& entry,int Index);

	//插入数据 根据前值
	void insert_LinkList(Object*& pre, Object*& entry);

	//修改数据 根据指定下标 Flag传入TRUE则清除原有位置数据，相反则保留在内存中
	void modify_LinkList(Object*& entry, int Index, bool flag);

	//修改数据 根据已知值 Flag传入TRUE则清除原有位置数据，相反则保留在内存中
	void modify_LinkList(Object*& OpsObj, Object*& entry, bool flag);

	//删除节点 根据指定下标 Flag传入TRUE则清除原有位置数据，相反则保留在内存中
	void delete_LinkList(int Index, bool flag);

	//删除节点 根据已知值 Flag传入TRUE则清除原有位置数据，相反则保留在内存中
	void delete_LinkList(Object*& OpsObj, bool flag);

	//重置链表 清除节点 但不清除内存当中数据
	void reset_LinkList();

	//清理链表 清除节点和内存数据
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