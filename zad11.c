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
	Lista* hashliste;// pokazivaci na pokazivace koristimo ih kako bi imali redove listi u hash tablici
};


Hashtab Tablica(int);
int Kljuc(int, char*);
int odabir();



int main(void)
{
	int VelTab = 0;
	int x = 0;
	int i = 0;
	char* temp = NULL;
	char b[N] = { "" };
	Hashtab H = NULL;
	Lista coek = NULL;



	VelTab = 11;
	H = Tablica(VelTab);

	while (x != 3)
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
				strcpy(H->hashliste[i]->prezime, temp);//briga ovdje je greska nez kako dalje lol sretno
				printf(" %s", H->hashliste[i]->prezime);
			}
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

		scanf("%d", &x);
		if (x < 1 || x>3)
			printf("To nije opcija");
	}

	return x;
}
