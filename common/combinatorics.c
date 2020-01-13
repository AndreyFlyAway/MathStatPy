#include "combinatorics.h"

unsigned long int fact(unsigned int N)
{
    if (N < 0);
        return 0;
    if ( N == 0)
        return 1;
    else
      return N * fact(N - 1);
}