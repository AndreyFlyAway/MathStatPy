//
// Created by user on 15.01.20.
//

#ifndef MATHSTATPYLIB_PROBABILITY_TYPE_H
#define MATHSTATPYLIB_PROBABILITY_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Python.h"
#include <math.h>

typedef struct {
    PyObject_HEAD
    PyObject            *x_attr;        /* Attributes dictionary */
    double p_value; // probability value
    short exceeded; // Flag set if p_value was exceeded 1.0 in last operation
} ProbabilityObject;

/* coomon */
ProbabilityObject * newProbabilityObject(PyObject *arg);
PyObject *ProbabilityObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds);
void ProbabilityObject_dealloc(ProbabilityObject *self);
int Probability_init(ProbabilityObject *self, PyObject *args, PyObject *kwds);
int Probability_pValSetAttr(ProbabilityObject *self, PyObject *value);
PyObject *Probabilit_pValGetAttr(ProbabilityObject *self,  void *Py_UNUSED(ignored));
PyObject *Probability_repr(ProbabilityObject *self);
/* numeric operations */
PyObject *Probabilit_add(PyObject *left, PyObject *right);
PyObject *Probabilit_subtract(PyObject *left, PyObject *right);
PyObject *Probabilit_multiply(PyObject *left, PyObject *right);
PyObject *Probabilit_divide(PyObject *left, PyObject *right);
PyObject *Probabilit_remainder(PyObject *left, PyObject *right);
PyObject *Probabilit_pow(PyObject *value, PyObject *n);
PyObject *Probabilit_invert(PyObject *val);
PyObject *Probabilit_nb_float(PyObject *self);

/* secondary functions */
PyObject *percentage(ProbabilityObject *self, PyObject *Py_UNUSED(ignored));
void p_values_check(PyObject *left, PyObject *right, double *v_left, double *v_rigt);
PyObject *num_operation(PyObject *left, PyObject *right, double (*operation)(double v_l, double v_r));
PyObject *exceeded(ProbabilityObject *self, PyObject *Py_UNUSED(ignored));

extern PyTypeObject ProbabilityType;

PyDoc_STRVAR(MathStatPy_percentage_doc,
"persentage()\n\
\n\
Probability value in percentage (int value in range from 0 to 100)\n");

#define PROBABILITY_PERSENTEAGE    \
    {"percentage", (PyCFunction)percentage, METH_NOARGS, MathStatPy_percentage_doc},

PyDoc_STRVAR(MathStatPy_exceeded_doc,
"exceeded()\n\
\n\
Return true if last p_value was exceeded in last operation. \n");

#define PROBABILITY_EXCEEDED    \
    {"exceeded", (PyCFunction)exceeded, METH_NOARGS, MathStatPy_exceeded_doc},

#ifdef __cplusplus
}
#endif

#endif //MATHSTATPYLIB_PROBABILITY_TYPE_H_H
