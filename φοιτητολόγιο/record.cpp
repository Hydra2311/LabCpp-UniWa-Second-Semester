#include "record.h"
#include "student.h"
#include "teacher.h"
#include <fstream>

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
    if (code == nullptr) return;

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
            x << "Προς φοιτητή : " << estud->GetName() << "AM : " << estud->GetAM() << endl;
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
            x << "Προς φοιτητή : " << eteach->GetName() << "AM : " << eteach->GetCode() << endl;
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