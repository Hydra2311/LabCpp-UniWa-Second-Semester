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
    Person(const string &x, char mf,const list <Subject> & List) : nameSurname(x), m_f(mf),Subjects(List){};
    ~Person(){};

    virtual void Print(ostream &) const;
    virtual void ListPrint(ostream &);

    void AddSubject(const Subject &);

    string GetName() const;
    char GetMF() const;
    list <Subject> & GetList();
    const list <Subject> & GetList() const;

    void SetName(const string);
	void SetMF(const char);
    void SetList(const list <Subject> &);

};

#endif