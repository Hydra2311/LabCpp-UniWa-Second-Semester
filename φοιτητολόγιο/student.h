#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <cstring>
#include "person.h"

using namespace std;

class Student : public Person
{
private:
	char *AM;
	unsigned int Semester;
public:
	Student (const char *,const string &,list <Subject>);
	Student (const char *,const string &,char,unsigned int,list <Subject>);
	Student (const Student &);
	~Student();

	void Print(ostream &) const;
	void ListPrint(ostream &) const;
	Student& operator =(const Student &);
	Student operator ++(int);
	Student& operator ++();
	Student& operator +=(unsigned int);
	Student& operator -=(unsigned int);
	Student& operator -();

	void SetAM(const char *);
	void SetSem(const unsigned int);

	const char * GetAM() const;
	unsigned int GetSem() const;
};

Student::Student (const char *am,const string &name,list <Subject> l) : Person(name,'-',l)
{
	int sizeam = strlen(am);

	if (sizeam)
	{
		AM = new char [sizeam + 1];
		strcpy(AM,am);
	}
	else
	{
		AM = nullptr;
	}

	Semester = 1;

    cout << "Student Half Con" << endl;
}

Student::Student (const char *am,const string &name,char mf,unsigned int sem,list <Subject> l) : Person(name,mf,l)
{
    int sizeam = strlen(am);

    if (sizeam)
    {
        AM = new char [sizeam + 1];
        strcpy(AM,am);
    }
	else
	{
		AM = nullptr;
	}

	Semester = sem;

    cout << "Student Full Con" << endl;
}

Student::Student (const Student &stud) : Person(stud.GetName(),stud.GetMF(),stud.GetList())
{
	Semester = stud.Semester;

	int sizeam = strlen(stud.AM);

	AM = new char [sizeam + 1];
	memcpy(AM,stud.AM,sizeam+1);

    cout << "Student Copy Con" << endl;
}

Student::~Student()
{
	delete[] AM;

    cout << "Student Des" << endl;
}

void Student::Print(ostream &x) const
{
	const char *namesur = this->GetName().c_str();
	int sizename = strlen(namesur);

	x << "AM: " << AM << " Name/Surname: " << this->GetName() << " M/F: " << this->GetMF() << " Semester: " << Semester << "||| (Size: " << sizename << ")" << endl;
	this->ListPrint(cout);
}

void Student::ListPrint(ostream &x) const
{
    list <Subject>::const_iterator il;
    for(il = this->GetList().begin();il != this->GetList().end();il++)
    {
        il -> SubPrint(x);
    }
}

Student& Student::operator =(const Student &stud)
{
	if (this == &stud)
		return *this;

	delete[] AM;
	int sizeam = strlen(stud.AM);
	AM = new char[sizeam + 1];
	memcpy (AM, stud.AM, sizeam+1);

	this->SetName(stud.GetName());
	this->SetMF(stud.GetMF());
	Semester = stud.Semester;

	return *this;
}

Student Student::operator ++(int)
{
	Student tmp = *this;
	Semester++;
	return tmp;
}

Student& Student::operator ++()
{
	Semester++;
	return *this;
}

Student& Student::operator +=(unsigned int x)
{
	Semester += x;
	return *this;
}

Student& Student::operator -=(unsigned int x)
{
	int notsigned = Semester;
	if ((notsigned -= x) > 0)
		Semester -= x;
	else
		Semester = 1;

	return *this;
}

Student& Student::operator -()
{
    char mf = this->GetMF();
	if (mf == 'M')
		mf = 'F';
	else if (mf == 'F')
		mf = 'M';

    this->SetMF(mf);

	return *this;
}

void Student::SetAM(const char *word)
{
	if (strcmp(AM,word) == 0) return;

	delete[] AM;
	int size = strlen(word);
	AM = new char[size + 1];
	strcpy(AM,word);
}

void Student::SetSem(unsigned int sem)
{
	Semester = sem;
}

const char * Student::GetAM() const
{
	return AM;
}

unsigned int Student::GetSem() const
{
	return Semester;
}

#endif