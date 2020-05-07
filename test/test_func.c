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
    ASSERT_STR(arrTeor[0], arr[0]);
    ASSERT_STR(arrTeor[1], arr[1]);
    ASSERT_STR(arrTeor[2], arr[2]);
    ASSERT_STR(arrTeor[3], arr[3]);
    ASSERT_STR(arrTeor[4], arr[4]);
}

CTEST(arithmetic_suite, countWord)
{
    long long max = 0, count = 0;
    countWord(&max, &count, "test.txt");
    const long long countTeor = 4;
    const long long maxTeor = 5;
    ASSERT_EQUAL(countTeor, count);
    ASSERT_EQUAL(maxTeor, max);
}

CTEST(arithmetic_suite, Unique)
{
    long long s=3, sTeor=2;
    int i;
    char **arr;
	arr = (char**)malloc(5*sizeof(char*));
	for (i=0; i<5; i++) {
	arr[i] = (char*)malloc(10*sizeof(char));}
	strcpy(arr[0],"cat");
    strcpy(arr[1],"cat");
    strcpy(arr[2],"dog");
    
    char **arrTeor;
	arrTeor = (char**)malloc(5*sizeof(char*));
	for (i=0; i<5; i++) {
	arrTeor[i] = (char*)malloc(10*sizeof(char));}
	
    strcpy(arrTeor[0],"cat");
    strcpy(arrTeor[1],"dog");
    s=Unique(arr, s);
    ASSERT_EQUAL(sTeor, s);
    ASSERT_STR(arrTeor[0], arr[0]);
    ASSERT_STR(arrTeor[1], arr[1]);
}
