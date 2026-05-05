#include <time.h>
#include <stdlib.h>
#include <stdio.h>

struct intpoint
{
	int x;
	int y;
};

struct floatpoint
{
	float x;
	float y;
};

intpoint &farthest(intpoint*,int );
floatpoint &farthest(floatpoint*,int );

int main()
{
	const int n(10);
	intpoint *ipinakas;
	floatpoint *fpinakas;
	srand(time(NULL));

	ipinakas = new intpoint[n];
	fpinakas = new floatpoint[n];

	for(int i=0;i<n;i++)
	{
		ipinakas[i].x = rand()%21 - 10;
		ipinakas[i].y = rand()%21 - 10;
		printf("x: %d y: %d\n",ipinakas[i].x,ipinakas[i].y);
	}

        for(int i=0;i<n;i++)
        {
                fpinakas[i].x = ((rand() / (float)(RAND_MAX)) * 20.0f) - 10.0f;
                fpinakas[i].y = ((rand() / (float)(RAND_MAX)) * 20.0f) - 10.0f;
		printf("x: %.2f y: %.2f\n",fpinakas[i].x,fpinakas[i].y);
        }

	intpoint &maxipoint =  farthest(ipinakas,n);
	floatpoint &maxfpoint =  farthest(fpinakas,n);
	printf("Μέγιστο ακέραιο σημείο x: %d y: %d\n",maxipoint.x,maxipoint.y);
	printf("Μέγιστο πραγματικό σημείο x: %.2f y: %.2f\n",maxfpoint.x,maxfpoint.y);

	delete[] ipinakas;
	delete[] fpinakas;

	return 0;
}

intpoint &farthest(intpoint *ipinakas,int n)
{
	int maxdist = ipinakas[0].x * ipinakas[0].x + ipinakas[0].y * ipinakas[0].y;
	int dist;
	int maxi = 0;

	for(int i=1;i<n;i++)
	{
		dist = ipinakas[i].x * ipinakas[i].x + ipinakas[i].y * ipinakas[i].y;
		if (dist > maxdist)
		{
			maxdist = dist;
			maxi = i;
		}
	}

	return ipinakas[maxi];
}

floatpoint &farthest(floatpoint *fpinakas,int n)
{
        float maxdist = fpinakas[0].x * fpinakas[0].x + fpinakas[0].y * fpinakas[0].y;
        float dist;
	int maxi = 0;

        for(int i=1;i<n;i++)
        {
                dist = fpinakas[i].x * fpinakas[i].x + fpinakas[i].y * fpinakas[i].y;
                if (dist > maxdist)
                {
                        maxdist = dist;
                        maxi = i;
                }
        }

        return fpinakas[maxi];
}
