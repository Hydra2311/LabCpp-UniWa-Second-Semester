#include "subject.h"
#include "teacher.h"

void Subject::SubPrint(ostream &x) const
{
    x << "Code: " << Subcode << " Description: " << Descript << " Semester: " << TeachSem << " Υπεύθυνος μαθήματος: " << endl;
    if (Head != nullptr) {
        Head->Print(x);
    } else {
        x << "None" << endl;
    }
}