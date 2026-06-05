#include "person.h"
#include "teacher.h"
#include "student.h"
#include "subject.h"
#include "record.h"
#include <iostream>
#include <string>
#include <cstring>

int main()
{
    cout << "\n========================================" << endl;
    cout << "Δοκιμή Subject/Person/Student/Teacher κλάσεων\n\n1. Αρχικοποίηση" << endl;
    cout << "========================================" << endl;
    
    list<Subject> empty_list;
    Teacher k1("Θοδωρής", 'M', "T01", "Action Dept", empty_list);
    Teacher k2("Μιχάλης", 'M', "T02", "History Dept", empty_list);
    Teacher k3("Thomas", 'M', "T03", "Programming Dept", empty_list);

    Subject v1("848", "Action", 3, &k1), v2("373", "History", 4, &k2), v3(v2); 
    v3.setSub("73653"); v3.setDes("Programming"); v3.setSem(3); v3.setHead(&k3); 

    list<Subject> l = {v1, v2}; 
    Person Tommy("Thomas", 'M', l);

    cout << "\n========================================" << endl;
    cout << "2. Πρώτη Εκτύπωση Subject" << endl;
    cout << "========================================" << endl;
    Tommy.ListPrint(cout);
    
    Tommy.AddSubject(v3);
    cout << "\n========================================" << endl;
    cout << "3. Πρόσθεση Subject" << endl;
    cout << "========================================" << endl;
    Tommy.ListPrint(cout);

    cout << "\n========================================" << endl;
    cout << "4. Teacher Constructor/Setters/Getters" << endl;
    cout << "========================================" << endl;

    Teacher George("George", 'M', "330", "History", l);
    George.SetCode("22"); George.SetName("Georgi"); George.SetMF('F'); George.SetSpecial("Tourism");
    George.Print(cout);

    cout << "Code: " << George.GetCode() << " Name/Surname: " << George.GetName() 
         << " M/F: " << George.GetMF() << " Specialty: " << George.GetSpecial() << "\n";

    cout << "\n========================================" << endl;
    cout << "5. Student Constructor/Getters/Setters" << endl;
    cout << "========================================" << endl;

    int const n(5);
    Student* class1A = new Student[n] {
        Student("23475", "Βαγγέλης Χαμπέας", l),
        Student("31534", "Cornelius Roger", 'M', 5, l),
        Student("18554", "Τάκης Νουτρέας", 'M', 7, l),
        Student("87348", "Jenny Smoky", 'F', 4, l),
        Student("67389", "Ελένη Λίγκου", 'F', 2, l)
    };

    class1A[0].SetMF('M'); 
    class1A[1].AddSubject(v3);
    for(int i = 0; i < n; i++) {class1A[i].Print(cout); cout << endl;}

    cout << endl;

    class1A[0]++; ++class1A[1]; class1A[2] += 3; class1A[3] -= 4; -class1A[4];

    Student testcopy = class1A[4], getset = class1A[4];
    getset.SetAM("22"); getset.SetName("Thomas Washignton"); getset.SetMF('F'); getset.SetSem(8);

    for(int i = 0; i < n; i++) {class1A[i].Print(cout); cout << endl;}

    cout << endl;

    testcopy.Print(cout); 

    cout << endl;

    getset.Print(cout);
    
    cout << "AM: " << getset.GetAM() << " Name/Surname: " << getset.GetName() 
         << " M/F: " << getset.GetMF() << " Semester: " << getset.GetSem() << "\n";

    delete[] class1A;

    cout << "\n========================================" << endl;
    cout << "Λειτουργίες Κλάσεων Ολοκληρώθηκαν" << endl;
    cout << "========================================" << endl;

	cout << "========================================" << endl;
    cout << "Λειτουργίες Record\n\n1. Αρχικοποίηση" << endl;
    cout << "========================================" << endl;
    
    Record myRecord;
    list<Subject> emptyList;

    Teacher* t1 = new Teacher("Κύριος Γιώργος", 'M', "T01", "Μαθηματικά", emptyList);
    Teacher* t2 = new Teacher("Dr. Stein", 'M', "T02", "Γλώσσα", emptyList);
    Teacher* t3 = new Teacher("Κυρία Αναστασία", 'F', "T03", "Προγραμματισμός", emptyList);
    myRecord.AddPerson(t1);
    myRecord.AddPerson(t2);
    myRecord.AddPerson(t3);

    Subject math("101", "Algebra", 1, t1);
    Subject physics("102", "Physics", 2, t1);
    Subject python("103", "Python", 3, t2);
    myRecord.AddSubject(math);
    myRecord.AddSubject(physics);
    myRecord.AddSubject(python);

    Student* s1 = new Student("12345", "Thomas", 'M', 3, emptyList);
    Student* s2 = new Student("6789", "Νικολέτα", 'F', 3, emptyList);

    s1->AddSubject(math);
    s1->AddSubject(physics);
    s2->AddSubject(python);

    t1->AddSubject(math);
    t1->AddSubject(python);
    t2->AddSubject(math);
    t2->AddSubject(physics);
    t3->AddSubject(python);

    myRecord.AddPerson(s1);
    myRecord.AddPerson(s2);

    cout << "--- Τωρινά Members ---" << endl;
    myRecord.PrintMemb(cout);


    cout << "\n========================================" << endl;
    cout << "2. Αποθήκευση σε CSV" << endl;
    cout << "========================================" << endl;
    try {
        myRecord.StudentOCSV();
        myRecord.TeacherOCSV();
        cout << "Δημιουργήθηκαν τα student.csv και teacher.csv" << endl;
    } 
    catch (int x) {
        cout << "Αδυναμία αποθήκευσης" << endl;
    }


    cout << "\n========================================" << endl;
    cout << "3. Φόρτωση από CSV" << endl;
    cout << "========================================" << endl;
    
    Record loadedRecord;
    
    loadedRecord.AddSubject(math);
    loadedRecord.AddSubject(physics);
    loadedRecord.AddSubject(python);

    try {
        loadedRecord.StudentICSV();
        loadedRecord.TeacherICSV();
        cout << "Τα αρχεία φορτώθηκαν\n--- Τωρινά Members ---\n" << endl;
        loadedRecord.PrintMemb(cout);
    }
    catch (int x) {
        cout << "Αδυναμία φόρτωσης" << endl;
    }

    cout << "\n========================================" << endl;
    cout << "4. Αλλαγή και Διαγραφή" << endl;
    cout << "========================================" << endl;

    cout << "Thomas σε Tommy" << endl;
    loadedRecord.ChangeName("12345", "Tommy");
    
    cout << "Αλλαγή Subject 101 Description" << endl;
    loadedRecord.ChangeDesc("101", "Advanced Algebra");

    cout << "--- Members μετά τις αλλαγές ---" << endl;
    loadedRecord.PrintMemb(cout);

    cout << "\nΔιαγραφή κύριου Γιώργου" << endl;
    loadedRecord.DeleteMember("T01");
    
    cout << "--- Members μετά τη διαγραφή ---" << endl;
    loadedRecord.PrintMemb(cout);

    cout << "\n========================================" << endl;
    cout << "5. Δοκιμή Emails" << endl;
    cout << "========================================" << endl;
    
    loadedRecord.EmailStudent(cout, "Ακύρωση του μαθήματος στις 17:00.");
    loadedRecord.EmailTeacher(cout, "Συνάντηση καθηγητών στις 19:00");

    cout << "\n========================================" << endl;
    cout << "Λειτουργίες Record ολοκληρώθηκαν" << endl;
    cout << "========================================" << endl;

    return 0;
}