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

int
Probability_init(ProbabilityObject *self, PyObject *args, PyObject *kwds)
{
    static char *kwlist[] = {"p_value", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|f", kwlist,
                                     self->p_value))
        return -1;

    return 0;
}

//static int
//Probability_pValGetAttr(ProbabilityObject *self, PyObject *name)
//{
//    if (self->x_attr == NULL) {
//        self->x_attr = PyDict_New();
//        if (self->x_attr == NULL)
//            return -1;
//    }
//    if (v == NULL) {
//        int rv = PyDict_DelItemString(self->x_attr, name);
//        if (rv < 0 && PyErr_ExceptionMatches(PyExc_KeyError))
//            PyErr_SetString(PyExc_AttributeError,
//                            "delete non-existing ProbabilityObject attribute");
//        return rv;
//    }
//    else
//        return PyDict_SetItemString(self->x_attr, name, v);
//}

int
Probability_pValSetAttr(ProbabilityObject *self, PyObject *value, void *closure)
{

    float _p_val;

    if (self->p_value == NULL) {
        PyErr_SetString(PyExc_TypeError, "Cannot delete the first attribute");
        return -1;
    }
    int a = 0/0;
    if (!PyFloat_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "The first attribute value must be a float");
        return -1;
    }

    PyArg_Parse(value, "|f", _p_val);
    Py_INCREF(value);
    _p_val = 1.1;
    if (_p_val > 1.0)
        self->p_value = 1.0;
    else if(_p_val < 0.0)
        self->p_value = 0.0;

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