#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



typedef struct titl
{
    int redni_broj;
    long int pocetak;//ms
    long int kraj;//ms
    char tekst[10][255];
}Titl;

long int string_to_miliSec(char* time_str);

int main()
{
    FILE* nasTitl = fopen("titl.srt","r");
    char temp[255];


    Titl nasTit;
    while(!feof(nasTitl))
    {

        while( strlen(fgets(temp,255,nasTitl))  < 2);//obscure c :D
        nasTit.redni_broj = atoi(temp);
        printf("%d",nasTit.redni_broj);

        fgets(temp,255,nasTitl);

        char str_pocetak[50],str_kraj[50];

        sscanf(temp,"%s --> %s",str_pocetak,str_kraj);
        nasTit.pocetak = string_to_miliSec(str_pocetak);
        nasTit.kraj = string_to_miliSec(str_kraj);
        int j = 0;
        while(!feof(nasTitl))
        {
            char * tmp = fgets(temp,255,nasTitl);
            if(feof(nasTitl))
            {
                printf("ffff");
                break;
            }
            if(strlen(tmp)  < 2)break;
            strncpy(nasTit.tekst[j],temp,255);
            printf("\n%s",temp);
            j++;
            if(feof(nasTitl))
            {
                printf("ajde");
            }
        }
        printf("\nx1\n");
        printf("\n%s%s",nasTit.tekst[0],nasTit.tekst[1]);
    }
    //struct tm test_time_st;
    //char sat[3];
    //char minut[3];
    //char sekund[3];
    //char miliSek[5];

    //long int miliSekTime;


    //miliSekTime = string_to_miliSec(test[1]);
    //if(strptime(test_time, "%H:%M:%S",&test_time_st) == NULL)
      //    printf("\nstrptime failed\n");

    //printf("%ld", miliSekTime);
    return 0;
}

long int string_to_miliSec(char* time_str)
{
    int sat,minut,sekund,miliSek;
    sscanf(time_str,"%d:%d:%d,%d",&sat,&minut,&sekund,&miliSek);
    return sat*60*60*1000 + minut*60*1000 + sekund*1000 + miliSek;
}
