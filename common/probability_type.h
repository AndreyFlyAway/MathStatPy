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
    double p_value;
} ProbabilityObject;

/* coomon */
ProbabilityObject * newProbabilityObject(PyObject *arg);
PyObject *ProbabilityObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds);
void ProbabilityObject_dealloc(ProbabilityObject *self);
int Probability_init(ProbabilityObject *self, PyObject *args, PyObject *kwds);
int Probability_pValSetAttr(ProbabilityObject *self, PyObject *value);
PyObject *Probabilit_pValGetAttr(ProbabilityObject *self,  void *Py_UNUSED(ignored));
/* numeric operations */
PyObject *Probabilit_add(PyObject *left, PyObject *right);
PyObject *Probabilit_subtract(PyObject *left, PyObject *right);
PyObject *Probabilit_multiply(PyObject *left, PyObject *right);
PyObject *Probabilit_divide(PyObject *left, PyObject *right);
PyObject *Probabilit_remainder(PyObject *left, PyObject *right);
PyObject *Probabilit_pow(PyObject *value, PyObject *n);
PyObject *Probabilit_invert(PyObject *val);

/* secondary functions */
PyObject *persentage(ProbabilityObject *self, PyObject *Py_UNUSED(ignored));
void p_values_check(PyObject *left, PyObject *right, double *v_left, double *v_rigt);
PyObject *num_operation(PyObject *left, PyObject *right, double (*operation)(double v_l, double v_r));

extern PyTypeObject ProbabilityType;

#ifdef __cplusplus
}
#endif

#endif //MATHSTATPYLIB_PROBABILITY_TYPE_H_H
