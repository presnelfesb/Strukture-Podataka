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
int unos(position, int);
int ispis(position);
position trazi(position, int);
position trazimin(position);
position brisi(position, int);


int main()
{
	Stablo s;
	position temp = NULL;
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
			unos(&s, a);
			a = 0;
		}
		else if (x == 2)
		{
			printf("\nUnesite broj koji zelite izbrisati: ");
			scanf("%d", &a);
			temp = brisi(&s, a);
			if (temp == NULL)
				printf("Broj koji ste unijeli ne postoji u stablu");
		}
		else if (x == 3)
		{
			printf("\nUnesite broj koji zelite pronaci: ");
			scanf("%d", &a);
			temp = trazi(&s, a);
			if (temp != NULL)
				printf("\nBroj je pronaden i nalazi se na adresi:%d\n\n", temp);
		}
		else if (x == 4)
		{
			printf("Ispis je:\n\n");
			ispis(&s);
			printf("\n\n");
		}


	}
	return 0;
}

int odabir()
{
	int x = 0;

	while (x < 1 || x>5)
	{
		printf("Unesi broj operacije koju zelis:\n");
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

int unos(position p, int x)
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

int ispis(position s)
{
	if (s != NULL)
	{
		if (s->el != 0)
			printf("%d\n\n ", s->el);

		if (s->el != 0)
			printf("Od broja %d \n", s->el);



		if (s->LD != NULL)
		{
			printf("Njegovo lijevo dijete je:");
			ispis(s->LD);
		}
		else
		{
			printf("Nema lijevog djeteta.");
		}
		if (s->RD != NULL)
		{
			printf("Njegovo desno dijete je:");
			ispis(s->RD);
		}
		else
		{
			printf("Nema desnog djeteta.");
		}
	}
	return 0;
}

position trazi(position s, int x)
{
	if (s == NULL)
	{
		printf("Ne postoji takav clan\n");
		return NULL;
	}
	else if (x < s->el)
	{
		return trazi(s->LD, x);
	}
	else if (x > s->el)
	{
		return trazi(s->RD, x);
	}
	else
		return s;
}

position trazimin(position s)
{
	if (s == NULL)
		return NULL;
	else if (s->LD == NULL)
		return s;
	else
		return trazimin(s->LD);
}

position brisi(position s, int x)
{
	position temp;

	if (s == NULL)
		printf("\nBroj koji ste izabrali ne postoji u stablu.\n");

	else if (x < s->el)
		s->LD = brisi(s->LD, x);

	else if (x > s->el)
		s->RD = brisi(s->RD, x);

	else if (s->LD != NULL && s->RD != NULL)
	{
		temp = trazimin(s->RD);
		s->el = temp->el;
		s->RD = brisi(s->RD, s->el);
	}
	else
	{
		temp = s;
		if (s->RD == NULL)
			s = s->LD;
		else
			s = s->RD;
		free(temp);

	}
	return s;
}
