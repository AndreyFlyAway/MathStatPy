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
ProbabilityObject_new(PyTypeObject  *type, PyObject *args, PyObject *kwds)
{
    ProbabilityObject *self;
    self = (ProbabilityObject *) type->tp_alloc(type, 0);
    if (self != NULL) {
        self->p_value = 0.0;
    }
    return (PyObject *) self;
}

int
Probability_init(ProbabilityObject *self, PyObject *args, PyObject *kwds)
{
    static char *kwlist[] = {"p_value", NULL};
    double _p_val;
    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|f", kwlist,
                                     &_p_val))
        return -1;
    self->p_value = _p_val;
    return 0;
}


PyObject *
Probabilit_pValGetAttr(ProbabilityObject *self,  void *Py_UNUSED(ignored))
{
    return PyFloat_FromDouble(self->p_value);
}

int
Probability_pValSetAttr(ProbabilityObject *self, PyObject *value)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the p_value attribute");
        return -1;
    }

    double _p_val = PyFloat_AsDouble(value);
    Py_INCREF(value);
    if (_p_val > 1.0)
    {
        self->p_value = 1.0;
    }
    else if(_p_val < 0.0)
    {
        self->p_value = 0.0;
        PyErr_SetString(PyExc_TypeError, "Probability value cant be negative!");
        return -1;
    }
    else
    {
        self->p_value = _p_val;
    }

    return 0;
}

PyObject *
persentage(ProbabilityObject *self, PyObject *Py_UNUSED(ignored))
{
    long v = long(self->p_value * 100);
    return PyLong_FromLong(v);
}



void
ProbabilityObject_dealloc(ProbabilityObject *self)
{
    Py_TYPE(self)->tp_free((PyObject *) self);
}