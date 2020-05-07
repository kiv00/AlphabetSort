#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Unique(char **S, int s);

void Sort(char **A, int size, int M);

void countWord(long long *max, long long *count, char *filename);

void wordsArray(char **slovaDinam, char *filename, long long count,
                long long max);

#endif
