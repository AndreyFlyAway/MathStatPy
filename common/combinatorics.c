#include "combinatorics.h"

long int fact(long int N)
{
    if ( N == 0)
        return 1;
    else
      return N * fact(N - 1);
}