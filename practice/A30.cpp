#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class MyString
{
private:
	char * mystr;
public:
	MyString(const char *);
	MyString();
	~MyString();

	int SizeStr();

	MyString & operator = (const MyString &);
	bool operator == (MyString &);
	bool operator < (MyString &);

	vector <MyString> Split(const char);

	char * GetStr();
};

char * MyString::GetStr()
{
	return mystr;
}

MyString::MyString(const char *word)
{
	int size = strlen(word);
	mystr = new char[size + 1];
	strcpy(mystr,word);
}

MyString::MyString()
{
	mystr = new char [1];
	strcpy(mystr,"");
}

MyString::~MyString()
{
	delete [] mystr;
}

int MyString::SizeStr()
{
	return (strlen(this->GetStr()) + 1);
}

MyString & MyString::operator =(const MyString &word)
{
	if (this == &word)
		return *this;

	delete[] mystr;
        int size = strlen(word.mystr);
        mystr = new char[size + 1];
        memcpy(mystr,word.mystr,size + 1);

	return *this;
}

bool MyString::operator ==(MyString &Equal)
{
	if (this->SizeStr() == Equal.SizeStr())
		return true;
	else
		return false;
}

bool MyString::operator <(MyString &Less)
{
        if (this->SizeStr() < Less.SizeStr())
                return true;
        else
                return false;
}

vector <MyString> MyString::Split(const char x)
{
	vector <MyString> lista;
	char *buf = new char [100];
	int j=0;

	int size = this->SizeStr();
	char *string = new char[size];
	strcpy(string,this->GetStr());

	for (int i=0;i<size;i++)
	{
		if (string[i] != x || string != "")
		{
			buf[j] = string[i];
			j++;
		}
		else
		{
			j = 0;
			MyString ForList(buf);
			lista.push_back(ForList);
		}
	}
	delete[] buf;
	delete[] string;
	return lista;
}

int main()
{
	MyString *first = new MyString("Salamanka");
	MyString *second = new MyString("Goodman");
	MyString *thirf = new MyString("WalterJ");
	MyString *forsplit = new MyString("Aba,Saba,Daba,Kappa");

	if (*second < *first)
		cout << "Salamanka is longer" << endl;

	if (*second == *thirf)
		cout << "WalterJ and Goodman are the same" << endl;

	*second = *thirf;

	cout << second->GetStr() << endl;

	vector <MyString> splitted = forsplit->Split(',');

	for (int i=0;i<splitted.size();i++)
	{
		cout << splitted[i].GetStr() << endl;
	}

	return 0;
}
