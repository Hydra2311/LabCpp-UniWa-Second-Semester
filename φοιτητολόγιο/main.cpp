#include "person.h"
#include "teacher.h"
#include "student.h"
#include <iostream>
#include <string>
#include <cstring>

int main()
{
    cout << "\n======Δοκιμή Teacher Constructor=======\n" << endl;
    Teacher Theo("Theodore",'M',"175","Math");
    Theo.Print(cout);

    cout << "\n=======Δοκιμή Teacher Setter/Getter=======\n" << endl;
    Teacher George("George",'M',"330","History");

    George.SetCode("22"); George.SetName("Georgi");
	George.SetMF('F'); George.SetSpecial("Tourism");

    George.Print(cout);

	const char *codex = George.GetCode();
	string	NameSure = George.GetName();
	char mf_ = George.GetMF();
	string specialty = George.GetSpecial();

    cout << "Code: " << codex << " Name/Surname: " << NameSure << " M/F: " << mf_ << " Specialty: " << specialty << endl;

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