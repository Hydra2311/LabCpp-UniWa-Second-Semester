#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <string>
#include <cstring>
#include "person.h"
#include "subject.h"

using namespace std;

class Student : public Person
{
private:
	char *AM;
	unsigned int Semester;
public:
	Student (const char *,const string &,const list <Subject> &);
	Student (const char *,const string &,char,unsigned int,const list <Subject> &);
	Student (const Student &);
	~Student();

	void Print(ostream &) const;
	void ListPrint(ostream &) const;
    void AddSub(const Subject &);

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

#endif