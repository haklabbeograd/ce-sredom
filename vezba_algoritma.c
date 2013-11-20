#include <stdio.h>
#include <stdlib.h>

#define n 5
void stampanje_niza(int a[], int array_size)
{
    printf("{ ");
    for(int i =0;i < array_size ;i++)
    {
        printf(" %d ", a[i]);
    }
    printf(" }\n");
}

void BubbleSort(int a[], int array_size)
{
     int i, j, temp;
     for (i = 0; i < (array_size - 1); ++i)
     {
          for (j = 0; j < array_size - 1 - i; ++j )
          {
               if (a[j] > a[j+1])
               {
                    temp = a[j+1];
                    a[j+1] = a[j];
                    a[j] = temp;
               }
               getchar();
               stampanje_niza(a,16);
          }
     }
}

void SelectionSort(int a[], int array_size)
{
     int i;
     for (i = 0; i < array_size - 1; ++i)
     {
          int j, min, temp;
          min = i;
          for (j = i+1; j < array_size; ++j)
          {
               if (a[j] < a[min])
                    min = j;
          }

          temp = a[i];
          a[i] = a[min];
          a[min] = temp;
          getchar();
          stampanje_niza(a,16);

     }
}

void insertionSort(int a[], int array_size)
{
     int i, j, temp;
     for (i = 1; i < array_size; ++i)
     {
          temp = a[i];
          for (j = i; j > 0 && a[j-1] > temp; j--)
               {
                   a[j] = a[j-1];
                   getchar();
                   stampanje_niza(a,n);
               }
          a[j] = temp;
          getchar();
          stampanje_niza(a,n);
     }
}

int main()
{
    int neki_niz[]={5,4,1,3,2};//{6,5,17,22,12,8,47,24,1001,10,235,222,512,33,3,9};//16
    stampanje_niza(neki_niz,n);
    //BubbleSort(neki_niz,16);
    //SelectionSort(neki_niz,16);

    insertionSort(neki_niz,n);
    stampanje_niza(neki_niz,n);

    return 0;
}


