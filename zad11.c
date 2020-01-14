#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

typedef struct cvor* position; //koristimo za micanje po vezanim listama u retcima hash tablice
typedef struct cvor* Lista; //pokazivac na cvor (prvi element)
typedef struct HashT* Hashtab; //pokazivac na Hashtablicu

struct cvor {

	char ime[N];
	char prezime[N];
	int MB;

	position next;

};

struct HashT {
	int VelT;
	Lista* hashliste;// pokazivaci na koji pokazuje na podatke tipe Lista (koji je pokazivac koji koristimo u prvoj strukturi)
};


Hashtab Tablica(int);
int Kljuc(int, char*);
position trazi(Hashtab);
int odabir();
int ispis(Hashtab);



int main(void)
{
	int VelTab = 0;
	int x = 0;
	int i = 0;
	char* temp = NULL;
	char b[N] = { "" };
	Hashtab H = NULL;
	Lista coek = NULL;
	Lista p = NULL;



	VelTab = 11;
	H = Tablica(VelTab);

	while (x != 4)
	{
		x = odabir();
		
		if (x == 1)
		{
			printf("Unesi prezime:");
			scanf(" %s", b);
			temp = &b;
			i = Kljuc(VelTab, temp);
			coek = (Lista)malloc(sizeof(struct cvor));
			if (coek = NULL)
			{
				printf("GRESKA U ALOKACIJI MEMORIJE");
				exit(-1);
			}
			if (H->hashliste[i] == NULL)
			{
				coek->next = H->hashliste[i];
				H->hashliste[i] = coek;
				strcpy(coek->prezime, b);
				printf("\nUnesi Ime: ");
				scanf(" %s", b);
				strcpy(coek->ime, b);
				printf("\nUnesi MB: ");
				scanf("%d", coek->MB);
				}
			if (H->hashliste[i] != NULL)
			{
				strcpy(coek->prezime, b);
				printf("\nUnesi Ime: ");
				scanf(" %s", b);
				strcpy(coek->ime, b);
				printf("\nUnesi MB: ");

				p = H->hashliste[i];
				while (strcmp(p->prezime, coek->prezime) < 0)
					p = p->next;
				coek->next = p->next;
				p->next = coek;
			}
		}

		if (x == 2)
		{
			p = trazi(H);
			if(p!=NULL)
				{
					printf("Zelite li ispisati MB?\n");
					scanf(" %s", b);
					if (strcmp(b, "DA") == 0 || strcmp(b, "Da") == 0 || strcmp(b, "da") == 0 || strcmp(b, "dA") == 0)
						printf("MB=", p->MB);
				}
		}

		if (x == 3)
		{
			ispis(H);
		}
	}

	return 0;
}

Hashtab Tablica(int VelTab)
{
	Hashtab H = NULL;
	int i = 0;

	H = (Hashtab)malloc(sizeof(struct HashT));
	if (NULL == H)
	{
		printf("GRESKA U ALOKACIJI MEMORIJE");
		exit(-1);
	}
	H->VelT = VelTab;

	H->hashliste = (Lista*)malloc(sizeof(Lista) * H->VelT);
	if (H->hashliste == NULL)
	{
		printf("GRESKA U ALOKACIJI MEMORIJE");
		exit(-1);
	}

	for (i = 0;i < VelTab;i++)
	{
		H->hashliste[i] = NULL;
	}

	return H;
}

int Kljuc(int VelTab, char* Prez)
{
	int i = 0;
	int temp = 0;

	for (i = 0;i < 5;i++)
		temp += *Prez++;
	return temp % VelTab;
}

int odabir()
{
	int x = 0;
	while (x < 1 || x>3)
	{
		printf("Unesi naredbu koju zelis:\n");
		printf("1.Unos\n");
		printf("2.Trazi\n");
		printf("3.Ispis\n");
		printf("4.Izlaz\n");

		scanf("%d", &x);
		if (x < 1 || x>3)
			printf("To nije opcija");
	}

	return x;
}

position trazi(Hashtab H)
{
	char a[N] = { "" };
	char* t;
	Lista x = NULL;
	int i = 0;

	printf("\n Unesi trazeno prezime: ");
	scanf(" %s", a);
	t = &a;

	i = Kljuc(H->VelT, t);

	x = H->hashliste[i];
	while (strcmp(x->prezime, t) !=0 )
		x = x->next;

	if (x == NULL)
		printf("Nema tog coeka");

	return x;
}

int ispis(Hashtab H)
{
	int i = 0;
	Lista p = NULL;
	
	for (i = 0;i < 11;i++)
	{
		p = H->hashliste[i];
		while (p != NULL)
		{
			p = p->next;
			printf("%s %s %d", p->ime, p->prezime, p->MB);
		}
	}

	return 0;
}
