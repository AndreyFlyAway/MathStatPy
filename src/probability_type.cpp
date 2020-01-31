///*
// * describe of probability object
// *
// * Created  on 15.01.20.
// */
#include "probability_type.h"
#include <math.h>

static double sum_o(double v_l, double v_r) { return v_r + v_l;}
static double subtract_o(double v_l, double v_r) { return v_r - v_l;}
static double multiply_o(double v_l, double v_r) { return v_r * v_l;}
static double divide_o(double v_l, double v_r) { return v_l / v_r;}

PyObject *
new_probability_ext(double _p_val,
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
        self->exceeded = 0;
    }
    return (PyObject *) self;
}

int
Probability_init(ProbabilityObject *self, PyObject *args, PyObject *kwds)
{
    double _p_val;
    if (!PyArg_ParseTuple(args, "|d", &_p_val))
        return -1;
    if (_p_val > 1.0)
    {
        self->p_value = 1.0;
        self->exceeded = 1;
    }
    else if(_p_val < 0.0)
    {
        PyErr_SetString(PyExc_TypeError, "Probability value cant be negative!");
        return -1;
    }
    else
    {
        self->p_value = _p_val;
        self->exceeded = 0;
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
    if (_p_val > 1.0)
        self->exceeded = 1;
    else
        self->exceeded = 0;

    return 0;
}

void
ProbabilityObject_dealloc(ProbabilityObject *self)
{
    Py_TYPE(self)->tp_free((PyObject *) self);
}

PyObject *
Probability_repr(ProbabilityObject *self)
{
    int vH;
    unsigned long vL;
    if (self->p_value == 1.0)
    {
        vH = (int)self->p_value;
        vL = 0;
    }
    else
    {
        vH = 0;
        vL = ((unsigned long)(self->p_value * 10000000.0)) % 10000000;
    }
    return PyUnicode_FromFormat("%d.%lu", vH, vL);
}

/* custom methods */

PyObject *
percentage(ProbabilityObject *self, PyObject *Py_UNUSED(ignored))
{
    long v = long(self->p_value * 100);
    return PyLong_FromLong(v);
}

PyObject *
exceeded(ProbabilityObject *self, PyObject *Py_UNUSED(ignored))
{
    return PyBool_FromLong(self->exceeded);
}

/* numeric operations */

PyObject *
num_operation(PyObject *left, PyObject *right, double (*operation)(double v_l, double v_r))
{
    double _v_left, _v_right, res;
    PyObject *result = Py_NotImplemented;

    p_values_check (left, right, &_v_left, &_v_right);

    if ((_v_right < 0.0) || (_v_left < 0.0))
    {
        PyErr_SetString(PyExc_TypeError, "Probability value cant be negative!");
    }
    else
    {
        res = check_p_val(operation(_v_left, _v_right));
        if (res < 0.0)
        {
            PyErr_SetString(PyExc_TypeError, "Result of numeric operation cant be negative!");
        }
        result = new_probability_obj(res);
    }

    if (result == Py_NotImplemented)
        Py_INCREF(result);

    return result;
}

void p_values_check(PyObject *left, PyObject *right, double *v_left, double *v_rigt)
{
    if (PyObj_Check(left))
    {
        *v_left = ((ProbabilityObject *)left)->p_value;
    }
    else{
        *v_left = PyFloat_AsDouble(left);
    }
    if (PyObj_Check(right))
    {
        *v_rigt = ((ProbabilityObject *)right)->p_value;
    }
    else{
        *v_rigt = PyFloat_AsDouble(right);
    }
}

PyObject *
Probabilit_add(PyObject *left, PyObject *right)
{
    return num_operation(left, right, sum_o);
}

PyObject *
Probabilit_subtract(PyObject *left, PyObject *right)
{
    return num_operation(right, left, subtract_o);
}

PyObject *
Probabilit_multiply(PyObject *left, PyObject *right)
{
    return num_operation(left, right, multiply_o);
}
PyObject *
Probabilit_divide(PyObject *left, PyObject *right)
{
    return num_operation(left, right, divide_o);
}

PyObject *
Probabilit_remainder(PyObject *left, PyObject *right)
{
    return num_operation(left, right, fmod);
}

PyObject *
Probabilit_pow(PyObject *n, PyObject *value)
{
    return num_operation(n, value, pow);
}

PyObject *
Probabilit_invert(PyObject *val)
{
    PyObject *result = new_probability_obj(1.0 - ((ProbabilityObject *)val)->p_value);
    return result;
}

PyObject *
Probabilit_nb_float(PyObject *self)
{
    ProbabilityObject* v = (ProbabilityObject*)self;
    return PyFloat_FromDouble(v->p_value);
}