#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/func.h"

#include "../thirdparty/ctest.h"

CTEST(arithmetic_suite, Sort)
{
	int i;
	char **arr;
	arr = (char**)malloc(5*sizeof(char*));
	for (i=0; i<5; i++) {
	arr[i] = (char*)malloc(10*sizeof(char));}
	
    strcpy(arr[0],"call");
    strcpy(arr[1],"art");
    strcpy(arr[2],"dog");
    strcpy(arr[3],"cat");
    strcpy(arr[4],"sad");
	
    Sort(arr, 5, 10);

	char **arrTeor;
	arrTeor = (char**)malloc(5*sizeof(char*));
	for (i=0; i<5; i++) {
	arrTeor[i] = (char*)malloc(10*sizeof(char));}
	
    strcpy(arrTeor[0],"art");
    strcpy(arrTeor[1],"call");
    strcpy(arrTeor[2],"cat");
    strcpy(arrTeor[3],"dog");
    strcpy(arrTeor[4],"sad");
    ASSERT_DATA(arrTeor, 5, arr, 5);
}
