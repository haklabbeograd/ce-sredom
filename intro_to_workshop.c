#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char deleteTweed[] = {8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0}; // 8 ASCII for BackSpace

int main()
{
    char tumbleweed[17];
    tumbleweed[16] = 0;

    int counter = 0;
    while(counter++ < 16)
    {
        int i;
        for(i = 0; i < 16; i++)
        {
            if(i == counter)
                tumbleweed[i] = '@';
            else
                tumbleweed[i] = '_';
        }
        printf(deleteTweed);
        printf(tumbleweed);
        usleep(200000);
    }
    return 0;
}
