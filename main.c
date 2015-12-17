//#include <assert.h>
#include <stdio.h>
//#include <windows.h>

#define ENCODE_CRUFT 0

// Можно наделать таких блоков для каждого варианта,
// и потом переключать значения макроса ENCODE_CRUFT
#if ENCODE_CRUFT == 0
    #define AP_L 224
    #define AP_R 255
    #define CAPS_L 192
    #define CAPS_R 223
#endif

int
main ()
{
    /*SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   // setlocale (LC_TYPE, "rus");*/
    FILE *qwero;
    FILE *qwer;
    int l[34]; /*массив-счетчик*/
    int i;
    for (i=0; i<=33; i++)
    {
        l[i]=0;
    };

    int c;
        qwero=fopen ("C:\\qwero.txt", "w");
        qwer=fopen("C:\\qwer.txt", "r");

    while ((c=fgetc(qwer)) != EOF) /*распределение и подсчет символов*/
    {
        printf("%d\t", c);
        if (c>=AP_L && c <=AP_R) /* а-п */
        {
            c-=AP_L-1;
            l[c]++;
            //printf("%d\n",l[c]);
        }
                if (c>=CAPS_L && c<= CAPS_R) /* А-Я */
        {
            c-=CAPS_L-1;
            l[c]++;
            //printf("%d\n", l[c]);
        }
    }
    printf("%d\n", l[2]); /*почему не печатается??? */

       for (i=1; i<=33; i++)
    {
        fprintf(qwero, "%d\n",l[i]);
    }
    //assert (! ferror (stdin));
    fclose (qwero);
    fclose (qwer);
    return 0;
    }
