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

int Ispis(position);
int Unos(position);
int Zbroji(position, position, position);
int Umnozak(position, position, position);


int main()
{
	int n = 0;
	Polinom p1, p2, zbroj, umnozak;

	p1.next = NULL;
	printf("Prvi polinom\n");
	Unos(&p1);
	Ispis(&p1);

	p2.next = NULL;
	printf("\nDrugi polinom\n");
	Unos(&p2);
	Ispis(&p2);

	zbroj.next = NULL;
	printf("\nZbroj polinoma je:\n");
	Zbroji(&p1, &p2, &zbroj);
	Ispis(&zbroj);

	umnozak.next = NULL;
	printf("\nUmnozak polinoma je:\n");
	Umnozak(&p1, &p2, &umnozak);
	Ispis(&umnozak);




	return 0;
}

int Unos(position p)
{
	int n = 0;
	int i = 0;
	position q = NULL, temp = NULL;


	printf("Koliko cete unjeti clanova u polinom:"); scanf("%d", &n);

	temp = p;
	for (i = 0; i < n; i++)
	{
		q = (position)malloc(sizeof(Polinom));

		printf("Unesi %d. koeficijent: ",i+1);
		scanf(" %d", &q->koef);
		printf("\Unesi %d. eksponent: ",i+1);
		scanf(" %d", &q->expo);

		while (p->next != NULL && q->expo < p->next->expo)
			p = p->next;

		if (p->next != NULL && q->expo == p->next->expo)
		{
			p->next->koef = p->next->koef + q->koef;
		}
		else
		{
			q->next = p->next;
			p->next = q;
		}
		p = temp;

	}
	return 0;
}


int Ispis(position p)
{
	p = p->next;
	printf("(%dx^%d)", p->koef, p->expo);
	p = p->next;
	while (p != NULL)
	{
		printf("+(%dx^%d)", p->koef, p->expo);
		p = p->next;
	}
	printf("\n");
	return 0;
}

int Zbroji(position p1, position p2, position z)
{
	position q = NULL, temp = NULL;

	p1 = p1->next;
	p2 = p2->next;

	while (p1 != NULL && p2 != NULL)
	{
		q = (position)malloc(sizeof(Polinom));

		if (p1->expo > p2->expo)
		{
			q->koef = p1->koef;
			q->expo = p1->expo;
			p1 = p1->next;
		}
		else if (p2->expo > p1->expo)
		{
			q->koef = p2->koef;
			q->expo = p2->expo;
			p2 = p2->next;
		}
		else
		{
			q->koef = p1->koef + p2->koef;
			q->expo = p1->expo;
			p1 = p1->next;
			p2 = p2->next;
		}
		q->next = z->next;
		z->next = q;
		z = z->next;
	}

	if (p1 != NULL)
		temp = p1;
	else
		temp = p2;

	while (temp != NULL)
	{
		q = (position)malloc(sizeof(Polinom));
		q->koef = temp->koef;
		q->expo = temp->expo;

		q->next = z->next;
		z->next = q;
		z = z->next;

		temp = temp->next;
	}

	return 0;
}

int Umnozak(position p1, position p2, position u)
{
	position q = NULL, temp1 = NULL;
	position temp2 = NULL;
	p1 = p1->next;
	p2 = p2->next;

	temp2 = u;
	temp1 = p2;


	while (p1 != NULL)
	{
		while (p2 != NULL)
		{
			u = temp2;
			
			q = (position)malloc(sizeof(Polinom));
			q->koef = p1->koef * p2->koef;
			q->expo = p1->expo + p2->expo;

			
			while (u->next != NULL && u->next->expo > q->expo)
				u = u->next;

			if (u->next != NULL && q->expo == u->next->expo)
			{
				u->next->expo = q->expo;
				u->next->koef = u->next->koef + q->koef;

			}
			else
			{
				q->next = u->next;
				u->next = q;


			}


			p2 = p2->next;
		}
		p1 = p1->next;
		p2 = temp1;
	}
	return 0;

}
