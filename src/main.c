#include "func.h"
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int i, j;
    long long count = 0, max = 0;
    FILE *op, *sort;
    char name1[1000], name2[1000], zapros[1002], simbol, pred = '.';
    char** slovaDyn;
    printf("enter the file name: ");
    scanf("%s", zapros);
    strcpy(name1, "../texts/");
    strcpy(name2, "../Sort/");
    strcat(name1, zapros);
    strcat(name2, zapros);
    sort = fopen(name2, "w");
    op = fopen(name1, "r");
    if (op == NULL) {
        printf("file error");
        system("PAUSE");
        return 0;
    }
    countWord(&max, &count, name1);
    char** slovaDinam;
    slovaDinam = (char**)malloc(count * sizeof(char*));
    for (i = 0; i < count; i++) {
        slovaDinam[i] = (char*)malloc(max * sizeof(char));
    }
    wordsArray(slovaDinam, name1, count, max);
    Sort(slovaDinam, count, max);

    count = Unique(slovaDinam, count);

    for (int i = 0; i < count; i++) {
        fputs(slovaDinam[i], sort);
        putc('\n', sort);
    }
    fclose(op);
    fclose(sort);
    printf("Complete!\n");
    system("PAUSE");
    return EXIT_SUCCESS;
}
