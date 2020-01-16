///*
// * descibe of probability object
// *
// * Created  on 15.01.20.
// */
#include "probability_type.h"



ProbabilityObject *
newProbabilityObject(PyObject *arg)
{
    ProbabilityObject *self;
    self = PyObject_New(ProbabilityObject, &ProbabilityType);
    if (self == NULL)
        return NULL;
    self->x_attr = NULL;
    self->p_value = 0;
    return self;
}

PyObject *
ProbabilityObject_new(PyObject *self, PyObject *args)
{
    ProbabilityObject *rv;

    if (!PyArg_ParseTuple(args, ":new"))
        return NULL;
    rv = newProbabilityObject(args);
    if (rv == NULL)
        return NULL;
    return (PyObject *)rv;
}

void
ProbabilityObject_dealloc(ProbabilityObject *self)
{
    Py_TYPE(self)->tp_free((PyObject *) self);
}