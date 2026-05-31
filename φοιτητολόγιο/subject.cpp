#include "subject.h"
#include "teacher.h"

void Subject::SubPrint(ostream &x) const
{
    x << "Code: " << Subcode << " Description: " << Descript << " Semester: " << TeachSem << " Υπεύθυνος μαθήματος: " << Head->GetName() << endl;
}

Subject & Subject::operator=(const Subject &Sub)
{
    if (this == &Sub)
    {
        return *this;
    }
    this->setSub(Sub.getSub());
    this->setHead(Sub.getHead());
    this->setDes(Sub.getDes());
    this->setSem(Sub.getSem());

    return *this;
}

Subject::Subject(const string &sub,const string &des,const int sem,Teacher *head)
{
    Subcode = sub;
    Descript = des;
    TeachSem = sem;
    Head = head;
}

Subject::Subject(const Subject &Sub)
{
    Subcode = Sub.Subcode;
    Descript = Sub.Descript;
    TeachSem = Sub.TeachSem;
    Head = Sub.Head;
}

Subject::~Subject()
{

}

void Subject::setSub(const string &sub)
{
    Subcode = sub;
}

void Subject::setDes(const string &des)
{
    Descript = des;
}

void Subject::setSem(const int sem)
{
    TeachSem = sem;
}

void Subject::setHead(Teacher *head)
{
    Head = head;
}

string Subject::getSub() const
{
    return Subcode;
}

string Subject::getDes() const
{
    return Descript;
}

int Subject::getSem() const
{
    return TeachSem;
}

Teacher * Subject::getHead() const
{
    return Head;
}