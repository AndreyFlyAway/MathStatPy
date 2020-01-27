#include "Python.h"
#include "combinatorics.h"
#include "probability_type.h"
#include "structmember.h"

/* objects */

static PyMethodDef Probability_methods[] = {
        {"persentage", (PyCFunction)persentage, METH_CLASS, PyDoc_STR("Probability value in percentage (int value in range from 0 to 100)")},
        {NULL, NULL}/* sentinel */
};


PyGetSetDef ProbabilityObject_getsetters[] = {
        {"p_value", (getter)Probabilit_pValGetAttr, (setter)Probability_pValSetAttr,
                "probabiliry value", NULL},
        {NULL}  /* Sentinel */
};

static PyNumberMethods value_as_number = {
        Probabilit_add,                                  /* nb_add */
        Probabilit_subtract,                                  /* nb_subtract */
        Probabilit_multiply,                                  /* nb_multiply */
        Probabilit_remainder,                                  /* nb_remainder */
        0,                                  /* nb_divmod */
        Probabilit_pow,                                  /* nb_power */
        0,                                  /* nb_negative */
        0,                                  /* nb_positive */
        0,                                  /* nb_absolute */
        0,                /* nb_bool */
        Probabilit_invert,                                  /* nb_invert */
        0,                                          /*nb_lshift*/
        0,                                          /*nb_rshift*/
        0,                                          /*nb_and*/
        0,                                          /*nb_xor*/
        0,                                          /*nb_or*/
        0,                                          /*nb_int*/
        0,                                          /*nb_reserved*/
        0,                                          /*nb_float*/
        0,                                          /*nb_inplace_add*/
        0,                                          /*nb_inplace_subtract*/
        0,                                          /*nb_inplace_multiply*/
        0,                                          /*nb_inplace_remainder*/
        0,                                          /*nb_inplace_power*/
        0,                                          /*nb_inplace_lshift*/
        0,                                          /*nb_inplace_rshift*/
        0,                                          /*nb_inplace_and*/
        0,                                          /*nb_inplace_xor*/
        0,                                          /*nb_inplace_or*/
        0,                                          /* nb_floor_divide */
        Probabilit_divide,                                          /* nb_true_divide */
        0,                                          /* nb_inplace_floor_divide */
        0,                                          /* nb_inplace_true_divide */
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