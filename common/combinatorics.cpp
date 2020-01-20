#include "combinatorics.h"
/*
 * some functions from combinatorics
 */

/*
 *  factorial
 */
long int _factorial(long int N)
{
    if ( N == 0)
        return 1;
    else
      return N * _factorial(N - 1);
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

/*
 * combinations
 */
long int _combinations(long int m, long int n)
{
    long int C;
    C = _factorial(n) / (_factorial(m) * _factorial(n - m));
    return C;
}

// TODO: make limits for input values of combinatoric functions
// TODO: change type of input and output values to usigned


PyObject *
Permutation(PyObject *self, PyObject *args)
{
    long int N, res;
    if (!PyArg_ParseTuple(args, "l", &N))
        return NULL;
    if (N < 0) {
        PyErr_SetString(ErrorWrongValueObject, "N cant be less then 0!");
        return NULL;
    }
    res = _factorial(N);

    return PyLong_FromLong(res);
}


PyObject *
Variations(PyObject *self, PyObject *args)
{
    long int M, N, res;
    if (!PyArg_ParseTuple(args, "ll", &M, &N))
        return NULL;
    if ((M < 0) || (N < 0)){
        PyErr_SetString(ErrorWrongValueObject, "M and N cant be less then 0!");
        return NULL;
    }
    if (M > N) {
        PyErr_SetString(ErrorWrongValueObject, "M cant be rather then N!");
        return NULL;
    }
    res = _variations(M, N);

    return PyLong_FromLong(res);
}

PyObject *
Combinations(PyObject *self, PyObject *args)
{
    long int M, N, res;
    if (!PyArg_ParseTuple(args, "ll", &M, &N))
        return NULL;
    if ((M < 0) || (N < 0)){
        PyErr_SetString(ErrorWrongValueObject, "M and N cant be less then 0!");
        return NULL;
    }
    if ((M < 0) || (N < 0)){
        PyErr_SetString(ErrorWrongValueObject, "M and N cant be less then 0!");
        return NULL;
    }
    if (M > N) {
        PyErr_SetString(ErrorWrongValueObject, "M cant be rather then N!");
        return NULL;
    }
    res = _combinations(M, N);

    return PyLong_FromLong(res);

}