#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

typedef struct CvorStabla Stablo;
typedef struct CvorStabla* stablo;
struct CvorStabla {

	char ime[N];
	stablo PD;
	stablo NB;
	int dubina;
};

struct stog;
typedef struct stog Stog;
typedef struct stog* position;

struct stog {
	stablo s;
	position next;
};

int odabir();
int ispis(stablo);
int ispisD(stablo,position);
int md(stablo);
stablo Cd(stablo, position, char*);
stablo CdDir(stablo, position);
int push(position, stablo);
stablo pop(position p);


int main(void) {
	Stablo Direktorij;
	stablo Temp = NULL;
	int x = 0;
	char* a = NULL;
	char b[N] = { "/0" };
	Stog memorija;
	
	memorija.next = NULL;
	memorija.s = NULL;

	Direktorij.PD = NULL;
	Direktorij.NB = NULL;
	Direktorij.dubina = 0;

	Temp = &Direktorij;
	





	printf("Unesi ime Direktorija: \n");
	scanf(" %s", Direktorij.ime);

	push(&memorija, &Direktorij);

	while (x != 5)
	{
		printf("Trenutno se nalazite u %s", Temp->ime);
		x=odabir();
		
		if (x == 1)
		{
			md(Temp);
		}
		
		else if (x == 2)
		{
			Temp= CdDir(Temp, &memorija);
		}
		
		else if (x == 3)
		{

			printf("Unesi ime direktorija kojeg trazis: ");
			scanf(" %s", b);
			a = &b;
			Temp = Cd(Temp,&memorija, a);
			if (Temp == NULL)
			{
				printf("ERROR data not found please try again\n");
				Temp = &Direktorij;
			}

			else
			{
				ispisD(Temp,&memorija);
				printf("\n");
				system("pause");
				}
		}
		else if (x == 4)
		{
			ispis(&Direktorij);
			printf("\n");
			system("pause");
		}
		system("cls");
	}
	return 0;
}


int odabir()
{
	int x = 0;

	while (x < 1 || x>5)
	{
		printf("\nUnesite commandu koju zelite: \n");
		printf("  1.MD \n");
		printf("  2.CD DIR\n");
		printf("  3.CD\n");
		printf("  4.Ispis\n");
		printf("  5.Izlaz\n\n\n");

		scanf("%d", &x);

		if (x < 1 || x>5)
			printf("To nije opcija\n");
	}
	return x;
	

}


int ispis(stablo p)
{
	stablo q = NULL;
	int i = 0;
	q = (stablo)malloc(sizeof(Stablo));
	
	
	
	while (i != p->dubina)
	{
		printf("  ");
		i++;
	}

	printf("- %s", p->ime);
	
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

	return 0;
}

int ispisD(stablo p,position mem)
{
	stablo q = NULL;
	int i = 0;
	q = (stablo)malloc(sizeof(Stablo));
	
	printf("- %s", p->ime);

	if (p->PD != NULL)
	{
		q = p->PD;
		printf("\n");
		ispis(q);
	}
}

int md(stablo p)
{
	stablo q = NULL;
	q = (stablo)malloc(sizeof(Stablo));

	printf("Unesite ime : ");
	scanf(" %s", q->ime);
	q->NB = p->PD;
	p->PD = q;
	q->dubina = p->dubina + 1;

	q->PD = NULL;
	return 0;
}

stablo Cd(stablo p, position mem, char* a)
{
	stablo Temp = NULL;
	if (p->PD != NULL)
		Temp = p->PD;
	if (strcmp(a, Temp->ime) == 0)
	{
		push(mem,Temp);
		return Temp;
	}
	else
	{
		while (Temp->NB != NULL)
		{
			Temp = Temp->NB;
			if (strcmp(a, Temp->ime) == 0) 
			{
				push(mem, Temp);
				return Temp;
			}
		}
	}
	
	
	
	
	
	//stablo temp = NULL;
	//Stog q;



	//if (strcmp(p->ime, a) == 0)
		//return temp;


	//if (p->PD != NULL)
	//{											//POKUSAJ PRONALASKA BILO KOJEG DIREKTORIJA U STABLU 
		//push(&q, temp);						//NE RADI PITAJ ZASTO.
		//temp = Cd(p->PD, a);
		//if (temp != NULL)
		//	return temp;
	//}
	//if (p->NB != NULL)
	//{
	//	temp = Cd(p->NB, a);
	//	if (temp != NULL)
	//		return temp;
	//}

	//return temp;

}

stablo CdDir(stablo s, position p)
{
	stablo Temp = NULL;
	Temp = pop(p);

	return Temp;
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
