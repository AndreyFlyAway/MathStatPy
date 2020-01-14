#include "combinatorics.h"
/*
 * some functions from combinatorics
 */

/*
 *  factorial
 */
long int fact(long int N)
{
    if ( N == 0)
        return 1;
    else
      return N * fact(N - 1);
}

/*
 * variations without repetition
 */
long int _variations(long int m, long int n)
{
    if (m == 0)
        return 1;
    else
        return _variations(m - 1, n) * (n - m + 1);
}