#include "combinatorics.h"
/*
 * some functions from combinatorics
 */

/*
 *  factorial
 */
ull _factorial(int N)
{
    if ( N == 0)
        return 1;
    else
      return N * _factorial(N - 1);
}

/*
 * variations without repetition
 */
ull _variations(int m, int n)
{
    if (m == 0)
        return 1;
    else
        return _variations(m - 1, n) * (n - m + 1);
}

/*
 * combinations
 */
ull _combinations(int m, int n)
{
    unsigned long C;
    C = _factorial(n) / (_factorial(m) * _factorial(n - m));
    return C;
}

// TODO: make limits for input values of combinatoric functions
// TODO: change type of input and output values to unsigned
PyObject *
Permutation(PyObject *self, PyObject *args)
{
    ull res;
    int N;
    if (!PyArg_ParseTuple(args, "I", &N))
        return NULL;
    if (N < 0) {
        PyErr_SetString(ErrorWrongValueObject, "N cant be less then 0!");
        return NULL;
    }
    res = _factorial(N);

    return PyLong_FromUnsignedLongLong(res);
}

PyObject *
Variations(PyObject *self, PyObject *args)
{
    int M, N;
    ull res;
    if (!PyArg_ParseTuple(args, "II", &M, &N))
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

    return PyLong_FromUnsignedLongLong(res);
}

PyObject *
Combinations(PyObject *self, PyObject *args)
{
    int M, N;
    ull res;
    if (!PyArg_ParseTuple(args, "II", &M, &N))
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

    return PyLong_FromUnsignedLongLong(res);

}