//
// Created by user on 30.01.20.
//

#include "probability_theory.h"

PyObject *Bernoulli_func(PyObject *self, PyObject *args)
{
    int m,n;
    double p;
    ull combs;
    if (!PyArg_ParseTuple(args, "iid", &m, &n, &p))
        return NULL;
    combs = _combinations(m, n);
    p = ((double) combs) * pow(p, m) * pow(1.0 - p, n - m);
    PyObject *resul = new_probability_obj(p);

}