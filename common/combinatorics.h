#ifndef COMBINATORICS_H_
#define COMBINATORICS_H_

#ifdef __cplusplus
    extern "C" {
#endif

#include "Python.h"

PyObject *ErrorWrongValueObject;

long int _factorial(long int N);
long int _variations(long int m, long int n);
long int _combinations(long int m, long int n);

PyObject *Permutation(PyObject *self, PyObject *args);
PyObject *Variations(PyObject *self, PyObject *args);
PyObject *Combinations(PyObject *self, PyObject *args);



PyDoc_STRVAR(MathStatPy_permutation_doc,
             "P(N)\n\
\n\
Return amount of permutation for N objects. N must be rather 0");

PyDoc_STRVAR(MathStatPy_variations_doc,
             "A(m,n)\n\
\n\
Return amount of variations without repetitions for m of n objects."
                     "Value m cant be raher n. Both m and n must be rather 0.");

PyDoc_STRVAR(MathStatPy_combinations_doc,
             "C(m,n)\n\
\n\
Return combinations of variations without repetitions for m of n objects."
                     "Value m cant be raher n. Both m and n must be rather 0.");

#define COMBINATORICS_PERMUTATION_FNC    \
    {"P", (PyCFunction)Permutation, METH_VARARGS, MathStatPy_permutation_doc},

#define COMBINATORICS_VARIATIONS_FNC    \
    {"A", (PyCFunction)Variations, METH_VARARGS, MathStatPy_variations_doc},

#define COMBINATORICS_COMBINATIONS_FNC   \
    {"C", (PyCFunction)Combinations, METH_VARARGS, MathStatPy_combinations_doc},

#ifdef __cplusplus
}
#endif

#endif
