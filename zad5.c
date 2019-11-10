#define CRT_SECURE_NO_WARNING

#include <stdio.h>
#include <stdlib.h>

struct lista;
typedef struct lista Lista;
typedef struct lista *position;

struct lista {
	int clan;
	position next;
};

int stvori(position*);
int unos(position);
int ispis(position);
int unija(position,position,position);
int presjek(position, position, position);

int main(void)
{
	Lista l1, l2, u, p;
	int b = 0;

	l1.next = NULL;
	printf("Lista 1: ");
	unos(&l1);
	printf("Lista 1: ");
	ispis(&l1);

	l2.next = NULL;
	printf("\nLista 2: ");
	unos(&l2);
	printf("\nLista 2: ");
	ispis(&l2);
	
	u.next = NULL;
	printf("\nUnija liste 1 i 2 je: ");
	unija(&l1, &l2, &u);
	ispis(&u);

	p.next = NULL;
	printf("\nPresjek liste 1 i 2 je: ");
	b=presjek(&l1, &l2, &p);
	if (b == 0)
		printf("prazan skup\n");
	else
		ispis(&p);

	return 0;
}


int unos(position p)
{
	int n = 0, i = 0;
	position q = NULL, temp = NULL;

	temp = p;

	while (n == 0)
	{
		printf("Koliko clanova liste zelite unijeti: ");
		scanf("%d", &n);
	}


	for (i = 0; i < n; i++)
	{
		stvori(&q);
		printf("Unesite %d. clan: ", i + 1);
		scanf("%d", &q->clan);

		while (p->next != NULL && q->clan > p->next->clan)
			p = p->next;

		if (p->next != NULL && q->clan == p->next->clan)
			continue;
		else
		{
			q->next = p->next;
			p->next = q;
		}

		p = temp;
	}
	return 0;
}


int stvori(position* p)
{
	*p = (position*)malloc(sizeof(Lista));
	return 0;
}

int ispis(position p)
{
	p = p->next;

	printf("%d", p->clan);

	p = p->next;
	while (p != NULL)
	{
		printf(", %d", p->clan);
		p = p->next;
	}
	printf("\n");

	return 0;
}

int unija(position l1, position l2, position u)
{
	position q=NULL, temp=NULL;
	l1 = l1->next;
	l2 = l2->next;

	while (l1 != NULL && l2 != NULL)
	{
		stvori(&q);
		if (l1->clan < l2->clan)
		{
			q->clan = l1->clan;
			l1 = l1->next;
		}
		else if (l2->clan < l1->clan)
		{
			q->clan = l2->clan;
			l2 = l2->next;
		}
		else
		{
			q->clan = l1->clan;
			l1 = l1->next;
			l2 = l2->next;
		}
		q->next = u->next;
		u->next = q;
		u = u->next;
	}

	if (l1 != NULL)
		temp = l1;
	else
		temp = l2;

	while (temp != NULL)
	{
		stvori(&q);
		q->clan = temp->clan;

		q->next = u->next;
		u->next = q;
		u = u->next;

		temp = temp->next;

	}
	return 0;
}

int presjek(position l1, position l2, position p)
{
	int b = 0;
	position q = NULL;
	l1 = l1->next;
	l2 = l2->next;

	while (l1 != NULL && l2 != NULL)
	{
		stvori(&q);
		if (l1->clan < l2->clan)
			l1 = l1->next;

		else if (l2->clan < l1->clan)
			l2 = l2->next;

		else 
		{
			q->clan = l1->clan;
			l1 = l1->next;
			l2 = l2->next;

			q->next = p->next;
			p->next = q;
			p = p->next;
			b = b + 1;
		}
		
	}
	return b;
}
