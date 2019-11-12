#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct stog;
typedef struct stog *position;
typedef struct stog Stog;

struct stog{
	int el;
	position next;
};

int push(position,int);
int pop (position);
int odabir();
int ispis(position);
int popr (position );


int main ()
{
	Stog s;
	int k=0;
	int x=0;
	int l=0;

	s.next=NULL;
	srand(time(0));
	printf("Unesi želiš li raditi sa stogom ili redom:\n 1.Stog\n 2.Red ");
	scanf(" %d",&l);
	if(l!=1 && l!=2)
	{
		printf("Niste unijeli ispravan odabir!");
		return 0;
	}
	
	while(k!=4)
	{
		k=odabir();
		
		if(k==1){
			printf("Generirani broj je: ");
			x=rand() % 90 +10;
			printf("%d",x);
			push(&s,x);
		}
		
		else if(k==2){
			if(l==1)
				printf("x=%d ",pop(&s));
			else
				printf("x=%d ",popr(&s));
		}
		else if(k==3){
			ispis(&s);
		}

		else if(k==4)
			continue;
		
		else
			printf("Niste unijeli ispravan broj"); 

	}
	return 0;
}

int odabir()
{
	int i=0;
	printf("\nOdaberi broj funkcije:\n");
	printf(" 1.push\n 2.pop\n 3.ispis\n 4.izlaz\n");
	scanf("%d",&i);
	return i;
}


int push(position p,int x)
{
	position q=NULL;

	q=(position) malloc(sizeof(Stog));

	q->el=x;
	q->next=p->next;
	p->next=q;

	return 0;
}

int pop (position p)
{
	position q;
	q=(position)malloc(sizeof(Stog));

	q->el=p->next->el;
	p->next=p->next->next;

	return q->el;
}

int popr (position p)
{
	position q;
	q=(position)malloc(sizeof(Stog));
	while(p->next->next!=NULL)
		p=p->next;

	q->el=p->next->el;
	p->next=p->next->next;

	return q->el;
}

int ispis(position p)
{
	p=p->next;
	while(p!=NULL)
	{
		printf("%d ",p->el);
		p=p->next;
	}
	return 0;
}
