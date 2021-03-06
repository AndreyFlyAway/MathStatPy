//
// Created by user on 30.01.20.
//

#include "probability_theory.h"

const double INTEGRAL_ACCURACY = 0.0001;

/* common */
double Fi(double x){
    double res = (1 / sqrt(2 * M_PI)) * exp(-(pow(x, 2)) / 2);
    return res;
}

double Fi_Laplcae(double z){
    double res = (1 / sqrt(2 * M_PI)) * exp(-(pow(z, 2)) / 2);
    return res;
}

double Integral(const double x0, const double xN, double (*F)(double x))
{
    unsigned n = 1;
    double h = (xN - x0);
    double res = (F(x0) + F(xN)) * (h / 2);
    double accuracy = INTEGRAL_ACCURACY;
    double sum = 0;
    double delta, delta_abs, res_last;

    for(int k = 0; k < 10; k++)
    {
        sum = 0;
        h = h/2;
        for(unsigned j = 1; j <= n; j++)
            sum += F(x0 + (double((j * 2) - 1) * h));

        res_last = res;
        res = (res / 2) + (h * sum);
        delta = res_last / res - 1;
        delta_abs = ((delta < 0) ? -delta : delta);

        if((k > 1) && (delta_abs < accuracy))
            break;

        n *= 2;
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


PyObject *Laplace_by_Integral(PyObject *self, PyObject *args)
{
    int k1, k2, n;
    double p, q, k_del, np, res;
    double x1, x2;
    if (!PyArg_ParseTuple(args, "iiid", &k1, &k2, &n, &p))
        return NULL;
    //TODO: add value range checking
    if (k1 < 0){
        PyErr_SetString(ErrorWrongValueObject, "k1 cant be less then 0!");
        return NULL;
    }
    if (k2 < 0){
        PyErr_SetString(ErrorWrongValueObject, "k2 cant be less then 0!");
        return NULL;
    }
    if (n <= 0){
        PyErr_SetString(ErrorWrongValueObject, "n cant be less or equal 0!");
        return NULL;
    }
    if (p < 0.0 || p > 1.0){
        PyErr_SetString(ErrorWrongValueObject, "Wrong value for probability!");
        return NULL;
    }

    q = 1.0 - p;
    k_del = sqrt(n * p * q);
    np = n * p;
    x1 = (k1 - np) / k_del;
    x2 = (k2 - np) / k_del;
    res = Integral(0, x2, Fi_Laplcae) - Integral(0, x1, Fi_Laplcae);
    PyObject *result = new_probability_obj(res);
    return result;
}

PyObject *Freq_Deviation(PyObject *self, PyObject *args){
    int n;
    double p, eps, q, res, x;
    if (!PyArg_ParseTuple(args, "idd", &n, &p, &eps))
        return NULL;
    q = 1.0 - p;
    x = eps * sqrt(n / (p* q));
    res = 2 * Integral(0, x, Fi_Laplcae);
    PyObject *result = new_probability_obj(res);

    return result;
}

