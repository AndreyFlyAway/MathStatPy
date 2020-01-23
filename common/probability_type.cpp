///*
// * descibe of probability object
// *
// * Created  on 15.01.20.
// */
#include "probability_type.h"

#define PyObj_Check(op) PyObject_TypeCheck(op, &ProbabilityType)
#define new_probability_obj(p_val)  \
    new_probability_ext(p_val, &ProbabilityType)
#define check_p_val(p_val) { ((double )p_val > 1.0) ? 1.0 : p_val }

static PyObject *
new_probability_ext(float _p_val,
                   PyTypeObject *type)
{
    ProbabilityObject *self;

    self = (ProbabilityObject *) (type->tp_alloc(type, 0));
    if (self != NULL) {
        self->p_value = _p_val;
    }
    return (PyObject *) self;
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
    if(_p_val < 0.0)
    {
        self->p_value = 0.0;
        PyErr_SetString(PyExc_TypeError, "Probability value cant be negative!");
        return -1;
    }
    else{
        self->p_value = check_p_val(_p_val);
    }

    return 0;
}

PyObject *
persentage(ProbabilityObject *self, PyObject *Py_UNUSED(ignored))
{
    long v = long(self->p_value * 100);
    return PyLong_FromLong(v);
}

PyObject *
Probabilit__add__(PyObject *left, PyObject *right)
{
    double _v_left, _v_right, res;
    PyObject *result = Py_NotImplemented;
    if (PyObj_Check(left))
    {
        _v_left = ((ProbabilityObject *)left)->p_value;
    }
    else{
        _v_left = PyFloat_AsDouble(left);
    }
    if (PyObj_Check(right))
    {
        _v_right = ((ProbabilityObject *)right)->p_value;
    }
    else{
        _v_right = PyFloat_AsDouble(right);
    }
    if ((_v_right < 0.0) || (_v_left < 0.0))
    {
        PyErr_SetString(PyExc_TypeError, "Probablity value cant be neagative!");
    }
    else
    {
        res = check_p_val(_v_right + _v_left);
        result = new_probability_obj(res);
    }

    if (result == Py_NotImplemented)
        Py_INCREF(result);

    return result;
}
void
ProbabilityObject_dealloc(ProbabilityObject *self)
{
    Py_TYPE(self)->tp_free((PyObject *) self);
}