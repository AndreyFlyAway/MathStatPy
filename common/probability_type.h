//
// Created by user on 15.01.20.
//

#ifndef PROBABILITY_TYPE_H_H
#define MATHSTATPYLIB_PROBABILITY_TYPE_H_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Python.h"

typedef struct {
    PyObject_HEAD
    PyObject            *x_attr;        /* Attributes dictionary */
} ProbabilityObject;

#ifdef __cplusplus
}
#endif

#endif //PROBABILITY_TYPE_H_H
