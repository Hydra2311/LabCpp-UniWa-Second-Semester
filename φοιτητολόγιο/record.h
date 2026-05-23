#ifndef RECORD_H_
#define RECORD_H_

#include "person.h"
#include "subject.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Record 
{
private:
    vector<Person *> Members;
    list<Subject> AllSub;
public:
    Record(const vector<Person *> &People,const list<Subject> &Subjects) : Members(People),AllSub(Subjects){};
    ~Record();

};

#endif