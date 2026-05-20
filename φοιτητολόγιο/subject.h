#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Subject
{
private:
    char *Subcode;
    string Descript;
    int TeachSem;
    string Head;
public:
    Subject(const char *,const string &,const int,const string &);
    ~Subject();

    void setSub(const char *);
    void setDes(const string &);
    void setSem(const int);
    void setHead(const string &);

    char * getSub() const;
    string getDes() const;
    int getSem() const;
    string getHead() const;
};

Subject::Subject(const char *sub,const string &des,const int sem,const string &head)
{
    int size = strlen(sub);
    Subcode = new char[size+1];
    strcpy(Subcode,sub);

    Descript = des;
    TeachSem = sem;
    Head = head;
}

Subject::~Subject()
{
    delete[] Subcode;
}

#endif