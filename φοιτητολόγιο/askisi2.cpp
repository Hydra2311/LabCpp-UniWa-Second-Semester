#include <iostream>
#include <cstring>
#include <new>
#include <string>

using namespace std;

class Student
{
private:
	char *AM;
	string nameSurname;
	char m_f;
	unsigned int Semester;
public:
	Student (const char *,const string);
	Student (const char *,const string,char,unsigned int);
	Student (const Student &);
	~Student();

	void Print(ostream &) const;
	Student& operator =(const Student &);
	Student operator ++(int);
	Student& operator ++();
	Student& operator +=(unsigned int);
	Student& operator -=(unsigned int);
	Student& operator -();

	void SetAM(const char *);
	void SetName(const string);
	void SetMF(const char);
	void SetSem(const unsigned int);
	const char * GetAM() const;
	string GetName() const;
	char GetMF() const;
	unsigned int GetSem() const;
};

Student::Student (const char *am,const string name)
{
	int sizeam = strlen(am);

	if (sizeam)
	{
		AM = new char [sizeam + 1];
		strcpy(AM,am);
	}
	else
	{
		AM = nullptr;
	}

    nameSurname = name;
	Semester = 1;
}

Student::Student (const char *am,const string name,char mf,unsigned int sem)
{
    int sizeam = strlen(am);

    if (sizeam)
    {
        AM = new char [sizeam + 1];
        strcpy(AM,am);
    }
	else
	{
		AM = nullptr;
	}

	nameSurname = name;
	m_f = mf;
	Semester = sem;
}

Student::Student (const Student &stud)
{
	m_f = stud.m_f;
	Semester = stud.Semester;
	nameSurname = stud.nameSurname;

	int sizeam = strlen(stud.AM);

	AM = new char [sizeam + 1];
	memcpy(AM,stud.AM,sizeam+1);
}

Student::~Student()
{
	delete[] AM;
}

void Student::Print(ostream &x) const
{
	const char *namesur = nameSurname.c_str();
	int sizename = strlen(namesur);

	x << "AM: " << AM << " Name/Surname: " << nameSurname << " M/F: " << m_f << " Semester: " << Semester << "||| (Size: " << sizename << ")" << endl;
}

Student& Student::operator =(const Student &stud)
{
	if (this == &stud)
		return *this;

	delete[] AM;
	int sizeam = strlen(stud.AM);
	AM = new char[sizeam + 1];
	memcpy (AM, stud.AM, sizeam+1);

	nameSurname = stud.nameSurname;
	m_f = stud.m_f;
	Semester = stud.Semester;

	return *this;
}

Student Student::operator ++(int)
{
	Student tmp = *this;
	Semester++;
	return tmp;
}

Student& Student::operator ++()
{
	Semester++;
	return *this;
}

Student& Student::operator +=(unsigned int x)
{
	Semester += x;
	return *this;
}

Student& Student::operator -=(unsigned int x)
{
	int notsigned = Semester;
	if ((notsigned -= x) > 0)
		Semester -= x;
	else
		Semester = 1;

	return *this;
}

Student& Student::operator -()
{
	if (m_f == 'M')
		m_f = 'F';
	else if (m_f == 'F')
		m_f = 'M';

	return *this;
}

void Student::SetAM(const char *word)
{
	if (AM == word) return;

	delete[] AM;
	int size = strlen(word);
	AM = new char[size + 1];
	strcpy(AM,word);
}

void Student::SetName(const string name)
{
	 nameSurname = name;
}

void Student::SetMF(const char k)
{
	m_f = k;
}

void Student::SetSem(unsigned int sem)
{
	Semester = sem;
}

const char * Student::GetAM() const
{
	return AM;
}

string Student::GetName() const
{
	return nameSurname;
}

char Student::GetMF() const
{
	return m_f;
}

unsigned int Student::GetSem() const
{
	return Semester;
}

int main()
{
	int const n(5);
	Student *class1A;
	class1A = new Student[n]
	{
		Student("23475","Βαγγέλης Χαμπέας"),
		Student("31534","Cornelius Roger",'M',5),
		Student("18554","Τάκης Νουτρέας",'M',7),
		Student("87348","Jenny Smoky",'F',4),
		Student("67389","Ελένη Λίγκου",'F',2)
	};

	cout << "====Δοκιμή Parameter Constructor====\n" << endl;

	class1A[0].SetMF('M');

	for(int i=0;i<n;i++)
	{
		class1A[i].Print(cout);
	}

    cout << "\n====Δοκιμή Copy Constructor-Setter/Getter-Operators====\n" << endl;

	class1A[0]++;
	++class1A[1];
	class1A[2] += 3;
	class1A[3] -= 4;
	-class1A[4];

	Student testcopy = class1A[4];
	Student getset = class1A[4];

	getset.SetAM("22"); getset.SetName("Thomas Washignton");
	getset.SetMF('F'); getset.SetSem(8);

	const char *Am = getset.GetAM();
	string	NameSur = getset.GetName();
	char mf = getset.GetMF();
	unsigned int Seme = getset.GetSem();

    for(int i=0;i<n;i++)
    {
		class1A[i].Print(cout);
    }
	testcopy.Print(cout);
	getset.Print(cout);
	cout << "AM: " << Am << " Name/Surname: " << NameSur << " M/F: " << mf << " Semester: " << Seme << "\n";

	delete[] class1A;

	return 0;
}
