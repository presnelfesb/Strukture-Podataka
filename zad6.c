#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5
#define VELICINA 20

struct stog;
typedef struct stog Stog;
typedef struct stog* position;

struct stog {
	int el;
	position next;
};

int push(position, int);
int pop(position);
int unos(position, char*);
int ispis(position);

int main()
{
	Stog s;
	s.next = NULL;
	char* ime = NULL;

	ime = (char*)malloc(sizeof(char) * VELICINA);
	if (ime == NULL)
	{
		printf("Memorija nije alocirana");
		return -1;
	}

	printf("Unesi ime datoteke: ");
	scanf(" %s", ime);

	unos(&s, ime);
	printf("Rezultat je: %d", ispis(&s));

	return 0;

}

int unos(position p, char* ime)
{
	position q = NULL;
	FILE* fp = NULL;
	char* temp;
	int a = 0;
	int b = 0;


	fp = fopen(ime, "r");
	if (fp == NULL)
	{
		printf("Datoteka nije otvorena");
		return -1;
	}



	while (!feof(fp))
	{
		q = (position)malloc(sizeof(Stog));
		if (q == NULL)
		{
			printf("Memorija nije alocirana");
			return -1;
		}

		temp = (char*)malloc(sizeof(char) * N);

		fscnaf(fp, " %s", temp);

		if (isdigit(temp) != 0)
		{
			push(&p, atoi(temp));
		}
		else
		{
			a = pop(&p);
			b = pop(&p);

			if (strcmp(temp, '+') == 0)
				push(&p, a + b);

			else if (strcmp(temp, '-') == 0)
				push(&p, a - b);

			else if (strcmp(temp, '*') == 0)
				push(&p, a * b);

		}
		free(q);
		free(temp);
	}
	return 0;
}

int push(position p, int x)
{
	position q = NULL;

	q = (position)malloc(sizeof(Stog));

	q->el = x;
	q->next = p->next;
	p->next = q;

	return 0;
}

int pop(position p)
{
	position q;
	q = (position)malloc(sizeof(Stog));

	q->el = p->next->el;
	p->next = p->next->next;

	return q->el;
}

int ispis(position p)
{
	p = p->next;
	return p->el;
}
