#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
	

	return 0;

}

int unos(position p, char* ime)
{
	position q = NULL;
	FILE* fp = NULL;
	char* temp = NULL;
	int a = 0;
	int b = 0;
	char plus [2] = { '+' };
	char minus [2] = { '-' };
	char umnozak [2] = { '*' };


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

		fscanf(fp, " %s", temp);

		if (isdigit(temp[0]) != 0)
		{
			push(&p, atoi(temp));
		}
		else
		{
			a = pop(&p);
			b = pop(&p);

			if (strcmp(temp,plus) == 0)
				push(&p, a + b);

			else if (strcmp(temp,minus) == 0)
				push(&p, a - b);

			else if (strcmp(temp, umnozak) == 0)
				push(&p, a * b);

		}
		free(q);
		free(temp);
	}
	printf("Rezultat je: %d\n", ispis(&p));
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
	position q=NULL;
	int x = 0;
	q = (position)malloc(sizeof(Stog));

	q = p->next;
	x = p->next->el;
	p->next = p->next->next;
	free(q);

	return x;
}

int ispis(position p)
{
	p = p->next;
	return p->el;
}
