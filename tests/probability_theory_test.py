import sys
from inspect import stack
from MathStatPy import ProbabilityType, Bernoulli_func, Moivre_Laplace_func, Laplace_by_Integral, Freq_Deviation

ANSWER_FMT = "TEST: {0:20} RES: {1}"

def answer(ex, s):
    print(ANSWER_FMT.format(ex, s))

def Bernoulli_func_test_1():
    """
    Bernoulli function test 1
    :return:
    """
    p = ProbabilityType(0.5)
    res = Bernoulli_func(3, 6, p)
    answer(stack()[0][3], res)

def Bernoulli_func_test_2():
    """
    Bernoulli function test 2
    :return:
    """
    p = ProbabilityType(0.75)
    res = Bernoulli_func(4, 6, p)
    answer(stack()[0][3], res)

def Moivre_Laplace_test_1():
    """
    De Moivre-Laplace function 1
    :return:
    """
    p = ProbabilityType(0.75)
    res = Moivre_Laplace_func(8, 10, p)
    answer(stack()[0][3], res)

def Moivre_Laplace_test_2():
    """
    De Moivre-Laplace function  test 2
    :return:
    """
    p = ProbabilityType(0.2)
    res = Moivre_Laplace_func(80, 400, p)
    answer(stack()[0][3], res)

def Laplace_by_Integral_test_1():
    """
    De Laplace_by_Integral_test_2 function  test 1. Answer: 0.8882
    :return:
    """
    p = ProbabilityType(0.2)
    res = Laplace_by_Integral(70, 100, 400, p)
    answer(stack()[0][3], res)

def Laplace_by_Integral_test_2():
    """
    De Laplace_by_Integral_test_2 function  test 2. Answer: 0,8882
    :return:
    """
    p = ProbabilityType(0.8)
    res = Laplace_by_Integral(75, 90, 100, p)
    answer(stack()[0][3], res)


def Freq_Deviation_test_1():
    """
    De Freq_Deviation_test_1 function  test 2. 1nswer: 0,9544
    :return:
    """
    p = ProbabilityType(0.1)
    res = Freq_Deviation(400, p, 0.03)
    answer(stack()[0][3], res)

def Freq_Deviation_test_2():
    """
    De Freq_Deviation_test_1 function  test 2. Answer: 0,182
    :return:
    """
    p = ProbabilityType(0.75)
    res = Freq_Deviation(10000, p, 0.001)
    answer(stack()[0][3], res)

if __name__ == "__main__":
    Bernoulli_func_test_1()
    Bernoulli_func_test_2()
    Moivre_Laplace_test_1()
    Moivre_Laplace_test_2()
    Laplace_by_Integral_test_1()
    Laplace_by_Integral_test_2()
    Freq_Deviation_test_1()
    Freq_Deviation_test_2()