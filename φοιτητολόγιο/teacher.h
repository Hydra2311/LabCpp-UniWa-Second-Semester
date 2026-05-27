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

Teacher::Teacher (const string &name,char mf,const char *cd,const string &spec,const list <Subject> &l) : Person(name,mf,l)
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

Teacher::Teacher(const Teacher &teach) : Person(teach.GetName(),teach.GetMF(),teach.GetList())
{
    int size = strlen(teach.code);
    code = new char[size+1];
    memcpy(code,teach.code,size+1);

    special = teach.special;
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

void Teacher::ListPrint(ostream &x) const
{
    list <Subject>::const_iterator il;
    for(il = this->GetList().begin();il != this->GetList().end();il++)
    {
        il -> SubPrint(x);
    }
}

void Teacher::AddSub(const Subject &Sub)
{
    this->AddSubject(Sub);
}

Teacher & Teacher::operator =(Teacher &Teach)
{
    if (this == &Teach)
        return *this;

    delete[] code;
    int size = strlen(Teach.code);
    code = new char[size + 1];
    memcpy(code,Teach.code,size+1);

    special = Teach.special;

    this->SetList(Teach.GetList());
    this->SetName(Teach.GetName());
	this->SetMF(Teach.GetMF());

    return *this;
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
   
    this->ListPrint(cout);
}

#endif