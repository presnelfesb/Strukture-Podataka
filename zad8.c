#define _CRT_SECURE_NO_WARNINGS

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

int ispis(stablo);
int md(stablo);
stablo Cd(stablo);

int main(void) {
	Stablo Direktorij;
	stablo Temp = NULL;
	int x = 0;
	
	Direktorij.PD = NULL;
	Direktorij.NB = NULL;

	

	

	printf("Unesi ime Direktorija: \n");
	scanf(" %s", Direktorij.ime);

	ispis(&Direktorij);
	while (x != 5)
	{
		
		scanf("%d", &x);
		if (x == 1)
		{
			md(&Direktorij);
		}
		if (x == 3)
		{
			Temp = Cd(&Direktorij);
			if (Temp == NULL)
				printf("ERROR data not found please try again\n");
			else
			{
				Temp = (stablo)malloc(sizeof(Stablo));
				ispis(Temp);
			}
		}
	}
	return 0;
}

int ispis(stablo p)
{
	stablo q = NULL;
	q = (stablo)malloc(sizeof(Stablo));
	
	printf("- %s", p->ime);
	while (p->PD != NULL || p->NB != NULL)
	{
		if (p->PD != NULL)
		{
			q = p->PD;
			ispis(&q);
		}
		if (p->NB != NULL)
		{
			q = p->NB;
			ispis(&q);
		}
	}

	return 0;
}

int md(stablo p)
{
	stablo q = NULL;
	q = (stablo)malloc(sizeof(Stablo));
	q->NB = p->PD->NB;
	q->PD = NULL;
	return 0;
}

stablo Cd(stablo p)
{
	stablo temp = NULL;
	char a[N] = {"\0"};

	

	if (p->PD != NULL)
	{
		if (strcmp(p->ime, a) == 0)
			return temp;
		else
			temp = Cd(p->PD);
	}
	if (p->NB != NULL)
	{
		if (strcmp(p->ime, a) == 0)
			return temp;
		else
			temp = Cd(p->NB);
	}
	
	return temp;
}
