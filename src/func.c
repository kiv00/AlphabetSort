#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

int Unique(char** S, int s)
{
    for (int i = 0; i < s; i++) {
        for (int j = i + 1; j < s; j++) {
            if (strcmp(S[i], S[j]) == 0 && S[j] != NULL) {
                for (int shift = j; shift < s - 1; shift++) {
                    strcpy(S[shift], S[shift + 1]);
                }
                s--;
                if (strcmp(S[i], S[j]) == 0 && S[j] != NULL) {
                    j--;
                }
            }
        }
    }
    return s;
}

void Sort(char** A, int size, int M)
{
    char temp[M];
    for (int n = 1; n < size; n++)
        for (int m = 0; m < size - n; m++) {
            int code = strcmp(A[m + 1], A[m]);
            if (code < 0) {
                strcpy(temp, A[m]);
                strcpy(A[m], A[m + 1]);
                strcpy(A[m + 1], temp);
            }
        }
}

void countWord(long long* max, long long* count, char* filename)
{
    char simbol, pred = '.';
    long long dlin = 1;
    long long counts = 0;
    FILE* op = fopen(filename, "r");
    while ((simbol = getc(op)) != EOF) {
        if ((simbol > 64 && simbol < 91) || (simbol > 96 && simbol < 123) || (simbol > 191 && simbol < 256)) {
            if ((pred > 64 && pred < 91) || (pred > 96 && pred < 123) || (pred > 191 && pred < 256)) {
                dlin++;
            }
            else {
                if (dlin > *max)
                    *max = dlin;
                dlin = 1;
                counts++;
            }
        }
        pred = simbol;
    }
    *max++;
    *count = counts;
    fclose(op);
}

void wordsArray(char** slovaDinam, char* filename, long long count, long long max)
{
    char slova[count][max], simbol, pred;
    int i = -1, j = 0;
    FILE* op = fopen(filename, "r");
    rewind(op);
    pred = '.';
    while ((simbol = getc(op)) != EOF) {
        if ((simbol > 64 && simbol < 91) || (simbol > 96 && simbol < 123)) {
            if (!((pred > 64 && pred < 91) || (pred > 96 && pred < 123))) {
                i++;
                j = 1;
                if (simbol > 64 && simbol < 91)
                    simbol += 32;
                slovaDinam[i][0] = simbol;
            }
            else {
                if (simbol > 64 && simbol < 91)
                    simbol += 32;
                slovaDinam[i][j] = simbol;
                j++;
                slovaDinam[i][j] = 0;
            }
        }
        pred = simbol;
    }
    fclose(op);
}
