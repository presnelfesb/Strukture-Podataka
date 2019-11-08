#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N 20
#define duzina 1024

typedef struct {
	char ime[N];
	char prezime[N];
	int br;
} _student;


int brojac(char*);
int unos(char*, _student*, int);
int ispis(_student*,int, int);

int main(void)
{
	int n = 0;
	int max = 0;
	char* fp = NULL;
	_student *t=NULL;

	fp = (char*)malloc(duzina * sizeof(char));
	if (fp == NULL) return -1;
	memset(fp,'\0', duzina);

	printf("Unesite naziv datoteke za citanje\n");
	scanf(" %s",fp);

	if (strrchr(fp, '.') == NULL)
		strcat(fp, ".txt");
	
	n = brojac(fp);
	if (n > 0)
	{
		t = (_student*)malloc(n * sizeof(_student));
		if (t == NULL) return -1;
		max = unos(fp, t, n);
		ispis(t, n, max);
	}
	else
	{
		printf("U datoteci nisu pronađeni zapisi");
	}
	return 0;
}

int brojac(char *naziv)
{
	FILE *fo = NULL;
	int n = 0;
	char line[duzina] = { 0 };

	fo = fopen(naziv, "r");
	if (!fo)
	{
		printf("Datoteka nije otvorena");
		return -1;
	}

	while (!feof(fo))
	{
		fgets(line, duzina, fo);
		if (strlen(line) == 0) continue;
		n++;
	}
	fclose(fo);
	return n;
}

int unos(char* naziv, _student *t, int n)
{
	int i = 0;
	int bmax = 0;
	FILE *r = NULL;
	r = fopen(naziv, "r");
	for (i = 0; i < n; i++)
	{
		fscanf(r, "%s %s %d", t[i].ime, t[i].prezime, &t[i].br);
		if (t[i].br > bmax)
			bmax = t[i].br;
	}
	fclose(r);
	return bmax;
}

int ispis(_student *t, int n, int max)
{
	int i = 0;

	printf("\t%15s \t%15s \t%5s \t%7s\n","Ime","Prezime","Bod","RelBod");
	for (i = 0; i < n; i++)
	{
		printf("\t%15s \t%15s \t%5d \t%6.2f\n", t[i].ime, t[i].prezime, t[i].br, ((float)t[i].br / max) * 100);
	}
	return 0;
}
