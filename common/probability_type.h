//
// Created by user on 15.01.20.
//

#ifndef MATHSTATPYLIB_PROBABILITY_TYPE_H
#define MATHSTATPYLIB_PROBABILITY_TYPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Python.h"

typedef struct {
    PyObject_HEAD
    PyObject            *x_attr;        /* Attributes dictionary */
    float p_value;
} ProbabilityObject;

ProbabilityObject * newProbabilityObject(PyObject *arg);
PyObject *ProbabilityObject_new(PyTypeObject *type, PyObject *args, PyObject *kwds);
// int Probability_init(ProbabilityObject *self, PyObject *args, PyObject *kwds);
void ProbabilityObject_dealloc(ProbabilityObject *self);
int Probability_init(ProbabilityObject *self, PyObject *args, PyObject *kwds);
//PyObject *Probability_pValSetAttr(ProbabilityObject *self, PyObject *name);
//PyObject *Probability_pValGetAttr(ProbabilityObject *self, PyObject *name);

int Probability_pValSetAttr(ProbabilityObject *self, PyObject *value);
PyObject *Probabilit_pValGetAttr(ProbabilityObject *self,  void *Py_UNUSED(ignored));
PyObject *persentage(ProbabilityObject *self, PyObject *Py_UNUSED(ignored));
extern PyTypeObject ProbabilityType;

#ifdef __cplusplus
}
#endif

#endif //MATHSTATPYLIB_PROBABILITY_TYPE_H_H
