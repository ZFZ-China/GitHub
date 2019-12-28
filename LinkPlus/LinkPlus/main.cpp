#include<iostream>
#include<string>
using namespace std;

#include "Student.h"
#include "LinkPlus.hpp"
#include "LinkUnit.hpp"
#include "Printer.h"

int main() {

	//Test
	Student* stu1 = new Student("张三", 12);
	Student* stu2 = new Student("李四", 13);
	Student* stu3 = new Student("王五", 14);
	Student* stu4 = new Student("赵六", 15);
	Student* stu5 = new Student("宋七", 16);
	Student* stu6 = new Student("蒋八", 17);
	
	LinkPlus<Student>* StuLink = new LinkPlus<Student>();
	Priner* pr = Priner::getPriner();

	StuLink->insert_LinkList(stu1, 0);
	StuLink->insert_LinkList(stu2, 0);
	StuLink->insert_LinkList(stu3, 0);

	StuLink->insert_LinkList(stu1,stu4);

	cout << "-----------" << endl;
	pr->printLink(StuLink);
	
	cout << "-----------" << endl;
	StuLink->modify_LinkList(stu5,1,true);
	pr->printLink(StuLink);

	cout << "-----------" << endl;
	StuLink->modify_LinkList(stu3,stu6,true);
	pr->printLink(StuLink);

	cout << "-----------" << endl;
	StuLink->delete_LinkList(3, true);
	pr->printLink(StuLink);

	cout << "-----------" << endl;
	StuLink->delete_LinkList(stu5, true);
	pr->printLink(StuLink);

	StuLink->clear_LinkList();
	delete StuLink;
	

	return 0;
}