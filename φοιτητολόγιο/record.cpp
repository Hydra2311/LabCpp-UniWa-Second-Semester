#include "record.h"
#include "student.h"
#include "teacher.h"

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