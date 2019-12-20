#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 1024
typedef struct stablo Stablo;
typedef struct stablo *position;



struct stablo {
	position LD;
	position RD;
	char z[N];
};

int unos(char*, position);
int ispis(stablo);

int main()
{
	Stablo s;
	s.LD = NULL;
	s.RD = NULL;

	char*ime = NULL;
	
	ime = (char*)malloc(sizeof(char)*M);
	printf("Unesite naziv datoteke: ");
	scanf(" %s", ime);

	unos(ime, &s);
	ispis(&s);

	return 0;
}

int unos(char *ime, position p)
{
	FILE *fp = NULL;

	fp = fopen(ime, "r");

}
