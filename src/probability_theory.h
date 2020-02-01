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

/* common */
double Fi(double x);

/* Python functions */
PyObject *Bernoulli_func(PyObject *self, PyObject *args);
PyObject *Moivre_Laplace_func(PyObject *self, PyObject *args);

PyDoc_STRVAR(MathStatPy_Bernoulli_func_doc,
"Bernoulli_func(m, n, p)\n\
\n\
Bernoulli function calcuates probability that in n independent tests event with"
"probability p will occurs exactly k times.\n");

PyDoc_STRVAR(Moivre_Laplace_func_doc,
             "Moivre_Laplace_func(m, n, p)\n\
\n\
De Moivre-Laplace  theorem.\n");


#define BERNOULLI_FUNC    \
    {"Bernoulli_func", (PyCFunction)Bernoulli_func, METH_VARARGS, MathStatPy_Bernoulli_func_doc},

#define MOIVRE_LAPLACE_FUNC    \
    {"Moivre_Laplace_func", (PyCFunction)Moivre_Laplace_func, METH_VARARGS, Moivre_Laplace_func_doc},

#ifdef __cplusplus
}
#endif

#endif //MATHSTATPYLIB_PROBABILITY_THEORY_H
