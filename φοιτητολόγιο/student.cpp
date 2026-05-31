#include "subject.h"
#include "student.h"

Student::Student (const char *am,const string &name,const list <Subject> &l) : Person(name,'-',l)
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

	Semester = 1;
}

Student::Student (const char *am,const string &name,char mf,unsigned int sem,const list <Subject> &l) : Person(name,mf,l)
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

	Semester = sem;
}

Student::Student (const Student &stud) : Person(stud.GetName(),stud.GetMF(),stud.GetList())
{
	Semester = stud.Semester;

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
	const char *namesur = this->GetName().c_str();
	int sizename = strlen(namesur);

	x << "AM: " << AM << " Name/Surname: " << this->GetName() << " M/F: " << this->GetMF() << " Semester: " << Semester << "||| (Size: " << sizename << ")" << endl;
	this->ListPrint(cout);
}

void Student::ListPrint(ostream &x) const
{
    list <Subject>::const_iterator il;
    for(il = this->GetList().begin();il != this->GetList().end();il++)
    {
        il -> SubPrint(x);
    }
}

void Student::AddSub(const Subject &Sub)
{
    this->AddSubject(Sub);
}

Student& Student::operator =(const Student &stud)
{
	if (this == &stud)
		return *this;

	delete[] AM;
	int sizeam = strlen(stud.AM);
	AM = new char[sizeam + 1];
	memcpy (AM, stud.AM, sizeam+1);

	this->SetName(stud.GetName());
	this->SetMF(stud.GetMF());
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
    char mf = this->GetMF();
	if (mf == 'M')
		mf = 'F';
	else if (mf == 'F')
		mf = 'M';

    this->SetMF(mf);

	return *this;
}



void Student::SetAM(const char *word)
{
	if (strcmp(AM,word) == 0) return;

	delete[] AM;
	int size = strlen(word);
	AM = new char[size + 1];
	strcpy(AM,word);
}

void Student::SetSem(unsigned int sem)
{
	Semester = sem;
}

const char * Student::GetAM() const
{
	return AM;
}

unsigned int Student::GetSem() const
{
	return Semester;
}
