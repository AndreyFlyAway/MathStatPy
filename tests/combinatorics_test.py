import MathStatPy
import sys
def Permutation_test():
    """
    Permutation test
    :return:
    """
    print("Permutation test.")
    #print(help(MathStatPy.P))
    for i in range(0, 10):
        print(MathStatPy.P(i))
    print("Permutation out of range test.")
    try:
        print(MathStatPy.P(-1))
    except:
        print(sys.exc_info())
    try:
        print(MathStatPy.P(-1))
    except:
        print(sys.exc_info())
    try:
        print(MathStatPy.P(-2))
    except:
        print(sys.exc_info())
    try:
        print(MathStatPy.P(1.1))
    except:
        print(sys.exc_info())

def Variations_test():
    """
    Permutation test
    :return:
    """
    print("Variations test.")
    print(MathStatPy.A(1, 2))
    print(MathStatPy.A(1, 4))
    print(MathStatPy.A(2, 4))
    print(MathStatPy.A(3, 4))
    print(MathStatPy.A(2, 5))
    print(MathStatPy.A(3, 5))

if __name__ == "__main__":
    Permutation_test()
    Variations_test()