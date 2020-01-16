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
PyObject *ProbabilityObject_new(PyObject *self, PyObject *args);
int probabilityo_setattr(ProbabilityObject *self, const char *name, PyObject *v);
int Probability_init(ProbabilityObject *self, PyObject *args, PyObject *kwds);
void ProbabilityObject_dealloc(ProbabilityObject *self);
extern PyTypeObject ProbabilityType;

#ifdef __cplusplus
}
#endif

#endif //MATHSTATPYLIB_PROBABILITY_TYPE_H_H
