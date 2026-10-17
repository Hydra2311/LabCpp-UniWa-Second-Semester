#include <iostream>
#include <string>
#include <list>

using namespace std;

class Animal
{
private:
	int height;
public:
	Animal(int k) : height(k){};
	virtual ~Animal(){};

	virtual int GetHeight(){return height;};
};

class TypeBird : public Animal
{
private:
	string name;
	int length;
public:
	TypeBird(string Name,int Length,int Height) : Animal(Height),name(Name), length(Length){};
	~TypeBird(){};

	string Getname();
};

string TypeBird::Getname()
{
	return name;
}

class TypeFish : public Animal
{
private:
        string name;
        int length;
public:
        TypeFish(string Name,int Length,int Height) : Animal(Height), name(Name), length(Length){};
        ~TypeFish(){};

        string GetName();
};

string TypeFish::GetName()
{
        return name;
}

ostream & operator << (ostream &x, list <Animal *>& forfish)
{
	list <Animal *> :: iterator l;
	for (l = forfish.begin() ; l != forfish.end(); l++)
	{
		TypeFish *Maybe = dynamic_cast<TypeFish *>(*l);
		if (Maybe)
		{
			x << Maybe->GetName() << endl;
		}
	}

	return x;
}

int main()
{
	list <Animal *> Kingdom;

	TypeFish Tsipoura("Τσιπούρα", 3,4);
	TypeBird Pelekanos("Πελεκάνος",5,7);
	TypeBird Geraki("Γεράκι",6,7);
	TypeFish Lagokefalos("Λαγοκέφαλος",10,12);

	Kingdom.push_back(&Tsipoura);
	Kingdom.push_back(&Pelekanos);
	Kingdom.push_back(&Geraki);
	Kingdom.push_back(&Lagokefalos);

	cout << Kingdom << endl;

	return 0;
}
