#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
	string nameSurname;
	char m_f; 
public:
    Person(const string &x, char mf) : nameSurname(x), m_f(mf){cout << "Person Con" << endl;};
    ~Person(){cout << "Person Des" << endl;};
};

#endif





