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

    string GetName() const;
    char GetMF() const;

    void SetName(const string);
	void SetMF(const char);
};

string Person::GetName() const
{
	return nameSurname;
}

char Person::GetMF() const
{
	return m_f;
}

void Person::SetName(const string name)
{
	nameSurname = name;
}

void Person::SetMF(const char k)
{
	m_f = k;
}

#endif





