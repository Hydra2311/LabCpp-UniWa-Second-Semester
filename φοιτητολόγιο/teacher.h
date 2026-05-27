#ifndef TEACHER_H_
#define TEACHER_H_

#include "person.h"
#include "subject.h"
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Teacher : public Person
{
private:
    char *code;
    string special;
public:
    Teacher (const string &,char ,const char *,const string &,const list <Subject> &);
    Teacher (const Teacher &);
    ~Teacher();

    void SetCode(const char *);
    void SetSpecial(const string &);

    void ListPrint(ostream &) const;
    void AddSub(const Subject &);

    Teacher & operator = (Teacher &);

    char * GetCode() const;
    string GetSpecial() const;

    void Print(ostream &) const;
};

#endif