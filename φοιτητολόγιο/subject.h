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

#endif