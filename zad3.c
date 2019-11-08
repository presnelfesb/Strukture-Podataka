#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20
#define duzina 1024

struct student;
typedef struct student  _STUDENT;
typedef struct student *position;

struct student {
	char ime[N];
	char prezime[N];
	int godina;
	position next;

};
int odabir();
int stvori(position);
int unesi(position);
int ispis(position);
int dodajElp(position);
int dodajElk(position);
position trazi(position);
int brisi(position);
position traziPret(position);
int UnosIza(position);
int UnosIspred(position);
int sortiraj(position);
int ucitajdat(position);
int isprintajdat(position);
int sortiraniunos(position);

int main(void)
{
	_STUDENT head;
	int k = 0;
	int j = 0;
	position studentF = NULL;
	head.next = NULL;


	while (k != 12)
	{
		k = 0;
		k = odabir();

		if (k == 1)
		{
			dodajElp(&head);
		}
		else if (k == 2)
		{
			ispis(head.next);
		}
		else if (k == 3)
		{
			dodajElk(&head);
		}
		else if (k == 4)
		{
			studentF = trazi(head.next);
			if (studentF != NULL)
				printf("Trazeni student je: %s %s %d\n", studentF->ime, studentF->prezime, studentF->godina);
			else printf("Nije pronaden.\n");
		}
		else if (k == 5)
		{
			Brisi(&head);
		}
		else if (k == 6)
		{
			UnosIza(&head);
		}
		else if (k == 7)
		{
			UnosIspred(&head);
		}
		else if (k == 8)
		{
			sortiraj(&head);
		}
		else if (k == 9)
		{
			ucitajdat(&head);
		}
		else if (k == 10)
		{
			isprintajdat(head.next);
		}
		else if (k == 11)
		{
			sortiraniunos(&head);
		}
		else if (k == 12)
		{
			continue;
		}
		else
			printf("Pogresan izbor\n");
	}
	return 0;
}

int odabir()
{
	int n = 0;

	printf("Odaberite redni broj funkcije koju zelite koristiti\n");
	printf("1. Dodaj novi element na po?etak liste\n");
	printf("2. Ispis\n");
	printf("3. Dodaj novi element na kraj\n");
	printf("4. Pronadi element u listi(po prezimenu)\n");
	printf("5. Brisi element iz liste\n");
	printf("6. Unos elementa iza\n");
	printf("7. Unos elementa ispred\n");
	printf("8. Sortiraj listu po prezimenu\n");
	printf("9. Ucitaj iz datoteke\n");
	printf("10.Isprintaj datoteku\n");
	printf("11. Sortirani unos\n");
	printf("12. Izadi iz programa\n");


	scanf(" %d", &n);
	return n;
}

int stvori(position *head)
{
	position q = NULL;

	*head = (position)malloc(sizeof(_STUDENT));
	if (*head == NULL) return -1;

	q = *head;
	q->next = NULL;

	return 0;
}

int unesi(position p)
{
	if (p == NULL) return -1;

	printf("Unesite ime, prezime i godinu rodenja:\n");
	scanf(" %s %s %d", p->ime, p->prezime, &p->godina);

	return 0;
}

int dodajElp(position p)
{
	position q = NULL;
	int k = -1;

	k = stvori(&q);
	if (k == -1)
	{
		printf("Greska");
		return -1;
	}

	k = unesi(q);
	if (k == -1)
	{
		printf("Greska");
		return -1;
	}

	q->next = p->next;
	p->next = q;

	return 0;
}

int ispis(position p)
{
	if (p == NULL)
		printf("Lista je prazna\n");
	else
	{
		printf("Lista:\n");
		while (p != NULL)
		{
			printf("%s %s %d\n", p->ime, p->prezime, p->godina);
			p = p->next;
		}
	}
	return 0;
}

int dodajElk(position p)
{
	if (p == NULL) return NULL;

	while (p->next != NULL)
		p = p->next;

	return dodajElp(p);
}

position trazi(position p)
{
	char* prez = NULL;


	prez = (char*)malloc(duzina * sizeof(char));
	if (prez == NULL) return NULL;
	memset(prez, '\0', duzina);

	printf("Unesite prezime: ");
	scanf(" %s", prez);

	while ((p != NULL) && strcmp(p->prezime, prez) != 0)
		p = p->next;
	free(prez);

	return p;
}

int Brisi(position p)
{
	position temp = NULL;
	p = traziPret(p);

	if (p == NULL)
	{
		printf("Trazeno prezime se ne nalazi u listi.");
		return -1;
	}

	else
	{
		temp = p->next;
		p->next = p->next->next;
		free(temp);

	}
	return 0;
}


position traziPret(position p)
{
	char* prez = NULL;

	prez = (char*)malloc(duzina * sizeof(char));
	if (prez == NULL)
		return -1;
	memset(prez, '\0', duzina);

	printf("Unesite prezime: ");
	scanf(" %s", prez);

	while (p->next != NULL && strcmp(p->next->prezime, prez) != 0)
		p = p->next;

	if (p->next == NULL)
		return NULL;

	free(prez);

	return p;

}

int UnosIza(position p)
{
	p = trazi(p);
	if (p == NULL)
		return -1;
	return dodajElp(p);
}

int UnosIspred(position p)
{
	p = traziPret(p);
	if (p == NULL)
		return -1;
	return dodajElp(p);
}

int sortiraj(position p)
{
	position j = NULL;
	position prev_j = NULL;
	position temp = NULL;
	position end = NULL;

	while (p->next != end)
	{
		prev_j = p;
		j = p->next;
		while (j->next != end)
		{
			if (strcmp(j->prezime, j->next->prezime) > 0)
			{
				temp = j->next;
				prev_j->next = temp;
				j->next = temp->next;
				temp->next = j;

				j = temp;
			}
			prev_j = j;
			j = j->next;
		}
		end = j;
	}
	return 0;
}

int ucitajdat(position p)
{
	char* ime = NULL;
	FILE* fp = NULL;
	position q = NULL;
	int k = 0;



	ime = (char*)malloc(duzina * sizeof(char));
	if (ime == NULL) return -1;
	memset(ime, '\0', duzina);

	printf("Unesite naziv datoteke: ");
	scanf(" %s", ime);

	if (strchr(ime, '.') == NULL)
		strcat(ime, ".txt");

	fp = fopen(ime, "r");
	if (fp == NULL)
	{
		printf("Datoteka nije otvorena");
		return -1;
	}
	while (!feof(fp))
	{
		k = stvori(&q);
		if (k) break;
		fscanf(fp, " %s %s %d", q->ime, q->prezime, &q->godina);
		q->next = p->next;
		p->next = q;
	}
	fclose(fp);
	return 0;
}


int isprintajdat(position p)
{
	FILE* fp = NULL;
	char *ime = NULL;

	ime = (char*)malloc(duzina * sizeof(char));
	if (ime == NULL)
		return -1;

	memset(ime, '\0', duzina);

	printf("Unesite datoteku za upisivanje: ");
	scanf("%s", ime);

	if (strchr(ime, '.') == NULL)
		strcat(ime, ".txt");

	fp = fopen(ime, "w");
	if (fp == NULL)
	{
		printf("Datoteka nije otvorena");
		return -1;
	}

	while (p != NULL)
	{
		fprintf(fp, "%s %s %d", p->ime, p->prezime, p->godina);
		p = p->next;

		if (p != NULL)
			fprintf(fp, "\n");

	}
	fclose(fp);
	return 0;
}

int sortiraniunos(position p)
{
	position q = NULL;
	int k = -1;

	k = stvori(&q);
	k = unesi(q);

	while (p->next!=NULL && strcmp(q->prezime, p->next->prezime) > 0 )
		p = p->next;

	q->next = p->next;
	p->next = q;
	

	return 0;

}
