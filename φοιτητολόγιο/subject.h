#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Subject
{
private:
    string Subcode;
    string Descript;
    int TeachSem;
    string Head;
public:
    Subject(const string &,const string &,const int,const string &);
    ~Subject();

    void SubPrint(ostream &) const;

    void setSub(const string &);
    void setDes(const string &);
    void setSem(const int);
    void setHead(const string &);

    string getSub() const;
    string getDes() const;
    int getSem() const;
    string getHead() const;
};

Subject::Subject(const string &sub,const string &des,const int sem,const string &head)
{
    Subcode = sub;
    Descript = des;
    TeachSem = sem;
    Head = head;
}

Subject::~Subject()
{

}

void Subject::SubPrint(ostream &x) const
{
    x << "Code: " << Subcode << " Description: " << Descript << " Semester: " << TeachSem << " Υπεύθυνος μαθήματος: " << Head << endl;
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

void Subject::setHead(const string &head)
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

string Subject::getHead() const
{
    return Head;
}

#endif