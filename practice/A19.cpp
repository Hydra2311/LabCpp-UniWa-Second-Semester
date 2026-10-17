#include <iostream>

using namespace std;

class Area
{
private:
	int *height;
	int *width;
public:
	Area(int *Height,int *Width): height(Height), width(Width){};
	~Area(){};

	bool operator > (Area &);

	int GetHeight();
	int GetWidth();
};

bool Area::operator >(Area &Second)
{
	int firstsize = (this->GetHeight()) * (this->GetWidth());
	int secondsize = (Second.GetHeight()) * (Second.GetWidth());

	if (firstsize > secondsize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Area::GetHeight()
{
	return *height;
}

int Area::GetWidth()
{
	return *width;
}

template <typename T> T * sort(T *pin,int size)
{
	for (int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(pin[j] > pin[j+1])
			{
				T temp = pin[j+1];
				pin[j+1] = pin[j];
				pin[j] = temp;
			}
		}
	}

	return pin;
}

int main()
{
	int a(1),b(2),c(3),d(4);
	Area *pinakas = new Area[4]
	{
		Area(&c,&c), Area(&b,&b), Area(&d,&d), Area(&a,&a)
	};

        for (int i=0;i<4;i++)
        {
                cout << pinakas[i].GetHeight() << "," << pinakas[i].GetWidth() << endl;
        }

	pinakas = sort(pinakas,4);

	for (int i=0;i<4;i++)
	{
		cout << pinakas[i].GetHeight() << "," << pinakas[i].GetWidth() << endl;
	}

	return 0;
}


