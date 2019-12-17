#include <stdio.h>
#include <stdlib.h>

#define N 1024

typedef struct CvorStabla Stablo;
typedef struct CvorStabla* stablo;
struct CvorStabla {

	char ime[N];
	stablo PD;
	stablo NB;
};

struct stog;
typedef struct stog Stog;
typedef struct stog* position;

struct stog {
	stablo s;
	position next;
};

int ispis(stablo);
int md(stablo);
stablo Cd(stablo,char*);
int push(position, stablo);
stablo pop(position p);


int main(void) {
	Stablo Direktorij;
	stablo Temp = NULL;
	int x = 0;
	char* a=NULL;
	char b = { "/0" };

	Direktorij.PD = NULL;
	Direktorij.NB = NULL;

	Temp = &Direktorij;





	printf("Unesi ime Direktorija: \n");
	scanf(" %s", Direktorij.ime);

	ispis(&Direktorij);
	while (x != 5)
	{

		scanf("%d", &x);
		if (x == 1)
		{
			md(Temp);
		}
		else if (x == 3)
		{
			
			printf("Unesi ime direktorija kojeg trazis: ");
			scanf(" %s", b);
			a = &b;
			Temp = Cd(&Direktorij,a);
			if (Temp == NULL)
			{
				printf("ERROR data not found please try again\n");
				Temp = &Direktorij;
			}

			else
			{
				ispis(Temp);
			}
		}
		else if (x == 4)
		{
			ispis(&Direktorij);
		}
	}
	return 0;
}

int ispis(stablo p)
{
	stablo q = NULL;
	q = (stablo)malloc(sizeof(Stablo));

	printf("- %s", p->ime);
	//while (p->PD != NULL || p->NB != NULL)
	{
		if (p->PD != NULL)
		{
			q = p->PD;
			printf("\n");
			ispis(q);

		}
		if (p->NB != NULL)
		{
			q = p->NB;
			printf("\n");
			ispis(q);
		}
	}

	return 0;
}

int md(stablo p)
{
	stablo q = NULL;
	q = (stablo)malloc(sizeof(Stablo));

	printf("Unesite ime : ");
	scanf(" %s", q->ime);
	q->NB = p->PD;
	p->PD = q;

	q->PD = NULL;
	return 0;
}

stablo Cd(stablo p, char *a)
{
	stablo temp = NULL;
	Stog q;



	if (strcmp(p->ime, a) == 0)
		return temp;


	if (p->PD != NULL)
	{
			//push(&q, temp);
			temp = Cd(p->PD,a);
			if (temp != NULL)
				return temp;
	}
	if (p->NB != NULL)
	{
			temp = Cd(p->NB,a);
			if (temp != NULL)
				return temp;
	}

	return temp;
}

int push(position p, stablo x)
{
	position q = NULL;

	q = (position)malloc(sizeof(Stog));

	q->s = x;
	q->next = p->next;
	p->next = q;

	return 0;
}

stablo pop(position p)
{
	position q = NULL;
	stablo x;
	q = (position)malloc(sizeof(Stog));
	x = (stablo)malloc(sizeof(Stablo));

	q = p->next;
	x = p->next->s;
	p->next = p->next->next;
	free(q);

	return x;
}
