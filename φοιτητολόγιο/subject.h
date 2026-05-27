#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Teacher;

class Subject
{
private:
    string Subcode;
    string Descript;
    int TeachSem;
    Teacher* Head;
public:
    Subject(const string &,const string &,const int,Teacher *);
    Subject(const Subject &);
    ~Subject();

    void SubPrint(ostream &) const;

    void setSub(const string &);
    void setDes(const string &);
    void setSem(const int);
    void setHead(Teacher *);

    string getSub() const;
    string getDes() const;
    int getSem() const;
    Teacher * getHead() const;
};

Subject::Subject(const string &sub,const string &des,const int sem,Teacher *head)
{
    Subcode = sub;
    Descript = des;
    TeachSem = sem;
    Head = head;
}

Subject::Subject(const Subject &Sub)
{
    Subcode = Sub.Subcode;
    Descript = Sub.Descript;
    TeachSem = Sub.TeachSem;
    Head = Sub.Head;
}

Subject::~Subject()
{

}

void Subject::setSub(const string &sub)
{
    Subcode = sub;
}

void Subject::setDes(const string &des)
{
    Descript = des;
}

void Subject::setSem(const int sem)
{
    TeachSem = sem;
}

void Subject::setHead(Teacher *head)
{
    Head = head;
}

string Subject::getSub() const
{
    return Subcode;
}

string Subject::getDes() const
{
    return Descript;
}

int Subject::getSem() const
{
    return TeachSem;
}

Teacher * Subject::getHead() const
{
    return Head;
}

#endif