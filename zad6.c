#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 

typedef struct stog Stog;
typedef struct stog* position;
struct stog {
	int el;
	position next;
};

int push(position);
int pushr(position);
int pop(position);
int opcije();
int odabir(position);
int pick();

int main()
{
	Stog s;
	s.next = NULL;

	odabir(&s);


	return 0;
}



int odabir(position p)
{
	int x = 0;
	int a = 0;

	a = pick();
	
	while (x != 3)
	{
		x = opcije();

		switch (x)
		{
		case 3: break;
		case 2: {
			pop(&p);
			break;
		}
		case 1: {
			if(a==1)
				push(&p);
			else {
				pushr(&p);
			}
			break;
		}
		}
	}
	return 0;

}

int pick()
{
	int x = 0;
	while (x != 1 && x != 2)
	{
		printf("Izaberite:\n 1.Stog \n 2.Red\n\n");
		scanf("%d", &x);

		if (x < 1 || x>2)
			printf("KRIVI ODABIR\n");
	}

	return x;
}

int opcije()
{
	int x = 0;




	printf("Odaberite opciju koju zelite izabrati:\n ");
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Izlaz\n");

	scanf("%d", &x);
	if (x == 0 || x > 3 || x < 1)
		printf("KRIVI BROJ\n\n");


	return x;
}

int push(position p)
{
	position q = NULL;
	int x = 0;
	srand(time(0));

	x = rand() % 90 + 10;

	q = (position)malloc(sizeof(Stog));
	q->next = NULL;
	q->next = p->next;
	p->next = q;
	q->el = x;

	return 0;
}

int pushr(position p)
{
	position q = NULL;
	int x = 0;
	srand(time(0));

	x = rand() % 90 + 10;

	while (p->next != NULL)
		p = p->next;

	q = (position)malloc(sizeof(Stog));
	q->next = p->next;
	p->next = q;
	q->el = x;

	return 0;
}


int pop(position p)
{
	position temp = NULL;

	temp= (position)malloc(sizeof(Stog));
	temp->next = NULL;
	
	temp = p->next;
	if (temp != NULL)
	{
		p->next = temp->next;
		printf(" Pop-an clan je %d\n", temp->el);

		free(temp);
	}
	else
		printf("STOG JE PRAZAN");
	return 0;
}
