#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct stablo Stablo;
typedef struct stablo* position;
struct stablo {
	int el;
	position LD;
	position RD;
};

int odabir();
int unos(position,int);

int main()
{
	Stablo s;
	s.LD = NULL;
	s.RD = NULL;
	s.el = 0;
	int x = 0;
	int a = 0;

	while (x != 5)
	{
		x = odabir();
		
		if (x == 1)
		{
			
			while (a < 1)
			{
				printf("Unesite element a=");
				scanf("%d", &a);

				if (a < 1)
					printf("\nU binarno stablo pretrazivanja moguće je unositi samo pozitivne brojeve\n");
			}
			unos(&s,a);
		}

		
	}
}

int odabir()
{
	int x = 0;
	
	while (x < 1 || x>5)
	{
		printf("Unesi broj operacije koju zelis:\n ");
		printf("1.Unos\n");
		printf("2.Brisi\n");
		printf("3.Trazi\n");
		printf("4.Ispis\n");
		printf("5.Izlaz\n");

		scanf("%d", &x);
		if (x < 1 || x>5)
			printf("To nije ponudena opcija\n");
	}
	return x;
}

int unos(position p,int x)
{
	position q = NULL;
	
	if (p->el == 0)
	{
		p->el = x;
		return 0;
	}

	if (x > p->el)
	{
		if (p->LD != NULL)
		{
			q = p->LD;
			unos(q, x);
		}

		else
		{
			q = (position)malloc(sizeof(Stablo));
			p->LD = q;
			q->el = x;
			q->LD = NULL;
			q->RD = NULL;
		}

	}

	if (x < p->el)
	{
		if (p->RD != NULL)
		{
			q = p->RD;
			unos(q, x);
		}

		else
		{
			q = (position)malloc(sizeof(Stablo));
			p->RD = q;
			q->el = x;
			q->LD = NULL;
			q->RD = NULL;
		}
	}

	return 0;
}
