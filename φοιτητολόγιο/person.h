#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>
#include <list>
#include "subject.h"

using namespace std;

class Person
{
private:
	string nameSurname;
	char m_f; 
    list <Subject> Subjects;
public:
    Person(const string &x, char mf,const list <Subject> & List) : nameSurname(x), m_f(mf),Subjects(List){cout << "Person Con" << endl;};
    ~Person(){cout << "Person Des" << endl;};

    virtual void ListPrint(ostream &);

    virtual void AddSubject(const string &,const string &,const int,const string &);

    string GetName() const;
    char GetMF() const;
    const list <Subject> & GetList() const;

    void SetName(const string);
	void SetMF(const char);
};

void Person::ListPrint(ostream &x)
{
    list <Subject>::iterator il;
    for(il = Subjects.begin();il != Subjects.end();il++)
    {
        il -> SubPrint(x);
    }
}

void AddSubject(const string &,const string &,const int,const string &)
{
    
}

string Person::GetName() const
{
	return nameSurname;
}

char Person::GetMF() const
{
	return m_f;
}

const list <Subject> & Person::GetList() const
{
    return Subjects;
}

void Person::SetName(const string name)
{
	nameSurname = name;
}

void Person::SetMF(const char k)
{
	m_f = k;
}

#endif



