//
// some common functions from probability theory
//
// Created by user on 30.01.20.
//

#ifndef MATHSTATPYLIB_PROBABILITY_THEORY_H
#define MATHSTATPYLIB_PROBABILITY_THEORY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include "Python.h"
#include "combinatorics.h"
#include "probability_type.h"

extern PyObject *ErrorWrongValueObject;

PyObject *Bernoulli_func(PyObject *self, PyObject *args);

PyDoc_STRVAR(MathStatPy_Bernoulli_func_doc,
"Bernoulli_func(m, n, p)\n\
\n\
Bernoulli's function ");

#define BERNOULLI_FUNC    \
    {"Bernoulli_func", (PyCFunction)Bernoulli_func, METH_VARARGS, MathStatPy_Bernoulli_func_doc},

#ifdef __cplusplus
}
#endif

#endif //MATHSTATPYLIB_PROBABILITY_THEORY_H
