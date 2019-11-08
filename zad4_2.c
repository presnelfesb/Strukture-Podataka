#define CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>



struct polinom;
typedef struct polinom Polinom;
typedef struct polinom *position;


struct polinom {
	int koef;
	int expo;
	position next;
};

int Stvori(position*,int);
int Unos(position);

int main()
{
	Polinom p1, p2, zbroj, umnozak;
	
	p1.next = NULL;
	p2.next = NULL;
	zbroj.next = NULL;
	umnozak.next = NULL;

	
	Unos(&p1);




}

int Unos(position p)
{
	int n = 0;
	int i = 0;

	

	printf("Koliko cete unjeti clanova u polinom:"); scanf("%d", &n);
	Stvori(p,n);
	printf("Unosi koeficijente i eksponencije:");

	
	for (i = 0;i < n;i++)
	{
		scanf(" %d %d", &p->koef, &p->expo);
		p = p->next;
	}

	return 0;
}

int Stvori(position *p,int n)
{
	p = (position)malloc(n * sizeof(Polinom));
	
	return 0;

}
