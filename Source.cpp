#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
struct point
{
	char name[5];
	double x;
	double y;
};
double ans(struct point* a,int i[2])
{
	return sqrt(pow(a[i[0]].x-a[i[1]].x,2)+ pow(a[i[0]].y - a[i[1]].y, 2));
}
int checkname(struct point *a,int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (strcmp((a + i)->name, (a + i + 1)->name)==0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{	
	struct point* ptr;
	int n;
	char name1[2][5];
	bool isend = 0;
	printf("Enter number of point = ");
	scanf("%d",&n);
	if (n < 2)
	{
		printf("End\n");
		return 0;
	}
	ptr = (struct point*)malloc(n * sizeof(struct point));
	for (int i = 0; i < n; i++)
	{
		scanf("%s %lf %lf", (ptr + i)->name, &(ptr + i)->x, &(ptr + i)->y);
	}
	if (checkname(ptr, n) == 1)
	{
		printf("Error\n");
		return 0;
	}
	while (!isend)
	{
		repeat :
		printf("Enter 2 point : ");
		for (int i = 0; i < 2; i++)
		{
			scanf("%s", name1[i]);
		}
		int check = 0;
		int pos[2] = { 0,0 };
		for (int i = 0; i < 2; i++)
		{
			for (int k = 0; k < n; k++)
			{
				if (name1[0][0] == '0' && name1[1][0] == '0')
				{
					printf("End\n");
					return 0;
				}
				 else if (strcmp(name1[i], ptr[k].name) ==0)
				{
					check += 1;
					pos[i] = k;
				}
			}
		}
		if (check == 2)
		{
			printf( "The distant between %s ans %s is %lf.\n--------------------------------------------------------\n",ptr[pos[0]].name,ptr[pos[1]].name,ans(ptr,pos));
		}
		else
		{
			printf("Please try again\n--------------------------------------------------------\n");
		}
	}
	return 0;
}
