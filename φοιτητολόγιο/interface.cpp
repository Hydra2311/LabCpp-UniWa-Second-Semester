#include <ncurses.h>
#include <string>
#include <locale.h>
#include "person.h"
#include "record.h"
#include "student.h"
#include "subject.h"
#include "teacher.h"

using namespace std;

enum Choices {AddSt,AddTeach,AddSub,PrintSt,PrintTeach,PrintSub,
              SaveSt,SaveTeach,LoadSt,LoadTeach,AddSubSt,AddSubTeach,
              EmailSt,EmailTeach,ChangeName,ChangeDesc,DeleteM,DeleteSub};

int main()
{
    setlocale(LC_ALL, "");

    vector <Person *> empty_vector;
    list <Subject> empty_list;

    Record record;

    initscr();
    cbreak();
    noecho();   

    WINDOW *menuwin = newwin(LINES,COLS,0,0);  
    refresh();

    box(menuwin,0,0);

    attron(A_BOLD);
    mvwprintw(menuwin,1,COLS/2-5,"ΦΟΙΤΗΤΟΛΌΓΙΟ");
    attroff(A_BOLD);
    string exitq = "Πατήστε 'q' για έξοδο";
    mvwprintw(menuwin,LINES-2,COLS-25,"%s",exitq.c_str());

    wrefresh(menuwin);

    keypad(menuwin,TRUE);

    int numbofch = 18;
    string *choices = new string[numbofch];
    choices[0] = "Πρόσθεσε Μαθητή";
    choices[1] = "Πρόσθεσε Καθηγητή";
    choices[2] = "Πρόσθεσε Μάθημα (Απαιτεί Καθηγητή)";
    choices[3] = "Εκτύπωσε Μαθητές";
    choices[4] = "Εκτύπωση Καθηγητών";
    choices[5] = "Εκτύπωση Μαθημάτων";
    choices[6] = "Αποθήκευση Μαθητών";
    choices[7] = "Αποθήκευση Καθηγητών";
    choices[8] = "Φόρτωση Μαθητών";
    choices[9] = "Φόρτωση Καθηγητών";
    choices[10] = "Προσθήκη Μαθήματος σε Μαθητή";
    choices[11] = "Προσθήκη Μαθήματος σε Καθηγητή";
    choices[12] = "Αποστολή Email σε Μαθητές";
    choices[13] = "Αποστολή Email σε Καθηγητές";
    choices[14] = "Αλλαγή Ονόματος Καθηγητή/Μαθητή";
    choices[15] = "Αλλαγή Περιγραφής Μαθήματος";
    choices[16] = "Διαγραφή Μέλους";
    choices[17] = "Διαγραφή Μαθήματος";

    int choice, highlighted = 0;

    while(1)
    {
        for(int i = 0;i < numbofch;i++)
        {
            if (i == highlighted)
            {
                wattron(menuwin,A_REVERSE);
            }
            int startingpoint=3;
            mvwprintw(menuwin,startingpoint+i,1,"%s",choices[i].c_str());
            wattroff(menuwin,A_REVERSE);
        }
        
        choice = wgetch(menuwin);

        switch (choice)
        {
            case KEY_UP:
            {
                highlighted--;
                if(highlighted == -1)
                {
                    highlighted = 0;
                }
                break;
            }
            case KEY_DOWN:
            {
                highlighted++;
                if(highlighted == numbofch)
                {
                    highlighted = numbofch-1;
                }
                break;
            }
            default:
            {
                break;
            }
        }
        if (choice == 10)
        {
            switch (highlighted)
            {
                case AddSt:
                {
                    Student *Added = new Student(".",".",'.',1,empty_list);
                    WINDOW *addS = newwin(LINES,COLS,0,0);
                    box(addS,0,0);
                    mvwprintw(addS,1,COLS/2-5,"ΠΡΟΣΘΕΣΕ ΜΑΘΗΤΗ");
                    mvwprintw(addS,4,1,"Όνομα Επίθετο: ");
                    mvwprintw(addS,5,1,"Φύλο: ");
                    mvwprintw(addS,6,1,"Α.Μ: ");
                    mvwprintw(addS,7,1,"Εξάμηνο: ");
                    wrefresh(addS);      
                    
                    echo();
                    char input[100];

                    mvwgetnstr(addS, 4, 20, input, 99);
                    string Name(input);
                    Added->SetName(Name);

                    mvwgetnstr(addS, 5, 15, input, 99);
                    Added->SetMF(input[0]);

                    mvwgetnstr(addS, 6, 15, input, 99);
                    Added->SetAM(input);

                    mvwgetnstr(addS, 7, 15, input, 99);
                    Added->SetSem(atoi(input));

                    record.AddPerson(Added);

                    noecho();
                    delwin(addS);
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case AddTeach:
                {
                    Teacher *Added = new Teacher(".",'.',".",".",empty_list);
                    WINDOW *addT = newwin(LINES,COLS,0,0);
                    box(addT,0,0);
                    mvwprintw(addT,1,COLS/2-5,"ΠΡΟΣΘΕΣΕ ΚΑΘΗΓΗΤΉ");
                    mvwprintw(addT,4,1,"Όνομα Επίθετο: ");
                    mvwprintw(addT,5,1,"Φύλο: ");
                    mvwprintw(addT,6,1,"Κωδικός: ");
                    mvwprintw(addT,7,1,"Ειδικότητα: ");
                    wrefresh(addT);      
                    
                    echo();
                    char input[100];

                    mvwgetnstr(addT, 4, 20, input, 99);
                    string Name(input);
                    Added->SetName(Name);

                    mvwgetnstr(addT, 5, 15, input, 99);
                    Added->SetMF(input[0]);

                    mvwgetnstr(addT, 6, 15, input, 99);
                    Added->SetCode(input);

                    mvwgetnstr(addT, 7, 15, input, 99);
                    string Specialty(input);
                    Added->SetSpecial(Specialty);

                    record.AddPerson(Added);

                    noecho();
                    delwin(addT);
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case AddSub:
                {
                    bool teacherfound = false;
                    vector <Person *> &search = record.GetMembers();
                    for (int i = 0;i < search.size(); i++)
                    {
                        Teacher *Maybe = dynamic_cast<Teacher *>(search[i]);
                        if (Maybe)
                        {
                            teacherfound = true;
                        }
                    }
                    if (!teacherfound)
                    {
                        break;
                    }

                    Subject *Added = new Subject;
                    WINDOW *AddSub = newwin(LINES,COLS,0,0);
                    box(AddSub,0,0);
                    mvwprintw(AddSub,1,COLS/2-5,"ΠΡΟΣΘΗΚΗ ΜΑΘΗΜΑΤΩΝ");  
                    mvwprintw(AddSub,4,1,"Κωδικός: ");
                    mvwprintw(AddSub,5,1,"Περιγραφή: ");
                    mvwprintw(AddSub,6,1,"Εξάμηνο: ");
                    mvwprintw(AddSub,7,1,"Κωδικός Υπεύθυνου: ");
                    wrefresh(AddSub);      
                    
                    echo();
                    char input[100];

                    mvwgetnstr(AddSub, 4, 20, input, 99);
                    string Code(input);
                    Added->setSub(Code);

                    mvwgetnstr(AddSub, 5, 15, input, 99);
                    string Descr(input);
                    Added->setDes(Descr);

                    mvwgetnstr(AddSub, 6, 15, input, 99);
                    Added->setSem(atoi(input));

                    Teacher *Maybe = nullptr;

                    do
                    {
                        mvwprintw(AddSub, 7, 20, "                    ");
                        mvwgetnstr(AddSub, 7, 20, input, 99);
                        vector <Person *> search2 = record.GetMembers();
                        for (int i = 0;i < search2.size(); i++)
                        {
                            Maybe = dynamic_cast<Teacher *>(search2[i]);
                            if (Maybe)
                            {
                                if (!strcmp(input,Maybe->GetCode()))
                                {
                                    Added->setHead(Maybe);
                                    break;
                                }
                                else
                                {
                                    Maybe = nullptr;
                                }
                            }
                        }
                    } while (Maybe == nullptr);

                    record.AddSubject(*Added);

                    noecho();
                    delwin(AddSub);
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;                   
                }
                case PrintSt:
                {
                    WINDOW *printS = newwin(LINES,COLS,0,0);
                    box(printS,0,0);
                    mvwprintw(printS,1,COLS/2-5,"ΕΚΤΎΠΩΣΗ ΜΑΘΗΤΏΝ"); 

                    vector <Person *> &search = record.GetMembers();

                    int currentLine = 3;

                    for (int i = 0;i < search.size(); i++)
                    {
                        Student *Maybe = dynamic_cast<Student *>(search[i]);
                        if (Maybe)
                        {
                            int distance = 0;
                            mvwprintw(printS,currentLine,1,"Όνομα/Επίθετο: %s, Φύλο: %c, Α.Μ: %s, Εξάμηνο: %d", Maybe->GetName().c_str(), Maybe->GetMF(), Maybe->GetAM(), Maybe->GetSem());

                            list <Subject> :: iterator l;
                            list <Subject> forprint = Maybe->GetList();
                            for(l = forprint.begin(); l != forprint.end(); l++)
                            {
                               mvwprintw(printS,i+3+distance+1,1,"Κωδικός: %s, Περιγραφή: %s, Εξάμηνο: %d, Υπεύθυνος: %s", l->getSub().c_str(), l->getDes().c_str(), l->getSem(), (l->getHead())->GetName().c_str());
                               currentLine++;
                            }
                            currentLine++;
                        }
                    }

                    wrefresh (printS);
                    wgetch (printS);

                    delwin(printS);
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case PrintTeach:
                {
                    WINDOW *printΤ = newwin(LINES,COLS,0,0);
                    box(printΤ,0,0);
                    mvwprintw(printΤ,1,COLS/2-5,"ΕΚΤΎΠΩΣΗ ΚΑΘΗΓΗΤΏΝ"); 

                    vector <Person *> &search = record.GetMembers();

                    int currentLine = 3;

                    for (int i = 0;i < search.size(); i++)
                    {
                        Teacher *Maybe = dynamic_cast<Teacher *>(search[i]);
                        if (Maybe)
                        {
                            int distance = 0;
                            mvwprintw(printΤ,currentLine,1,"Όνομα/Επίθετο: %s, Φύλο: %c, Κωδικός: %s, Ειδικότητα: %s", Maybe->GetName().c_str(), Maybe->GetMF(), Maybe->GetCode(), Maybe->GetSpecial().c_str());

                            list <Subject> :: iterator l;
                            list <Subject> forprint = Maybe->GetList();
                            for(l = forprint.begin(); l != forprint.end(); l++)
                            {
                               mvwprintw(printΤ,i+3+distance+1,1,"Κωδικός: %s, Περιγραφή: %s, Εξάμηνο: %d, Υπεύθυνος: %s", l->getSub().c_str(), l->getDes().c_str(), l->getSem(), (l->getHead())->GetName().c_str());
                               currentLine++;
                            }
                            currentLine++;
                        }
                    }

                    wrefresh (printΤ);
                    wgetch (printΤ);

                    delwin(printΤ);
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case PrintSub:
                {
                    WINDOW *printSub = newwin(LINES,COLS,0,0);
                    box(printSub,0,0);
                    mvwprintw(printSub,1,COLS/2-5,"ΕΚΤΎΠΩΣΗ ΜΑΘΗΜΆΤΩΝ"); 

                    list <Subject> :: iterator l;
                    list <Subject> &forprint = record.GetSubjects();

                    int current = 0;

                    for (l = forprint.begin(); l != forprint.end(); l++)
                    {
                        mvwprintw(printSub,current+3,1,"Κωδικός: %s, Περιγραφή: %s, Εξάμηνο: %d, Υπεύθυνος: %s", l->getSub().c_str(), l->getDes().c_str(), l->getSem(), (l->getHead())->GetName().c_str());
                        current++;
                    }

                    wrefresh (printSub);
                    wgetch (printSub);

                    delwin(printSub);
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case SaveSt:
                {
                    try
                    {
                        record.StudentOCSV();
                    }
                    catch(int x)
                    {
                        mvwprintw(menuwin,9,20,"Αδυναμία Αποθήκευσης");
                        wrefresh(menuwin);
                        break;
                    }
                    mvwprintw(menuwin,9,30,"Επιτυχής Aποθήκευση");
                    wrefresh(menuwin);
                    wgetch(menuwin);
                    mvwprintw(menuwin, 9, 30, "                    ");
                    wrefresh(menuwin);
                    break;
                }
                case SaveTeach:
                {
                    try
                    {
                        record.TeacherOCSV();
                    }
                    catch(int x)
                    {
                        mvwprintw(menuwin,10,20,"Αδυναμία Αποθήκευσης");
                        wrefresh(menuwin);
                        break;
                    }
                    mvwprintw(menuwin,10,30,"Επιτυχής Aποθήκευση");
                    wrefresh(menuwin);
                    wgetch(menuwin);
                    mvwprintw(menuwin,10, 30, "                     ");
                    wrefresh(menuwin);
                    wrefresh(menuwin);
                    break;
                }
                case LoadSt:
                {
                    try
                    {
                        record.StudentICSV();
                    }
                    catch(int x)
                    {
                        mvwprintw(menuwin,11,30,"Αδυναμία Φόρτωσης");
                        wrefresh(menuwin);
                        break;
                    }
                    mvwprintw(menuwin,11,30,"Επιτυχής Φόρτωση");
                    wrefresh(menuwin);
                    wgetch(menuwin);
                    mvwprintw(menuwin,11, 30, "                    ");
                    wrefresh(menuwin);
                    break;
                }
                case LoadTeach:
                {
                    try
                    {
                        record.TeacherICSV();
                    }
                    catch(int x)
                    {
                        mvwprintw(menuwin,12,30,"Αδυναμία Φόρτωσης");
                        wrefresh(menuwin);
                        break;
                    }

                    mvwprintw(menuwin,12,30,"Επιτυχής Φόρτωση");
                    wrefresh(menuwin);
                    wgetch(menuwin);
                    mvwprintw(menuwin, 12, 30, "                    ");
                    wrefresh(menuwin);

                    break;
                }
                case AddSubSt:
                {
                    WINDOW *addSS = newwin(LINES,COLS,0,0);
                    box(addSS,0,0);
                    mvwprintw(addSS,1,COLS/2-5,"ΒΙΒΛΊΟ ΣΕ ΜΑΘΗΤΉ");
                    mvwprintw(addSS,4,1,"Κωδικός Βιβλίου: ");
                    mvwprintw(addSS,5,1,"AM Μαθήτη: ");

                    bool validAM,validCode;

                    do
                    {
                        validAM = false,validCode = false;

                        mvwprintw(addSS, 4, 20, "                    "); 
                        mvwprintw(addSS, 5, 20, "                    ");

                        list <Subject> :: iterator l;
                        list <Subject> &forsearch = record.GetSubjects();

                        vector <Person *> &search3 = record.GetMembers();

                        echo();
                        char input[100];

                        mvwgetnstr(addSS, 4, 20, input, 99);
                        string Code(input);

                        mvwgetnstr(addSS, 5, 20, input, 99);
                        for (l = forsearch.begin(); l != forsearch.end(); l++)
                        {
                            if (l->getSub() == Code)
                            {
                                validCode = true;
                                break;
                            }
                        }
                        if (validCode == true)
                        {
                            for (int i=0; i < search3.size();i ++)
                            {
                                Student *Maybe = dynamic_cast<Student *>(search3[i]);
                                if (Maybe)
                                {
                                    if (!strcmp(Maybe->GetAM(),input))
                                    {
                                        validAM = true;
                                        search3[i]->AddSubject(*l);
                                        break;
                                    }
                                }
                            }
                        }
                    } 
                    while (validAM == false || validCode == false);

                    wrefresh (addSS);

                    delwin(addSS);
                    noecho();
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case AddSubTeach:
                {
                    WINDOW *addST = newwin(LINES,COLS,0,0);
                    box(addST,0,0);
                    mvwprintw(addST,1,COLS/2-5,"ΒΙΒΛΊΟ ΣΕ ΚΑΘΗΓΗΤΉ");
                    mvwprintw(addST,4,1,"Κωδικός Βιβλίου: ");
                    mvwprintw(addST,5,1,"Κωδικός Καθηγητή: ");

                    bool validTeachCode,validSubCode;

                    do
                    {
                        validTeachCode = false,validSubCode = false;

                        mvwprintw(addST, 4, 20, "                    "); 
                        mvwprintw(addST, 5, 20, "                    ");

                        list <Subject> :: iterator l;
                        list <Subject> &forsearch = record.GetSubjects();

                        vector <Person *> &search3 = record.GetMembers();

                        echo();
                        char input[100];

                        mvwgetnstr(addST, 4, 20, input, 99);
                        string Code(input);

                        mvwgetnstr(addST, 5, 20, input, 99);
                        for (l = forsearch.begin(); l != forsearch.end(); l++)
                        {
                            if (l->getSub() == Code)
                            {
                                validSubCode = true;
                                break;
                            }
                        }
                        if (validSubCode == true)
                        {
                            for (int i=0; i < search3.size();i ++)
                            {
                                Teacher *Maybe = dynamic_cast<Teacher *>(search3[i]);
                                if (Maybe)
                                {
                                    if (!strcmp(Maybe->GetCode(),input))
                                    {
                                        validTeachCode = true;
                                        search3[i]->AddSubject(*l);
                                        break;
                                    }
                                }
                            }
                        }
                    } 
                    while (validTeachCode == false || validSubCode == false);

                    wrefresh (addST);

                    delwin(addST);
                    noecho();
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case EmailSt:
                {
                    WINDOW *writeS = newwin(LINES,COLS,0,0);
                    box(writeS,0,0);
                    mvwprintw(writeS,1,COLS/2-5,"ΜΉΝΥΜΑ EMAIL");
                    mvwprintw(writeS,4,1,"Μήνυμα Email: ");

                    echo();

                    char input[100];

                    mvwgetnstr(writeS, 4, 20, input, 99);
                    noecho();

                    wrefresh (writeS);
                    delwin(writeS);

                    WINDOW *emailS = newwin(LINES,COLS,0,0);
                    box(emailS,0,0);
                    mvwprintw(emailS,1,COLS/2-5,"ΑΠΟΣΤΟΛΉ EMAIL");

                    vector <Person *> &email = record.GetMembers();

                    int distance = 3;
                    for(int i = 0;i < email.size();i++)
                    {
                        if (Student *estud = dynamic_cast<Student *>(email[i]))
                        {
                            mvwprintw(emailS,i+distance,1,"Προς φοιτητή : %s AM : %s",(estud->GetName()).c_str(),estud->GetAM());

                            distance++;

                            mvwprintw(emailS,i+distance,1,"Περιεχόμενο : %s",input);

                            distance+=2;
                        }
                    }

                    wrefresh (emailS);
                    wgetch (emailS);

                    delwin(emailS);
                    noecho();
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case EmailTeach:
                {
                    WINDOW *writeT = newwin(LINES,COLS,0,0);
                    box(writeT,0,0);
                    mvwprintw(writeT,1,COLS/2-5,"ΜΉΝΥΜΑ EMAIL");
                    mvwprintw(writeT,4,1,"Μήνυμα Email: ");

                    echo();

                    char input[100];

                    mvwgetnstr(writeT, 4, 20, input, 99);
                    noecho();

                    wrefresh (writeT);
                    delwin(writeT);

                    WINDOW *emailS = newwin(LINES,COLS,0,0);
                    box(emailS,0,0);
                    mvwprintw(emailS,1,COLS/2-5,"ΑΠΟΣΤΟΛΉ EMAIL");

                    vector <Person *> &email = record.GetMembers();

                    int distance = 3;
                    for(int i = 0;i < email.size();i++)
                    {
                        if (Teacher *eteach = dynamic_cast<Teacher *>(email[i]))
                        {
                            mvwprintw(emailS,i+distance,1,"Προς καθηγητή : %s Κωδικός : %s",(eteach->GetName()).c_str(),eteach->GetCode());

                            distance++;

                            mvwprintw(emailS,i+distance,1,"Περιεχόμενο : %s",input);

                            distance+=2;
                        }
                    }

                    wrefresh (emailS);
                    wgetch (emailS);

                    delwin(emailS);
                    noecho();
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case ChangeName:
                {
                    WINDOW *changeN = newwin(LINES,COLS,0,0);
                    box(changeN,0,0);
                    mvwprintw(changeN,1,COLS/2-5,"ΑΛΛΑΓΉ ΟΝΌΜΑΤΟΣ");
                    mvwprintw(changeN,4,1,"Καινούριο Όνομα: ");
                    mvwprintw(changeN,5,1,"Κωδικός/ΑΜ: ");

                    bool validcode;

                    do
                    {
                        validcode = false;

                        mvwprintw(changeN, 4, 20, "                    "); 
                        mvwprintw(changeN, 5, 20, "                    ");

                        vector <Person *> &search3 = record.GetMembers();

                        echo();
                        char input[100];

                        mvwgetnstr(changeN, 4, 20, input, 99);
                        string newname(input);

                        mvwgetnstr(changeN, 5, 20, input, 99);
                        for (int i=0; i < search3.size();i ++)
                        {
                            if (Student *maybe = dynamic_cast<Student *>(search3[i]))
                            {
                                if (!strcmp(maybe->GetAM(),input))
                                {
                                    maybe->SetName(newname);
                                    validcode = true;
                                    break;
                                }
                            }
                            if (Teacher *maybe2 = dynamic_cast<Teacher *>(search3[i]))
                            {
                                if (!strcmp(maybe2->GetCode(),input))
                                {
                                    maybe2->SetName(newname);
                                    validcode = true;
                                    break;
                                }
                            }
                        }   
                    } 
                    while (validcode == false);

                    wrefresh (changeN);

                    delwin(changeN);
                    noecho();
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case ChangeDesc:
                {
                    WINDOW *changeD = newwin(LINES,COLS,0,0);
                    box(changeD,0,0);
                    mvwprintw(changeD,1,COLS/2-5,"ΑΛΛΑΓΉ ΠΕΡΙΓΡΑΦΉΣ");
                    mvwprintw(changeD,4,1,"Καινούρια Περιγραφή: ");
                    mvwprintw(changeD,5,1,"Κωδικός: ");

                    bool validcode;

                    do
                    {
                        validcode = false;

                        mvwprintw(changeD, 4, 24, "                    "); 
                        mvwprintw(changeD, 5, 20, "                    ");

                        list <Subject> :: iterator l;
                        list <Subject> &forchange = record.GetSubjects();

                        echo();
                        char input[100];

                        mvwgetnstr(changeD, 4, 24, input, 99);
                        string newdes(input);

                        mvwgetnstr(changeD, 5, 20, input, 99);
                        string CodeS(input);
                        for (l = forchange.begin() ; l != forchange.end(); l++)
                        {
                            if (CodeS == l->getSub())
                            {
                                l->setDes(newdes);
                                validcode = true;
                                break;
                            }
                        }   
                    } 
                    while (validcode == false);

                    wrefresh (changeD);

                    delwin(changeD);
                    noecho();
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case DeleteM:
                {
                    WINDOW *changeN = newwin(LINES,COLS,0,0);
                    box(changeN,0,0);
                    mvwprintw(changeN,1,COLS/2-5,"ΔΙΑΓΡΑΦΉ ΜΈΛΟΥΣ");
                    mvwprintw(changeN,4,1,"Κωδικός/ΑΜ για Διαγραφή: ");

                    bool validcode;

                    do
                    {
                        validcode = false;

                        mvwprintw(changeN, 4, 30, "                    "); 


                        vector <Person *> &search3 = record.GetMembers();

                        echo();
                        char input[100];

                        mvwgetnstr(changeN, 4, 30, input, 99);
                        for (int i=0; i < search3.size();i ++)
                        {
                            if (Student *maybe = dynamic_cast<Student *>(search3[i]))
                            {
                                if (!strcmp(maybe->GetAM(),input))
                                {
                                    record.DeleteMember(input);
                                    validcode = true;
                                    break;
                                }
                            }
                            if (Teacher *maybe2 = dynamic_cast<Teacher *>(search3[i]))
                            {
                                if (!strcmp(maybe2->GetCode(),input))
                                {
                                    record.DeleteMember(input);
                                    validcode = true;
                                    break;
                                }
                            }
                        }   
                    } 
                    while (validcode == false);

                    wrefresh (changeN);

                    delwin(changeN);
                    noecho();
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
                case DeleteSub:
                {
                    WINDOW *changeD = newwin(LINES,COLS,0,0);
                    box(changeD,0,0);
                    mvwprintw(changeD,1,COLS/2-5,"ΔΙΑΓΡΑΦΉ ΜΑΘΉΜΑΤΟΣ");
                    mvwprintw(changeD,4,1,"Κωδικός για Διαγραφή: ");

                    bool validcode;

                    do
                    {
                        validcode = false;

                        mvwprintw(changeD, 4, 27, "                    "); 

                        list <Subject> :: iterator l;
                        list <Subject> &forchange = record.GetSubjects();

                        echo();
                        char input[100];

                        mvwgetnstr(changeD, 4, 27, input, 99);

                        for (l = forchange.begin() ; l != forchange.end(); l++)
                        {
                            if (input == l->getSub())
                            {
                                record.DeleteSubject(input);
                                validcode = true;
                                break;
                            }
                        }   
                    } 
                    while (validcode == false);

                    wrefresh (changeD);

                    delwin(changeD);
                    noecho();
                    touchwin(menuwin);
                    wrefresh(menuwin);

                    break;
                }
            }
        }
        if (choice == 'q' || choice == 'Q' || choice == ';')
        {
            endwin();
            exit(1);
        }
    }

    getch();
    endwin();

    return 0;
}