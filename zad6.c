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
int pop(position);
int opcije();
int odabir(position);

int main()
{
	Stog s;
	s.next = NULL;

	odabir(&s);

	

}

int opcije()
{
	int x = 0;
	
	while (x!=3)
	{

		printf("Odaberite opciju koju zelite izabrati:\n ");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Izlaz\n");

		scanf("%d", &x);
		if (x == 0 || x > 3 || x < 1)
			printf("KRIVI BROJ\n\n");
		
	}
	return x;
}

int odabir(position p)
{
	int x = 0;
	int a = 0;

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
			printf("Unesi clan koji zelis staviti na stog\n");
			scanf("%d", &a);
			push(&p);
			break;
		}
		}
	}
	return 0;

}

int push(position p)
{
	position q = NULL;
	int x = 0;
	srand(time(0));

	x = rand() % 90 + 10;
	
	q = (position)malloc(sizeof(Stog));
	q->next = p->next;
	p->next = q;
	p->el =x ;

	return 0;
}

int pop(position p)
{
	position temp = NULL;

	temp = p->next;
	if (temp != NULL)
	{
		p->next = temp->next;
		printf("%d", temp->el);

		free(temp);
	}
	else
		printf("STOG JE PRAZAN");
	return 0;
}
