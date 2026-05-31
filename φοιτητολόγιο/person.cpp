#include "subject.h"
#include "person.h"

void Person::ListPrint(ostream &x)
{
    list <Subject>::iterator il;
    for(il = Subjects.begin();il != Subjects.end();il++)
    {
        il -> SubPrint(x);
    }
}

void Person::Print(ostream &x) const
{
    x << "Useless" << endl;
}

void Person::AddSubject(const Subject &Sub)
{
    Subjects.push_back(Sub);
}

string Person::GetName() const
{
	return nameSurname;
}

char Person::GetMF() const
{
	return m_f;
}

const list <Subject> & Person::GetList() const
{
    return Subjects;
}

void Person::SetName(const string name)
{
	nameSurname = name;
}

void Person::SetMF(const char k)
{
	m_f = k;
}

void Person::SetList(const list <Subject> &lista)
{
    this->Subjects = lista;
}