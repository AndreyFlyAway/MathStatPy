//
// some common functions from probability theory
//
// Created by user on 30.01.20.
//

#ifndef MATHSTATPYLIB_PROBABILITY_THEORY_H
#define MATHSTATPYLIB_PROBABILITY_THEORY_H

#define INTEGRAL_DELTA 1000.0

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
double Fi_Laplcae(double x);
double Integral(const double x0, const double xN, double (*F)(double x));

/* Python functions */
PyObject *Bernoulli_func(PyObject *self, PyObject *args);
PyObject *Moivre_Laplace_func(PyObject *self, PyObject *args);
PyObject *Laplace_by_Integral(PyObject *self, PyObject *args);

PyDoc_STRVAR(MathStatPy_Bernoulli_func_doc,
"Bernoulli_func(m, n, p)\n\
\n\
Bernoulli function calcuates probability that in n independent tests event with"
"probability p will occurs exactly k times. This functions cant be used if value"
"m and n rather 10, it's test function. \n");

PyDoc_STRVAR(Moivre_Laplace_func_doc,
"Moivre_Laplace_func(m, n, p)\n\
\n\
Calcuates approximatel value of probability that in n independent tests event with\"\n"
"\"probability p will occurs k times.\n");

PyDoc_STRVAR(Laplace_by_Integral_doc,
"Moivre_Laplace_func(k1, k2, n, p)\n\
\n\
Calcuates approximatel value of probability that in n independent tests event with\"\n"
"\"probability p will occurs k1 two k2 times.\n");


#define BERNOULLI_FUNC    \
    {"Bernoulli_func", (PyCFunction)Bernoulli_func, METH_VARARGS, MathStatPy_Bernoulli_func_doc},

#define MOIVRE_LAPLACE_FUNC    \
    {"Moivre_Laplace_func", (PyCFunction)Moivre_Laplace_func, METH_VARARGS, Moivre_Laplace_func_doc},

#define LAPLACE_BY_INTEGRAL_FUNC    \
    {"Laplace_by_Integral", (PyCFunction)Laplace_by_Integral, METH_VARARGS, Laplace_by_Integral_doc},

#ifdef __cplusplus
}
#endif

#endif //MATHSTATPYLIB_PROBABILITY_THEORY_H
