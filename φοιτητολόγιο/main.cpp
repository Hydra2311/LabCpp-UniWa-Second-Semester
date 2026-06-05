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
    Teacher Teacher1("Θοδωρής", 'M', "T01", "Action Dept", empty_list);
    Teacher Teacher2("Μιχάλης", 'M', "T02", "History Dept", empty_list);
    Teacher Teacher3("Thomas", 'M', "T03", "Programming Dept", empty_list);

    Subject sub1("848", "Action", 3, &Teacher1), sub2("373", "History", 4, &Teacher2), sub3(sub2); 
    sub3.setSub("73653"); sub3.setDes("Programming"); sub3.setSem(3); sub3.setHead(&Teacher3); 

    list<Subject> l = {sub1, sub2}; 
    Person Tommy("Thomas", 'M', l);

    cout << "\n========================================" << endl;
    cout << "2. Πρώτη Εκτύπωση Subject" << endl;
    cout << "========================================" << endl;
    Tommy.ListPrint(cout);
    
    Tommy.AddSubject(sub3);
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
    class1A[1].AddSubject(sub3);
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
    
    Record Φοιτητολογιο;
    list<Subject> emptyList;

    Teacher* t1 = new Teacher("Κύριος Γιώργος", 'M', "T01", "Μαθηματικά", emptyList);
    Teacher* t2 = new Teacher("Dr. Stein", 'M', "T02", "Γλώσσα", emptyList);
    Teacher* t3 = new Teacher("Κυρία Αναστασία", 'F', "T03", "Προγραμματισμός", emptyList);
    Φοιτητολογιο.AddPerson(t1);
    Φοιτητολογιο.AddPerson(t2);
    Φοιτητολογιο.AddPerson(t3);

    Subject math("101", "Algebra", 1, t1);
    Subject physics("102", "Physics", 2, t1);
    Subject python("103", "Python", 3, t2);
    Φοιτητολογιο.AddSubject(math);
    Φοιτητολογιο.AddSubject(physics);
    Φοιτητολογιο.AddSubject(python);

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

    Φοιτητολογιο.AddPerson(s1);
    Φοιτητολογιο.AddPerson(s2);

    cout << "--- Τωρινά Members ---" << endl;
    Φοιτητολογιο.PrintMemb(cout);


    cout << "\n========================================" << endl;
    cout << "2. Αποθήκευση σε CSV" << endl;
    cout << "========================================" << endl;
    try {
        Φοιτητολογιο.StudentOCSV();
        Φοιτητολογιο.TeacherOCSV();
        cout << "Δημιουργήθηκαν τα student.csv και teacher.csv" << endl;
    } 
    catch (int x) {
        cout << "Αδυναμία αποθήκευσης" << endl;
    }


    cout << "\n========================================" << endl;
    cout << "3. Φόρτωση από CSV" << endl;
    cout << "========================================" << endl;
    
    Record φορτωμενοφοιτ;
    
    φορτωμενοφοιτ.AddSubject(math);
    φορτωμενοφοιτ.AddSubject(physics);
    φορτωμενοφοιτ.AddSubject(python);

    try {
        φορτωμενοφοιτ.StudentICSV();
        φορτωμενοφοιτ.TeacherICSV();
        cout << "Τα αρχεία φορτώθηκαν\n--- Τωρινά Members ---\n" << endl;
        φορτωμενοφοιτ.PrintMemb(cout);
    }
    catch (int x) {
        cout << "Αδυναμία φόρτωσης" << endl;
    }

    cout << "\n========================================" << endl;
    cout << "4. Αλλαγή και Διαγραφή" << endl;
    cout << "========================================" << endl;

    cout << "Thomas σε Tommy" << endl;
    φορτωμενοφοιτ.ChangeName("12345", "Tommy");
    
    cout << "Αλλαγή Subject 101 Description" << endl;
    φορτωμενοφοιτ.ChangeDesc("101", "Advanced Algebra");

    cout << "--- Members μετά τις αλλαγές ---" << endl;
    φορτωμενοφοιτ.PrintMemb(cout);

    cout << "\nΔιαγραφή κύριου Γιώργου" << endl;
    φορτωμενοφοιτ.DeleteMember("T01");
    
    cout << "--- Members μετά τη διαγραφή ---" << endl;
    φορτωμενοφοιτ.PrintMemb(cout);

    cout << "\n========================================" << endl;
    cout << "5. Δοκιμή Emails" << endl;
    cout << "========================================" << endl;
    
    φορτωμενοφοιτ.EmailStudent(cout, "Ακύρωση του μαθήματος στις 17:00.");
    φορτωμενοφοιτ.EmailTeacher(cout, "Συνάντηση καθηγητών στις 19:00");

    cout << "\n========================================" << endl;
    cout << "Λειτουργίες Record ολοκληρώθηκαν" << endl;
    cout << "========================================" << endl;

    return 0;
}