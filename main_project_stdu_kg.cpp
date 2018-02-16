#include<iostream>
#include<string>
#include<stdlib.h>
#include <fstream>
using namespace std;


typedef struct student
{
	string firstName;
	string lastName;
	string id;
	float gpa;
//	int passedUnit;
//	float totalMark;
	string courses;

	struct student *next;
}std_n;

typedef struct courses
{
	char id[8];
	char courseName[18];
	int unit;
	float mark;
	char teacherName[20];
	
	struct courses *next;
}cour_n;

void addStudents(std_n* head_std);
void saveStdInFile(std_n* p);
void addCourses(cour_n* head_cour);
void saveCoursInFile(cour_n* p);
void savePlayerCoursInFile(std_n* p,cour_n* pp);
void addCourseForStudent(cour_n* head_cour,std_n* head_std);
void readStdFromFile(std_n* head_std);
void gpaProcess (std_n*head_std,cour_n*head_cour);
std_n* searchStduById(std_n* head_std,string x);
cour_n* searchCoursById(cour_n* head_cour,char* x);
void mainP(std_n* head_std,cour_n * head_cour);
int main()
{
	std_n * head_std=(std_n *)calloc(1,sizeof(std_n));
	cour_n * head_cour=(cour_n *)calloc(1,sizeof(cour_n));
	//FILE * students =fopen("students.txt","w");
	mainP(head_std,head_cour);
}
void mainP(std_n * head_std,cour_n * head_cour)
{

	int a;
	cin>>a;
	if(a==1)
	{
		addStudents(head_std);
		mainP(head_std,head_cour);
	}
	if (a==2)
	{
	 addCourseForStudent(head_cour,head_std);
	}
	if(a==3)
	{
		addCourses(head_cour);
		mainP(head_std,head_cour);
	}
	if(a==12)
	{
		return;
	}
	
}

void addStudents(std_n* p)
{
		std_n*pp =(std_n*) calloc(1, sizeof(std_n));
		pp=p;
		cin>>pp->firstName>>pp->lastName>>pp->id;
		saveStdInFile(p);
		pp = p->next;
}
void saveStdInFile(std_n* p)
{
		fstream  students;
		students.open("students.txt",ios::app);
		students << p->firstName <<","<<p->lastName<<","<<p->id<<endl;
		students.close();
}
void addCourses(cour_n* p)
{
		cour_n*pp =(cour_n*) calloc(1, sizeof(cour_n));
		pp=p;
		cin>>pp->courseName>>pp->id>>pp->unit>>pp->teacherName;
		saveCoursInFile(p);
		pp = p->next;
}
void  saveCoursInFile(cour_n* p)
{
		fstream  courses;
		courses.open("courses.txt",ios::app);
		courses << p->courseName <<","<<p->id <<","<<p->unit <<","<<p->teacherName<<endl;
		courses.close();
}
std_n* searchStduById(std_n* head_std,char* x)
{
	std_n*p =(std_n*) calloc(1, sizeof(std_n));
	p=head_std;
	while(p!=NULL)
	{
		if (p->id == x)
		{
			return p;
		}
		p=p->next;
	}

}
void addCourseForStudent(cour_n* head_cour,std_n* head_std)
{
	char x[6];
	cin>>x;
	std_n*p =(std_n*) calloc(1, sizeof(std_n));
	cour_n*pp =(cour_n*) calloc(1, sizeof(cour_n));
	p=searchStduById(head_std,x);
	char* z;
	cin>>z;
	pp=searchCoursById(head_cour,z);

	savePlayerCoursInFile(p,pp);

}
cour_n* searchCoursById(cour_n* head_cour,char* x)
{
	cour_n*p =(cour_n*) calloc(1, sizeof(cour_n));
	p=head_cour;
	while(p!=NULL)
	{
		if (p->id == x)
		{
			return p;
		}
		p=p->next;
	}
	if (p==NULL)
	{
	 searchCoursById(head_cour,x);
	}

}

void savePlayerCoursInFile(std_n* p,cour_n* pp)
{		
		cin>>pp->mark;
		string x= p->id;
		string a=".txt";
		string fileName;
		fileName=x+a;
		fstream  students;
		students.open(fileName.c_str(),ios::app);
		students << p->firstName <<","<<p->lastName <<","<<pp->courseName<<","<<pp->mark <<","<<pp->unit<<endl;
		students.close();
}

void readStdFromFile(std_n* head_std)
{
	int x;
	string total;
	string buffer;
	fstream students;
	students.open("students.txt",ios::in);
	students>>total;
	std_n*p =(std_n*) calloc(1, sizeof(std_n));
	p=head_std;
	char c[2]=",";

	while (p!=NULL)
	{
		for (int i=0;1;i++)
		{
			if (total[i]==c[0])
			{
				p->firstName=buffer;
				x=i;
				break;
			}
			buffer[(i-x)-1]=total[i];
		}

		for (int i=x+1;1;i++)
		{
			if (total[i]==c[0])
			{
				p->lastName=buffer;
				x=i;
				break;
			}
			buffer[i]=total[i];
		}
		for (int i=x+1;1;i++)
		{
			if (total[i]==c[0])
			{
				p->id=buffer;
				x=i;
				break;
			}
			buffer[(i-x)-1]=total[i];
		}
	}
}

void gpaProcess (std_n*head_std)
{
	std_n*p =(std_n*) calloc(1, sizeof(std_n));
	p=head_std;
	string x= p->id;		
	string a=".txt";
	string fileName;
	fstream students;
	students.open(fileName.c_str(),ios::in);
	

}
