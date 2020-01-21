#include "Python.h"
#include "combinatorics.h"
#include "probability_type.h"
#include "structmember.h"

/* objects */

static PyMethodDef Probability_methods[] = {
        {"persentage", (PyCFunction)persentage, METH_CLASS, PyDoc_STR("Probability value in percentage (int value in range from 0 to 100)")},
//        {"__radd__", (PyCFunction)Probabilit__add__, METH_CLASS, PyDoc_STR("__add__")},
        {NULL, NULL}/* sentinel */
};


PyGetSetDef ProbabilityObject_getsetters[] = {
        {"p_value", (getter)Probabilit_pValGetAttr, (setter)Probability_pValSetAttr,
                "probabiliry value", NULL},
        {NULL}  /* Sentinel */
};

static PyNumberMethods value_as_number = {
        delta_add,                                  /* nb_add */
        0,                                  /* nb_subtract */
        0,                                  /* nb_multiply */
        0,                                  /* nb_remainder */
        0,                                  /* nb_divmod */
        0,                                  /* nb_power */
        0,                                  /* nb_negative */
        0,                                  /* nb_positive */
        0,                                  /* nb_absolute */
        0,                /* nb_bool */
        0,                                  /* nb_invert */
};

PyTypeObject ProbabilityType = {
     PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "MathStatPy.ProbabilityObject",
    .tp_doc = "Representation of probability.",
    .tp_basicsize = sizeof(ProbabilityObject),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = PyType_GenericNew,
    .tp_init = (initproc) Probability_init,
    .tp_members = 0,
    .tp_methods = Probability_methods,
    .tp_getset = ProbabilityObject_getsetters,
    .tp_new = ProbabilityObject_new,
    .tp_dealloc = (destructor) ProbabilityObject_dealloc,
    .tp_as_number = &value_as_number,
};

/* methods */


//PyDoc_STRVAR(MathStatPy_permutation_doc,
//"P(N)\n\
//\n\
//Return amount of permutation for N objects. N must be rather 0");


static PyMethodDef MathStatPy_methods[] = {
    COMBINATORICS_PERMUTATION_FNC
    COMBINATORICS_VARIATIONS_FNC
    COMBINATORICS_COMBINATIONS_FNC
    {NULL,              NULL}           /* sentinel */
};


PyDoc_STRVAR(module_doc,
"Implementation some functions for probability theory and mathematical statistics.");

static int
MathStatPy_exec(PyObject *m)
{
    ProbabilityType.tp_base = &PyBaseObject_Type;

    /* Add some symbolic constants to the module */
    if (ErrorWrongValueObject == NULL) {
        ErrorWrongValueObject = PyErr_NewException("MathStatPy.ValueRangeError", NULL, NULL);
        if (ErrorWrongValueObject == NULL)
            goto fail;
    }
    Py_INCREF(ErrorWrongValueObject);
    PyModule_AddObject(m, "Wrong value error.", ErrorWrongValueObject);

    Py_INCREF(&ProbabilityType);
    if (PyType_Ready(&ProbabilityType) < 0)
        goto fail;
    PyModule_AddObject(m, "ProbabilityType", (PyObject *)&ProbabilityType);

    return 0;
 fail:
    Py_XDECREF(m);
    return -1;
}

static struct PyModuleDef_Slot MathStatPy_slots[] = {
    {Py_mod_exec, MathStatPy_exec},
    {0, NULL},
};

static struct PyModuleDef MathStatPymodule = {
    PyModuleDef_HEAD_INIT,
    "MathStatPy",
    module_doc,
    0,
    MathStatPy_methods,
    MathStatPy_slots,
    NULL,
    NULL,
    NULL
};


PyMODINIT_FUNC
PyInit_MathStatPy(void)
{
    return PyModuleDef_Init(&MathStatPymodule);
}