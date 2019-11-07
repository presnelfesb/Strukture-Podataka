#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define duzina 1024

struct _polinom;
typedef struct _polinom POLINOM;
typedef struct _polinom* position;

struct _polinom {
	int koef;
	int ekspo;
	position next;
};

int stvori(position*);
int ucitajdat(position);
int ispisi(position);
int zbroji(position, position, position);
int pomnozi(position, position, position);

int main(void)
{
	POLINOM p1, p2, z, u;
	int k = 0;

	p1.next = NULL;
	p2.next = NULL;
	z.next = NULL;
	u.next = NULL;

	printf("Polinom 1: ");
	k = ucitajdat(&p1);
	if (k == -1) return -1;
	ispisi(p1.next);

	printf("\nPolinom 2: ");
	k = ucitajdat(&p2);
	if (k == -1) return -1;
	ispisi(p2.next);

	printf("\nZbroj dva polinoma je: ");
	zbroji(p1.next, p2.next, &z);
	ispisi(z.next);

	printf("\nUmnozak dva polinoma je: ");
	pomnozi(p1.next, p2.next, &u);
	ispisi(u.next);

	return 0;
}

int stvori(position* p)
{
	position q = NULL;

	*p = (position)malloc(sizeof(POLINOM));
	if (*p == NULL) return -1;

	q = *p;
	q->next = NULL;

	return 0;

}

int ucitajdat(position p)
{
	position q = NULL;
	char* ime = NULL;
	FILE* fp = NULL;
	int k = 0;

	ime = (char*)malloc(duzina * sizeof(char));
	if (ime == NULL) return -1;
	memset(ime, '\0', duzina);

	printf("Unesite ime datoteke: ");
	scanf(" %s", ime);

	if (strchr(ime, '.') == NULL)
		strcat(ime, ".txt");

	fp = fopen(ime, "r");
	if (fp == NULL)
	{
		printf("Nije otovrena datoteka.");
		return -1;
	}

	while (!feof(fp))
	{
		k = stvori(&q);
		
		fscanf(fp," %d %d", &q->koef, &q->ekspo);
		while (p->next != NULL && p->next->ekspo > q->ekspo)
			p = p->next;
		if (p->next != NULL && p->next->ekspo == q->ekspo)
		{
			p->next->koef = p->next->koef + q->koef;
			free(q);
			if (p->next->koef == 0)
			{
				q = p->next;
				p->next = q->next;
				free(q);
			}
		}
		else
		{
			q->next = p->next;
			p->next = q;
		}
	}
	fclose(fp);
	return 0;
}


int ispisi(position p)
{
	int k = 1;
	while (p != NULL)
	{
		if (k == 1)
		{
			printf("%dx^%d ", p->koef, p->ekspo);
			k = 0;
		}
		else if (p->koef > 0)
			printf("+%dx^%d ", p->koef, p->ekspo);
		else if (p->koef < 0)
			printf("%dx^%d ", p->koef, p->ekspo);
		else
			continue;

		p = p->next;
	}
	return 0;
}

int zbroji(position p1, position p2, position z)
{
	int k = 0;
	position q = NULL;
	position temp = NULL;

	while (p1 != NULL && p2 != NULL)
	{
		k = stvori(&q);
		if (k == -1)
			return -1;
		if (p1->ekspo > p2->ekspo)
		{
			q->ekspo = p1->ekspo;
			q->koef = p1->koef;
			p1 = p1->next;
		}
		else if (p2->ekspo > p1->ekspo)
		{
			q->ekspo = p2->ekspo;
			q->koef = p2->koef;
			p2 = p2->next;
		}
		else
		{
			q->ekspo = p1->ekspo;
			q->koef = p1->koef + p2->koef;
			p1 = p1->next;
			p2 = p2->next;
		}
		q->next = z->next;
		z->next = q;
		z = q;
	}

	if (p1 == NULL)
		temp = p2;
	else
		temp = p1;

	while (temp != NULL)
	{
		k = stvori(&q);
		if (k == -1)
			return -1;
		q->ekspo = temp->ekspo;
		q->koef = temp->koef;
		q->next = z->next;
		z->next = q;
		z = q;
		temp = temp->next;
	}
	return 0;

}

int pomnozi(position p1, position p2, position u)
{
	int k = 0;
	position q = NULL;
	position temp = NULL;
	position i = NULL;
	position j = NULL;

	i = p1;
	while (i != NULL)
	{
		j = p2;
		while (j != NULL)
		{
			k = stvori(&q);
			if (k == -1)
			{
				printf("memorija nije alocirana");
				return -1;
			}
			q->ekspo = i->ekspo + j->ekspo;
			q->koef = i->koef * j->koef;
			temp = u;

			while ((temp->next != NULL) && (temp->next->ekspo > q->ekspo))
				temp = temp->next;
			if (temp->next != NULL && temp->next->ekspo == q->ekspo)
			{
				temp->next->koef += q->koef;
				free(q);
				if (temp->next->koef == 0)
				{
					q = temp->next;
					temp->next = q->next;
					free(q);
				}

			}
			else
			{
				q->next = temp->next;
				temp->next = q;
			}
			j = j->next;
		}
		i = i->next;
	}
	return 0;
}
