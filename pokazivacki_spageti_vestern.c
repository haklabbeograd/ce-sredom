#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct ListaTeksta
{
    char tekst[255];
    struct ListaTeksta * sledeci;
}ListaTeksta;



typedef struct titl
{
    int redni_broj;
    long int pocetak;//ms
    long int kraj;//ms
    ListaTeksta * pocetak_titla;
    ListaTeksta * kraj_titla;
}Titl;

typedef struct ListaTitlova
{
    Titl * theTitl;
    struct ListaTitlova * sledeci;
}ListaTitlova;

ListaTeksta * pocetak = NULL;
ListaTitlova * pocetak_titlova = NULL;

int ucitaj_fajl(FILE* pok_na_fajl);
void ocisti_prazne();
void ucitaj_SRT();

long int string_to_miliSec(char* time_str);

int main()
{
    FILE* nasTitl = fopen("titl.srt","r");
    char temp[255];


    Titl nasTit;
    if(!ucitaj_fajl(nasTitl))
    {
        printf("error Studs and Bitches :D");
        return 1;
    }
    ocisti_prazne();
    ucitaj_SRT();
    ListaTitlova * trenutni_titl = pocetak_titlova;

    while(trenutni_titl->sledeci != NULL)
    {
        printf("%d\n%ld --> %ld\n",trenutni_titl->theTitl->redni_broj, trenutni_titl->theTitl->pocetak,trenutni_titl->theTitl->kraj);
        ListaTeksta * trenutni_pok = trenutni_titl->theTitl->pocetak_titla;
        while(trenutni_pok != trenutni_titl->theTitl->kraj_titla)
        {
            printf("%s",trenutni_pok->tekst);
            trenutni_pok = trenutni_pok->sledeci;
        }
        printf("\n");
        trenutni_titl = trenutni_titl->sledeci;
    }
}

long int string_to_miliSec(char* time_str)
{
    int sat,minut,sekund,miliSek;
    sscanf(time_str,"%d:%d:%d,%d",&sat,&minut,&sekund,&miliSek);
    return sat*60*60*1000 + minut*60*1000 + sekund*1000 + miliSek;
}

int ucitaj_fajl(FILE* pok_na_fajl)
{
    char error = 0;
    ListaTeksta * trenutni = pocetak;
    while (!feof(pok_na_fajl))
    {


        if(pocetak == NULL)
        {
            if((pocetak = malloc(sizeof(ListaTeksta))) == NULL)
            {
                error = 1;
                break;
            }
            pocetak->sledeci = NULL;
            trenutni = pocetak;
        }
        else
        {
            if((trenutni->sledeci = malloc(sizeof(ListaTeksta))) == NULL)
            {
                error = 1;
                break;
            }
            trenutni = trenutni->sledeci;
            trenutni->sledeci = NULL;
        }
        fgets(trenutni->tekst,255,pok_na_fajl);
        if(error)return 0;
    }
    return 1;
}

void ocisti_prazne()
{

    ListaTeksta * trenutni = pocetak;

    int i = 0;
    while(trenutni->sledeci->sledeci != NULL)
    {
        //printf("\n%d",i++);
        if(trenutni->tekst[0] == '\n')//ako je prvi clan niza teksta novi red
        {
            if(trenutni->sledeci->tekst[0] == '\n')
            {
                ListaTeksta * temp = trenutni->sledeci;
                trenutni->sledeci = trenutni->sledeci->sledeci;
                free(temp);
                continue;
            }
        }
        trenutni = trenutni->sledeci;
    }
}

void ucitaj_SRT()
{
    ListaTeksta * trenutni = pocetak;
    ListaTitlova * trenutni_titl = pocetak_titlova;

    while(trenutni != NULL)
    {
        while(trenutni->tekst[0] == '\n')trenutni = trenutni->sledeci;



        if(pocetak_titlova == NULL)
        {
            pocetak_titlova = malloc(sizeof(ListaTitlova));
            trenutni_titl = pocetak_titlova;
        }
        else
        {
            trenutni_titl->sledeci = malloc(sizeof(ListaTitlova));
            trenutni_titl = trenutni_titl->sledeci;
        }
        trenutni_titl->sledeci = NULL;
        trenutni_titl->theTitl = malloc(sizeof(Titl));



        trenutni_titl->theTitl->redni_broj = atoi(trenutni->tekst);
        trenutni = trenutni->sledeci;
        if(trenutni == NULL) break;
        char str_pocetak[50],str_kraj[50];

        sscanf(trenutni->tekst,"%s --> %s",str_pocetak,str_kraj);
        trenutni_titl->theTitl->pocetak = string_to_miliSec(str_pocetak);
        trenutni_titl->theTitl->kraj = string_to_miliSec(str_kraj);

        trenutni = trenutni->sledeci;


        trenutni_titl->theTitl->pocetak_titla=trenutni;
        while(trenutni->tekst[0] != '\n')
        {
            trenutni = trenutni->sledeci;
            if(trenutni == NULL)break;
        }
        if(trenutni == NULL)break;
        trenutni_titl->theTitl->kraj_titla = trenutni;
    }
}

