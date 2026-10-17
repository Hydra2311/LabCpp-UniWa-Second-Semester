#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

class Product
{
private:
	char * code;
	string des;
	float price;
public:
	Product(const char *,string,const float);
	~Product();

	list <Product> ReadFile(string &);
	void Delete(list <Product> &,const float &);

	float GetPrice() const;
	char * GetCode() const;
	string GetDes() const;
};

list <Product> ReadFile(string);

void Delete(list <Product> &,const float &);

char * Product::GetCode() const
{
	return code;
}

string Product::GetDes() const
{
	return des;
}

float Product::GetPrice() const
{
	return price;
}

Product::Product(const char *Code,string Des, const float Price)
{
	int size = strlen(Code);
	code = new char[size + 1];
	strcpy(code,Code);

	des = Des;
	price = Price;
}

Product::~Product()
{
	delete []code;
}

list <Product> ReadFile(string filename)
{
	ifstream file(filename);

	if (!file.is_open())
	{
		throw 1;
	}

	string line;

	list <Product> empty_list;

	while(getline(file,line))
	{
		stringstream ss(line);
		string Code,Des,Price;

		getline(ss,Code,';');
		getline(ss,Des,';');
		getline(ss,Price);

		Product Neo(Code.c_str(),Des,stof(Price));

		empty_list.push_back(Neo);
	}

	return empty_list;
}

void Delete(list <Product> &lista,const float &meta)
{
	list <Product> :: iterator l;

	for(l = lista.begin();l != lista.end(); l++)
	{
		if (l->GetPrice() == meta)
		{
			l = lista.erase(l);
			break;
		}
	}
}

int main()
{
	list <Product> Lista;
	list <Product> :: iterator l;

	try
	{
		Lista = ReadFile("hey.txt");
	}
	catch(int x)
	{
		cerr << "Couldn't open file" << endl;
		exit(-1);
	}

	Delete(Lista,2.2);

	for (l = Lista.begin(); l != Lista.end(); l++)
	{
		cout << l->GetCode() << " " << l->GetDes() << " " << l->GetPrice() << endl;
	}

	return 0;
}


