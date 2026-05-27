#include "person.h"
#include "teacher.h"
#include "student.h"
#include "subject.h"
#include <iostream>
#include <string>
#include <cstring>

void Subject::SubPrint(ostream &x) const
{
    x << "Code: " << Subcode << " Description: " << Descript << " Semester: " << TeachSem << " Υπεύθυνος μαθήματος: " << endl;
    if (Head != nullptr) {
        Head->Print(x);
    } else {
        x << "None" << endl;
    }
}

int main()
{
cout << "\n======Δοκιμή Λίστας=======\n" << endl;
    
    list<Subject> empty_list;

    Teacher t1("Θοδωρής", 'M', "T01", "Action Dept", empty_list);
    Teacher t2("Μιχάλης", 'M', "T02", "History Dept", empty_list);
    Teacher t3("Thomas", 'M', "T03", "Programming Dept", empty_list);

    Subject v1("888", "Action", 3, &t1);
    Subject v2("373", "History", 4, &t2);
    Subject v3(v2); 

    v3.setSub("73653");
    v3.setDes("Programming");
    v3.setSem(3);
    v3.setHead(&t3); 

    list<Subject> l;
    list<Subject>::iterator il;
    
    l.push_back(v1);
    l.push_back(v2);

    Person Tommy("Thomas", 'M', l);

    cout << "\n--- First Print ---" << endl;
    Tommy.ListPrint(cout);

    Tommy.AddSubject(v3);

    cout << "\n--- Second Print (After adding v3) ---" << endl;
    Tommy.ListPrint(cout);

    cout << "\n======Δοκιμή Teacher Constructor=======\n" << endl;
    Teacher Theo("Theodore",'M',"175","Math",l);
	Theo.Print(cout);

	Teacher Nikos("Νίκος",'M',"5784","Math",l);
	Nikos.Print(cout);
	Nikos = Theo;
	Nikos.Print(cout);

	Theo.AddSubject(v3);

	Theo.Print(cout);

    cout << "\n=======Δοκιμή Teacher Setter/Getter=======\n" << endl;
    Teacher George("George",'M',"330","History",l);

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
		Student("23475","Βαγγέλης Χαμπέας",l),
		Student("31534","Cornelius Roger",'M',5,l),
		Student("18554","Τάκης Νουτρέας",'M',7,l),
		Student("87348","Jenny Smoky",'F',4,l),
		Student("67389","Ελένη Λίγκου",'F',2,l)
	};


	cout << "====Δοκιμή Parameter Constructor====\n" << endl;

	class1A[0].SetMF('M');

	class1A[1].AddSubject(v3);

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