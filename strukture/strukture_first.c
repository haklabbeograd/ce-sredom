#include <stdio.h>
#include <stdlib.h>

//Struktura clan koja sadrzi podatak i pokazivac na sledeci clan
typedef struct Clan
{
    int broj;
    struct Clan * sledeci;
} Clan;

//pokazivac na pocetak liste, tipa je pokazoivac na clan
//inicijalizovan na NULL tj nepokazuje ni nasta trenutno...
Clan * pocetak = NULL;

Clan * indeks = NULL;

Clan * vrati_Nti(Clan * poc, int N);
void ubaci_na_index(Clan * poc, int indeks, Clan * novi);

void main(void)
{
    int brojka;
    while(scanf("%d",&brojka) > 0)
    {
        Clan * tmp = malloc(sizeof(Clan));
        if(tmp == NULL)
        {
            printf("Gressskskksska NEma vise memm");
            break;
        }
        tmp->broj = brojka;
        tmp->sledeci = NULL; //novi caln sledeci pokazuje na kraj liste = NULL
        if(pocetak == NULL)
        {//ako lista nije jos zapoceta
         //postavi da pocetak i index pokazuje na novi clan
            pocetak = tmp;
            indeks= pocetak;
        }
        else
        {//ako vec postoji clan u listi
            indeks->sledeci = tmp;//postavi da poslednji clan pokazuje na novi
            indeks = indeks->sledeci;//pomeri index na novi clan
        }
    }
    indeks = pocetak;

    Clan * tmp = malloc(sizeof(Clan));
    if(tmp != NULL)
    {
        tmp->broj = 333;
        tmp->sledeci = NULL;
        ubaci_na_index(pocetak,4,tmp);
    }

    while(indeks != NULL)
    {
        printf("\n\n%d",indeks->broj);
        indeks = indeks->sledeci;
    }
    indeks = vrati_Nti(pocetak,5);
    printf ("\n\novo je 5ti clan: %d\n",indeks->broj);
}
//Vraca pokazivac na Nti clan liste
Clan * vrati_Nti(Clan * poc, int N)
{
    while((poc !=NULL)&&(N > 1))
    {
        poc = poc->sledeci;
        N--;
    }
     return poc;
}
//ubacuje clan novi na poziciju iza clana koji je na indeksu indeks :D
void ubaci_na_index(Clan * poc, int indeks, Clan * novi)
{
    poc = vrati_Nti(poc,indeks);
    novi->sledeci = poc->sledeci;
    poc->sledeci  = novi;
}
