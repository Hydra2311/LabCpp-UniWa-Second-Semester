#ifndef RECORD_H_
#define RECORD_H_

#include "person.h"
#include "subject.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

class Record 
{
private:
    vector<Person *> Members;
    list<Subject> AllSub;
public:
    Record(const vector<Person *> &People,const list<Subject> &Subjects) : Members(People),AllSub(Subjects){};
    Record(){};
    ~Record(){};

    void AddPerson(Person *);
    void AddSubject(const Subject &);

    void PrintMemb(ostream &);
    void PrintSub(ostream &);
    void CPrintSt();
    void CPrintT();
    void CPrintSub();

    void ChangeName(const char *,const string &); 
    void ChangeDesc(const string &,const string &);

    void DeleteMember(const char *);
    void DeleteSubject(const string &);

    Person * SearchMember(const char *);
    Subject * SearchSubject(const string &);

    void EmailStudent(ostream &,const string &);
    void EmailTeacher(ostream &,const string &);
    void CEmailStudent(const string &);
    void CEmailTeacher(const string &);

    void StudentOCSV();
    void TeacherOCSV();

    void StudentICSV();
    void TeacherICSV();

    vector <Person *> &GetMembers();
    list <Subject> &GetSubjects();
};

#endif
