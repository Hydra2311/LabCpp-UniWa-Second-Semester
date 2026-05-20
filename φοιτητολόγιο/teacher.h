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

    void SetCode(const char *);
    void SetSpecial(const string &);

    char * GetCode() const;
    string GetSpecial() const;

    void Print(ostream &) const;
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

void Teacher::SetCode (const char *cde)
{
    if (strcmp(code,cde) == 0) return;

    delete[] code;
    int sizec = strlen(cde);
    code = new char[sizec + 1];
    strcpy(code,cde);
}

void Teacher::SetSpecial(const string &spe)
{
    special = spe;
}

char * Teacher::GetCode() const
{
    return code;
}

string Teacher::GetSpecial() const
{
    return special;
}

void Teacher::Print(ostream &x) const
{
	x << "Code: " << code << " Name/Surname: " << this->GetName() << " M/F: " << this->GetMF() << " Specialty: " << special << endl;
}

#endif