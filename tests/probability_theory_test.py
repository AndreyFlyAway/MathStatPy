import sys
from MathStatPy import Bernoulli_func, Moivre_Laplace_func

def Bernoulli_func_test_1():
    """
    Bernoulli function test 1
    :return:
    """
    res = Bernoulli_func(3, 6, 0.5)
    print(res)

def Bernoulli_func_test_2():
    """
    Bernoulli function test 2
    :return:
    """
    res = Bernoulli_func(4, 6, 0.75)
    print(res)

def Moivre_Laplace_test_1():
    """
    De Moivre-Laplace function 1
    :return:
    """
    res = Moivre_Laplace_func(8, 10, 0.75)
    print(res)

def Moivre_Laplace_test_2():
    """
    De Moivre-Laplace function  test 2
    :return:
    """
    res = Moivre_Laplace_func(80, 400, 0.2)
    print(res)

if __name__ == "__main__":
    Bernoulli_func_test_1()
    Bernoulli_func_test_2()
    Moivre_Laplace_test_1()
    Moivre_Laplace_test_2()