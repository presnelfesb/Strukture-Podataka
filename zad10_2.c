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

int unos(char*, position);
int ispis(position);
int push(pozicija , position );
position pop(pozicija );


int main()
{
	Stablo s;
	s.LD = NULL;
	s.RD = NULL;

	char*ime = NULL;

	ime = (char*)malloc(sizeof(char)*M);
	printf("Unesite naziv datoteke: ");
	scanf(" %s", ime);

	unos(ime, &s);
	ispis(&s);

	return 0;
}

int unos(char *ime, position p)
{
	FILE *fp = NULL;
	char* temp=NULL;
	Stog q;
	q.next = NULL;
	position temp1=NULL;
	position a = NULL;
	position b = NULL;

	fp = fopen(ime, "r");
	if (fp == NULL)
	{
		printf("Datoteka nije otvorena");
		return -1;
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
	p = pop(&q);
	return 0;
}

int ispis(position p)
{
	if (p != NULL)
	{
		ispis(p->LD);
		printf("%s ", p->z[4]);
		ispis(p->RD);
	}
	return 0;
}



int push(pozicija p, position x)
{
	pozicija q = NULL;
	position temp;

	q = (pozicija)malloc(sizeof(Stog));
	temp = x;

	q->s = temp;
	q->next = p->next;
	p->next = q;

	return 0;
}

position pop(pozicija p)
{
	pozicija q = NULL;
	position x = NULL;
	q = (pozicija)malloc(sizeof(Stog));

	q = p->next;
	x = p->next->s;
	p->next = p->next->next;
	free(q);

	return x;
}
