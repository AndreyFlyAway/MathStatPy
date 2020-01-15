#include "Python.h"
#include "combinatorics.h"
#include "probability_type.h"


/* objects */
static PyObject *ErrorWrongValueObject;

static PyTypeObject ProbabilityType = {
        /* The ob_type field must be initialized in the module init function
         * to be portable to Windows without using C++. */
        PyVarObject_HEAD_INIT(NULL, 0)
        "MathStatPy.ProbabilityObject",             /*tp_name*/
        sizeof(ProbabilityObject),                          /*tp_basicsize*/
        0,                          /*tp_itemsize*/
        /* methods */
        0,                          /*tp_dealloc*/
        0,                          /*tp_vectorcall_offset*/
        0,                          /*tp_getattr*/
        0,                          /*tp_setattr*/
        0,                          /*tp_as_async*/
        0,                          /*tp_repr*/
        0,                          /*tp_as_number*/
        0,                          /*tp_as_sequence*/
        0,                          /*tp_as_mapping*/
        0,                          /*tp_hash*/
        0,                          /*tp_call*/
        0,                          /*tp_str*/
        0,                          /*tp_getattro*/
        0,                          /*tp_setattro*/
        0,                          /*tp_as_buffer*/
        Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /*tp_flags*/
        "Representation of Probability value.",                          /*tp_doc*/
        0,                          /*tp_traverse*/
        0,                          /*tp_clear*/
        0,                          /*tp_richcompare*/
        0,                          /*tp_weaklistoffset*/
        0,                          /*tp_iter*/
        0,                          /*tp_iternext*/
        0,                          /*tp_methods*/
        0,                          /*tp_members*/
        0,                          /*tp_getset*/
        0, /* see PyInit_xx */      /*tp_base*/
        0,                          /*tp_dict*/
        0,                          /*tp_descr_get*/
        0,                          /*tp_descr_set*/
        0,                          /*tp_dictoffset*/
        0,                          /*tp_init*/
        0,                          /*tp_alloc*/
        0,                          /*tp_new*/
        0,                          /*tp_free*/
        0,                          /*tp_is_gc*/
};

/* methods */
// TODO: make limits for input values of combinatoric functions

PyDoc_STRVAR(MathStatPy_permutation_doc,
"P(N)\n\
\n\
Return amount of permutation for N objects. N must be rather 0");

static PyObject *
Permutation(PyObject *self, PyObject *args)
{
    long int N, res;
    if (!PyArg_ParseTuple(args, "l", &N))
        return NULL;
    if (N < 0) {
        PyErr_SetString(ErrorWrongValueObject, "N cant be less then 0!");
        return NULL;
    }
    res = _factorial(N);
    
    return PyLong_FromLong(res);
}

PyDoc_STRVAR(MathStatPy_variations_doc,
"A(m,n)\n\
\n\
Return amount of variations without repetitions for m of n objects."
"Value m cant be raher n. Both m and n must be rather 0.");

static PyObject *
Variations(PyObject *self, PyObject *args)
{
    long int M, N, res;
    if (!PyArg_ParseTuple(args, "ll", &M, &N))
        return NULL;
    if ((M < 0) || (N < 0)){
        PyErr_SetString(ErrorWrongValueObject, "M and N cant be less then 0!");
        return NULL;
    }
    if (M > N) {
        PyErr_SetString(ErrorWrongValueObject, "M cant be rather then N!");
        return NULL;
    }
    res = _variations(M, N);

    return PyLong_FromLong(res);
}


PyDoc_STRVAR(MathStatPy_combinations_doc,
             "C(m,n)\n\
\n\
Return combinations of variations without repetitions for m of n objects."
"Value m cant be raher n. Both m and n must be rather 0.");

static PyObject *
Combinations(PyObject *self, PyObject *args)
{
    long int M, N, res;
    if (!PyArg_ParseTuple(args, "ll", &M, &N))
        return NULL;
    if ((M < 0) || (N < 0)){
        PyErr_SetString(ErrorWrongValueObject, "M and N cant be less then 0!");
        return NULL;
    }
    if ((M < 0) || (N < 0)){
        PyErr_SetString(ErrorWrongValueObject, "M and N cant be less then 0!");
        return NULL;
    }
    if (M > N) {
        PyErr_SetString(ErrorWrongValueObject, "M cant be rather then N!");
        return NULL;
    }
    res = _combinations(M, N);

    return PyLong_FromLong(res);

}


static PyMethodDef MathStatPy_methods[] = {
    {"P",             (PyCFunction)Permutation,          METH_VARARGS,
            MathStatPy_permutation_doc},
    {"A",             (PyCFunction)Variations,           METH_VARARGS,
            MathStatPy_variations_doc},
    {"C",             (PyCFunction)Combinations,         METH_VARARGS,
            MathStatPy_combinations_doc},
    {NULL,              NULL}           /* sentinel */
};


PyDoc_STRVAR(module_doc,
"Implementation some functions for probability theory and mathematical statistics.");

static int
MathStatPy_exec(PyObject *m)
{
    /* Slot initialization is subject to the rules of initializing globals.
       C99 requires the initializers to be "address constants".  Function
       designators like 'PyType_GenericNew', with implicit conversion to
       a pointer, are valid C99 address constants.

       However, the unary '&' operator applied to a non-static variable
       like 'PyBaseObject_Type' is not required to produce an address
       constant.  Compilers may support this (gcc does), MSVC does not.

       Both compilers are strictly standard conforming in this particular
       behavior.
    */
    /* Finalize the type object including setting type of the new type
     * object; doing it here is required for portability, too. */

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