#include "record.h"
#include "student.h"
#include "teacher.h"
#include <fstream>
#include <sstream>

void Record::AddPerson(Person *newly)
{
    Members.push_back(newly);
}

void Record::AddSubject(const Subject &newly)
{
    AllSub.push_back(newly);
}

void Record::PrintMemb(ostream &x)
{
    for (int i=0;i<Members.size();i++)
    {
        Members[i]->Print(cout);
    }
}

void Record::PrintSub(ostream &x)
{
    list <Subject> :: iterator l;

    for(l = AllSub.begin(); l != AllSub.end(); l++)
    {
        l->SubPrint(cout);
    }
}

void Record::ChangeName(const char *code,const string &newname)
{
    if (code == nullptr) return;

    for (int i = 0;i < Members.size();i++)
    {
        if (Student *maybe = dynamic_cast<Student *>(Members[i]))
        {
            if (!strcmp(maybe->GetAM(),code))
            {
                maybe->SetName(newname);
                break;
            }
        }
        if (Teacher *maybe2 = dynamic_cast<Teacher *>(Members[i]))
        {
            if (!strcmp(maybe2->GetCode(),code))
            {
                maybe2->SetName(newname);
                break;
            }
        }
    }
}

void Record::ChangeDesc(const string &code,const string &desc)
{
    list <Subject> :: iterator l;

    for(l = AllSub.begin();l != AllSub.end();l++)
    {
        if (l->getSub() == code)
        {
            l->setDes(desc);
            break;
        }
    }

    for (int i = 0; i < Members.size(); i++)
    {
        list <Subject> temp = Members[i]->GetList();

        bool changed = false;

        list <Subject> :: iterator it;

        for (it = temp.begin(); it != temp.end(); it++)
        {
            if (it->getSub() == code)
            {
                it->setDes(desc);
                changed = true;
                break;
            }
        }

        if (changed)
        {
            Members[i]->SetList(temp);
        }
    }
}

void Record::DeleteMember(const char *code)
{
    if (code == nullptr) return;

    for (int i = 0;i < Members.size();i++)
    {
        if (Student *maybe = dynamic_cast<Student *>(Members[i]))
        {
            if (!strcmp(maybe->GetAM(),code))
            {
                Members.erase(Members.begin()+i);
                break;
            }
        }
        if (Teacher *maybe2 = dynamic_cast<Teacher *>(Members[i]))
        {
            if (!strcmp(maybe2->GetCode(),code))
            {
                Members.erase(Members.begin()+i);
                break;
            }
        }
    }
}

void Record::DeleteSubject(const string &code)
{
    list <Subject> :: iterator l;

    for(l = AllSub.begin();l != AllSub.end();l++)
    {
        if (l->getSub() == code)
        {
            l = AllSub.erase(l);
            break;
        }
    }
}

Person * Record::SearchMember(const char *code)
{
    if (code == nullptr) return nullptr;

    for (int i = 0;i < Members.size();i++)
    {
        if (Student *maybe = dynamic_cast<Student *>(Members[i]))
        {
            if (!strcmp(maybe->GetAM(),code))
            {
                return Members[i];
            }
        }
        if (Teacher *maybe2 = dynamic_cast<Teacher *>(Members[i]))
        {
            if (!strcmp(maybe2->GetCode(),code))
            {
                return Members[i];
            }
        }
    }    

    return nullptr;
}

Subject * Record::SearchSubject(const string &code)
{
    list <Subject> :: iterator l;

    for(l = AllSub.begin();l != AllSub.end();l++)
    {
        if (l->getSub() == code)
        {
            return &(*l);
        }
    }    

    return nullptr;
}

void Record::EmailStudent(ostream &x,const string &message)
{
    for(int i = 0;i < Members.size();i++)
    {
        if (Student *estud = dynamic_cast<Student *>(Members[i]))
        {
            x << "Προς φοιτητή : " << estud->GetName() << " AM : " << estud->GetAM() << endl;
            x << "Περιεχόμενο : " << message << endl;
        }
    }
}

void Record::EmailTeacher(ostream &x,const string &message)
{
    for(int i = 0;i < Members.size();i++)
    {
        if (Teacher *eteach = dynamic_cast<Teacher *>(Members[i]))
        {
            x << "Προς καθηγητή : " << eteach->GetName() << " Κωδικός : " << eteach->GetCode() << endl;
            x << "Περιεχόμενο : " << message << endl;
        }
    }
}

void Record::StudentOCSV()
{
    ofstream stud("student.csv");

    if (!stud.is_open())
    {
        throw 1;
    }

    for(int i = 0;i < Members.size();i++)
    {
        if (Student *estud = dynamic_cast<Student *>(Members[i]))
        {
            list <Subject> :: iterator l;
            list <Subject> subList = estud->GetList();

            if (subList.empty()) 
            {
                stud << estud->GetName() << ", " 
                     << estud->GetAM() << ", "
                     << estud->GetMF() << ", " 
                     << estud->GetSem() 
                     << ", NONE" << endl;
            }
            else 
            {
                for (l = subList.begin(); l != subList.end(); l++)
                {
                    stud << estud->GetName() << ", " 
                         << estud->GetAM() << ", "
                         << estud->GetMF() << ", " 
                         << estud->GetSem() << ", "
                         << l->getSub() << endl;
                }
            }
        }
    }
}

void Record::TeacherOCSV()
{
    ofstream teach("teacher.csv");

    if (!teach.is_open())
    {
        throw 1;
    }

    for(int i = 0;i < Members.size();i++)
    {
        if (Teacher *eteach = dynamic_cast<Teacher *>(Members[i]))
        {
            list <Subject> :: iterator l;
            list <Subject> subList = eteach->GetList();

            if (subList.empty()) 
            {
                teach << eteach->GetName() << ", " 
                      << eteach->GetCode() << ", "
                      << eteach->GetMF() << ", " 
                      << eteach->GetSpecial() 
                      << ", NONE" << endl;
            }
            else 
            {
                for (l = subList.begin(); l != subList.end(); l++)
                {
                    teach << eteach->GetName() << ", " 
                          << eteach->GetCode() << ", "
                          << eteach->GetMF() << ", " 
                          << eteach->GetSpecial() << ", "
                          << l->getSub() << endl;
                }
            }

        }
    }
}

void Record::StudentICSV()
{
    ifstream stud("student.csv");

    if (!stud.is_open())
    {
        throw 1;
    }

    string line;

    while(getline(stud,line))
    {
        stringstream ss(line);
        string name, am, mf, sem, subCode;

        getline(ss,name,',');

        getline(ss,am,',');
        am.erase(0,1);

        getline(ss, mf, ',');
        mf.erase(0, 1); 
        
        getline(ss, sem, ',');
        sem.erase(0, 1);
        
        getline(ss, subCode);
        subCode.erase(0, 1);

        Person *Exists = SearchMember(am.c_str());
        Student *Current = dynamic_cast<Student *>(Exists);

        if (Current == nullptr)
        {
            char m_f  = mf[0];
            int semester = stoi(sem);
            
            list <Subject> emptyList;

            Current = new Student(am.c_str(),name,m_f,semester,emptyList);
            Members.push_back(Current);
        }

        if (subCode != "NONE")
        {
            Subject *NewSub = SearchSubject(subCode);

            if (NewSub != nullptr)
            {
                bool alreadyHasIt = false;
                list<Subject> tempList = Current->GetList();
                list<Subject>::iterator it;
                
                for (it = tempList.begin(); it != tempList.end(); it++)
                {
                    if (it->getSub() == subCode)
                    {
                        alreadyHasIt = true;
                        break;
                    }
                }

                if (!alreadyHasIt)
                {
                    Current->AddSubject(*NewSub);
                }
            }
        }
    }
}

void Record::TeacherICSV()
{
    ifstream teach("teacher.csv");

    if (!teach.is_open())
    {
        throw 1;
    }

    string line;

    while(getline(teach,line))
    {
        stringstream ss(line);
        string name, code, mf, specialty, subCode;

        getline(ss,name,',');

        getline(ss,code,',');
        code.erase(0,1);

        getline(ss, mf, ',');
        mf.erase(0, 1); 
        
        getline(ss, specialty, ',');
        specialty.erase(0, 1);
        
        getline(ss, subCode);
        subCode.erase(0, 1);

        Person *Exists = SearchMember(code.c_str());
        Teacher *Current = dynamic_cast<Teacher *>(Exists);

        if (Current == nullptr)
        {
            char m_f  = mf[0];
            
            list <Subject> emptyList;

            Current = new Teacher(name,m_f,code.c_str(),specialty,emptyList);
            Members.push_back(Current);
        }

        if (subCode != "NONE")
        {
            Subject *NewSub = SearchSubject(subCode);

            if (NewSub != nullptr)
            {
                bool alreadyHasIt = false;
                list<Subject> tempList = Current->GetList();
                list<Subject>::iterator it;
                
                for (it = tempList.begin(); it != tempList.end(); it++)
                {
                    if (it->getSub() == subCode)
                    {
                        alreadyHasIt = true;
                        break;
                    }
                }

                if (!alreadyHasIt)
                {
                    Current->AddSubject(*NewSub);
                }
            }
        }
    }
}
