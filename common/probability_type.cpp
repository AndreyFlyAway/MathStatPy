///*
// * descibe of probability object
// *
// * Created  on 15.01.20.
// */
#include "probability_type.h"

static PyTypeObject ProbabilityType;

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


int
probabilityo_setattr(ProbabilityObject *self, const char *name, PyObject *v)
{
    if (self->x_attr == NULL) {
        self->x_attr = PyDict_New();
        if (self->x_attr == NULL)
            return -1;
    }
    if (v == NULL) {
        int rv = PyDict_DelItemString(self->x_attr, name);
        if (rv < 0 && PyErr_ExceptionMatches(PyExc_KeyError))
            PyErr_SetString(PyExc_AttributeError,
                            "delete non-existing Xxo attribute");
        return rv;
    }
    else
        return PyDict_SetItemString(self->x_attr, name, v);
}