#ifndef TEACHER_H_
#define TEACHER_H_

#include "person.h"
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
    Teacher (const string &,char ,const char *,const string &);
    ~Teacher();
};

Teacher::Teacher (const string &name,char mf,const char *cd,const string &spec) : Person(name,mf)
{
    int size = strlen(cd);
    if (size)
    {
        code = new char[size+1];
        strcpy(code,cd);
    }
    else
    {
        code = nullptr;
    }

    special = spec;
    cout << "Teacher Con" << endl;
}

Teacher::~Teacher()
{
    delete[] code;
    cout << "Teacher Des" << endl;
}

#endif