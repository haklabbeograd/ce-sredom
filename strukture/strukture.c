#include <stdio.h>
#include <stdlib.h>

typedef enum {PLASTIKA,METAL,STAKLO} M;
char Mate[3][9]={"Plastika","Metal","Staklo"};
typedef enum {BELA,CRVENA,ZUTA,PLAVA,CRNA} B;
char Boj[5][7]={"Bela","Crvena","Zuta","Plava","Crna"};
typedef enum {PIVO,VISKI,RAKIJA,VODA,SOK}S;
char Sad[5][7] = {"Pivo","Viski","Rakija","Voda","K-so"};

char Rec[2][6] = {"Jeste","Nije"};
#define TRUE 0
#define FALSE 1





typedef struct
{

    M materijal;
    B boja;
    double zapremina;
    int recikljivo;
    FILE* etiketa;
    S sadrzaj;
}flasa;

void Stampaj_Flasu(flasa* Flasa);

int main()
{
    FILE* pok;
    pok = fopen("etiketa.txt","w");
    fprintf(pok,"Jelen_PIVO");
    fclose(pok);

    flasa Jelen;
    Jelen.materijal = STAKLO; //2;
    Jelen.boja = BELA;
    Jelen.zapremina = 0.5;
    Jelen.recikljivo = TRUE;
    Jelen.etiketa = fopen("etiketa.txt","r");
    Jelen.sadrzaj = PIVO;

    Stampaj_Flasu(&Jelen);
    fclose(Jelen.etiketa);

    return 0;
}

void Stampaj_Flasu(flasa* Flasa)
{
    printf("\nFlasa\n\nMaterijal je %s",Mate[Flasa->materijal]);
    printf("\nBoja je %s",Boj[Flasa->boja]);
    printf("\nZapremina je %.1fL",Flasa->zapremina);
    printf("\nDa li je odrzivo: %s",Rec[Flasa->recikljivo]);
    char temp[255];
    fgets(temp,255,Flasa->etiketa);
    printf("\nEtiketa: %s",temp);
    printf("\nSadrzaj je %s",Sad[Flasa->sadrzaj]);

}



