#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <locale.h>

int Unique(char **S, int s){
for (int i = 0; i < s; i++)
    {
        for (int j = i + 1; j < s ; j++)
        {
            if (strcmp(S[i],S[j])==0 && S[j]!=NULL)
            {   
                for (int shift = j; shift < s-1; shift++)
                {
                    strcpy(S[shift],S[shift + 1]);
                }
                s--;
                if (strcmp(S[i],S[j])==0 && S[j]!=NULL)
                {
                 j--;    
                }
            }
        }
    }
    return s;
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
