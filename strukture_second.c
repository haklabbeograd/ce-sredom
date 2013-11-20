#include <stdio.h>
#include <stdlib.h>

int store(int start_pos, char sep_value,char* input, char*output,int maxc);
int count_chars(char * line, char c);

typedef struct Licnost
{
    char ime[30];
    long long jmbg;
    char adresa[50];
    int visina;
    int tezina;
} Licnost;

typedef struct Node
{
    Licnost lice;
    struct Node *next;
} Node;

int load_Licnost(FILE * file, Licnost* lice);

Node *clan, *prvi_clan = 0;

int main()
{
    FILE* file = fopen("test.csv","r");

    Licnost lice;
    while(!feof(file))
    {
        if(load_Licnost(file,&lice))
        {
            //printf("\n%s\n%I64d\n%s\n%d\n%d\n",lice.ime,lice.jmbg,lice.adresa,lice.visina,lice.tezina);
            if (!prvi_clan)
            {
                clan = malloc(sizeof(Node));
                prvi_clan = clan;
            } else {
                clan->next = malloc(sizeof(Node));
                clan = clan->next;
            }
            clan->next = 0;
            clan->lice = lice;
        }
    }
    fclose(file);

    clan = prvi_clan;
    while (clan) {
        printf("\n%s\n%I64d\n%s\n%d\n%d\n",clan->lice.ime,clan->lice.jmbg,clan->lice.adresa,clan->lice.visina,clan->lice.tezina);
        clan = clan->next;
    }
    return 0;
}

int store(int start_pos, char sep_value,char* input, char*output,int maxc)
{
    int i = start_pos;
    int j = 0;
    while((input[i] != sep_value)&&(input[i] != 0)&& (j < maxc))
    {
        output[j] = input[i];
        j++;
        i++;
    }
    output[j] = '\0';
    if(input[i] == sep_value) i++;
    return i;
}


int load_Licnost(FILE * file, Licnost* lice)
{
    char test[255];
    fgets(test,255,file);
    if( count_chars(test,',') == 4)
    {
        char jmbg[20],visina[5],tezina[5];
        int pos = 0;
        pos = store(pos,',',test,lice->ime,29);
        pos = store(pos,',',test,jmbg,19);
        pos = store(pos,',',test,lice->adresa,49);
        pos = store(pos,',',test,visina,4);
        pos = store(pos,',',test,tezina,4);

        sscanf(jmbg,"%I64d",&(lice->jmbg));
        sscanf(visina,"%d",&(lice->visina));
        sscanf(tezina,"%d",&(lice->tezina));
        return 1;
    }
    else return 0;
}


int count_chars(char *line,char c)
{
    int i = 0;
    int broj_nadjenih=0;
    while(line[i]!= '\0')
    {
        if(line[i]== c)
        {
            broj_nadjenih++;
        }
        i++;
    }
    return broj_nadjenih;
}

//
