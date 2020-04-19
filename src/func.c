#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

int Unique(char **S, int s){

}

void Sort(char **A, int size, int M){
char temp[M];
		for (int n = 1; n < size; n++)
			for (int m = 0; m < size - n; m++) {
				int code = strcmp(A[m + 1], A[m]);
				if (code < 0)
				{
					strcpy(temp,A[m]); 
					strcpy(A[m],A[m+1]);
					strcpy(A[m+1],temp); 
				}
			}
}
