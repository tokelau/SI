#include <assert.h>
#include <stdio.h>
#include <windows.h>

main()
{
    int t;
    FILE *qwer;
    qwer=fopen("C:\\qwer.txt", "r");
    t=fgetc(qwer);
    printf("%d\n", t);
}
