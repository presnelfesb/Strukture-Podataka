#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 1024
typedef struct stablo Stablo;
typedef struct stablo *position;



struct stablo {
	position LD;
	position RD;
	char* z;
};

struct stog;
typedef struct stog Stog;
typedef struct stog* pozicija;

struct stog {
	position s;
	pozicija next;
};

position unos(char*);
int ispis(position);
int push(pozicija, position);
position pop(pozicija);


int main()
{
	position p = NULL;

	char*ime = NULL;

	ime = (char*)malloc(sizeof(char)*M);
	printf("Unesite naziv datoteke: ");
	scanf(" %s", ime);

	p = unos(ime);
	ispis(p);

	return 0;
}

position unos(char *ime)
{
	FILE *fp = NULL;
	char* temp = NULL;
	Stog q;
	q.next = NULL;
	position temp1 = NULL;
	position a = NULL;
	position b = NULL;

	fp = fopen(ime, "r");
	if (fp == NULL)
	{
		printf("Datoteka nije otvorena");
	}

	while (!feof(fp))
	{
		temp = (char*)malloc(N * sizeof(char));
		fscanf(fp, " %s", temp);
		if ((temp[0] != '+') && (temp[0] && '*') && (temp[0] != '-'))
		{
			temp1 = (position)malloc(sizeof(Stablo));
			temp1->z = temp;
			temp1->LD = NULL;
			temp1->RD = NULL;


			push(&q, temp1);
		}
		else
		{
			a = pop(&q);
			b = pop(&q);
			temp1 = (position)malloc(sizeof(Stablo));
			temp1->z = temp;
			temp1->LD = b;
			temp1->RD = a;


			push(&q, temp1);
		}
		free(temp);
		free(temp1);
	}

	return pop(&q);
}

int ispis(position p)
{
	if (p != NULL)
	{
		ispis(p->LD);
		printf("%s ", p->z);
		ispis(p->RD);
	}
	return 0;
}



int push(pozicija p, position x)
{
	pozicija q = NULL;

	q = (pozicija)malloc(sizeof(Stog));

	q->s = x;
	q->next = p->next;
	p->next = q;

	return 0;
}

position pop(pozicija p)
{
	pozicija q = NULL;
	position x = NULL;

	q = p->next;
	x = p->next->s;
	p->next = p->next->next;
	free(q);

	return x;
}
