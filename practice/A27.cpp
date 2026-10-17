#include <iostream>

template <typename T> class Pina
{
private:
	T **pinakas;
	int x,y;
public:
	Pina (int ,int );
	Pina (const Pina &);
	~Pina ();

	Pina & operator = (const Pina &);

	void Set(T &,int ,int );
	T & Get(int ,int );

	void Change(T *,int );

	int Getx();
	int Gety();
};

template <typename T>
int Pina<T>::Getx()
{
	return x;
}

template <typename T>
int Pina<T>::Gety()
{
        return y;
}

template <typename T>
Pina<T>::Pina(int xs, int ys)
{
	pinakas = new T[x];
	for (int i=0;i<x;i++)
	{
		pinakas[i] = new T[y];
	}
	x = xs;
	y = ys;
}

template <typename T>
Pina<T>::Pina(const Pina &More)
{
        pinakas = new T[More.Getx()];
        for (int i=0;i<More.Getx();i++)
        {
                pinakas[i] = new T[More.Gety()];
        }
	memcpy(pinakas,More.pinakas,x*y*sizeof(T));
}

template <typename T>
Pina<T>::~Pina()
{
        for (int i=0;i<this->Getx();i++)
        {
                delete [] pinakas[i];
        }
        delete []pinakas;
}

template <typename T>
Pina<T> & Pina<T>::operator =(const Pina &More)
{
	if (*this == More)
		return *this;
	for (int i=0;i<this->Getx();i++)
        {
                delete [] pinakas[i];
        }
	delete []pinakas;
        pinakas = new T[More.Getx()];
        for (int i=0;i<More.Getx();i++)
        {
                pinakas[i] = new T[More.Gety()];
        }
        memcpy(pinakas,More.pinakas,x*y*sizeof(T));

	return *this;
}

template <typename T>
void Pina<T>::Set(T &thing, int x,int y)
{
	pinakas[x][y] = thing;
}

template <typename T>
T & Pina<T>::Get(int x,int y)
{
        return pinakas[x][y];
}

template <typename T>
void Pina<T>::Change(T *pin,int x)
{
	for(int i=0;i<x;i++)
	{
		pinakas[x][i] = pin[i];
	}
}

int main()
{
	Pina<int> *pin = new Pina(4,4);

	return 0;
}
