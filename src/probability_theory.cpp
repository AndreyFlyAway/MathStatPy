//
// Created by user on 30.01.20.
//

#include "probability_theory.h"

/* common */
double Fi(double x){
    double res = (1 / sqrt(2 * M_PI)) * exp(-(pow(x, 2)) / 2);
    return res;
}

double Fi_Laplcae(double z){
    double res = (1 / sqrt(2 * M_PI)) * exp(-(pow(z, 2)) / 2);
    return res;
}

double Integral(double x0, double xN, double (*F)(double x))
{
    double c_delta, res, x_step;
    res = 0.0;
    c_delta = (xN - x0)/1000.0;
    x_step = x0 + c_delta;
    while(x_step < xN)
    {
        res = res + F(x_step) * c_delta;
        x_step = x_step + c_delta;
    }
    return res;
}

/* Python functions */
PyObject *Moivre_Laplace_func(PyObject *self, PyObject *args){
    int k, n;
    double p, x, res;
    if (!PyArg_ParseTuple(args, "iid", &k, &n, &p))
        return NULL;
    //TODO: add value range checking
    x = (k - n * p) / sqrt(n * p * (1 - p));
    res = ( 1/ sqrt(n * p * (1 - p)) )* Fi(x);
    PyObject *result = new_probability_obj(res);
    return result;
}

PyObject *Bernoulli_func(PyObject *self, PyObject *args)
{
    int m,n;
    double p;
    ull combs;

    if (!PyArg_ParseTuple(args, "iid", &m, &n, &p))
        return NULL;
    combs = _combinations(m, n);
    p = ((double) combs) * pow(p, m) * pow(1.0 - p, n - m);
    PyObject *result = new_probability_obj(p);
    return result;
}