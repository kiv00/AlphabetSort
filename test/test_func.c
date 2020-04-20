#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/func.h"

#include "../thirdparty/ctest.h"

CTEST(arithmetic_suite, Sort)
{
    const char arr[5][10] = {"call", "art", "dog", "cat", "sad"};


     const char arrFact[5][10] = Sort(arr, 5, 10);

    const char[5][10] arrTeor = {"art", "call", "cat", "dog", "sad"};
    ASSERT_DATA(arrTeor, 5, arrFact, 5);
}
