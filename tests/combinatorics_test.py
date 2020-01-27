import MathStatPy
import sys
# TODO: make more complete test

TEST_ERR_FORMAT = "Test {0} failed. Result: {1} instead {2}"
TEST_OK_FORMAT = "Test {0} OK."

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
    print("Variations out of range test.")
    try:
        print(MathStatPy.A(-1))
    except:
        print(sys.exc_info())
    try:
        print(MathStatPy.A(-1, 2))
    except:
        print(sys.exc_info())
    try:
        print(MathStatPy.A(2, -3))
    except:
        print(sys.exc_info())
    try:
        print(MathStatPy.A(25, 13))
    except:
        print(sys.exc_info())

def Combinations_test():
    """
    Permutation test
    :return:
    """
    test_name = "Combinations value"
    test_faild = False
    adding_tests = [
                  # rvalue
                  ["C(1,1)", 1, 1, 1],
                  ["C(1,2)", 1, 2, 2],
                  ["C(1,3)", 1, 3, 3],
                  ["C(1,4)", 1, 4, 4],
                  ["C(1,5)", 1, 5, 5],
                  ["C(1,6)", 1, 6, 6],
                  ["C(2,4)", 2, 4, 6],
                  ["C(3,4)", 3, 4, 4],
                  ["C(3,6)", 3, 6, 20],
                  ["C(3,4)", 3, 7, 35],
                  ["C(4,7)", 4, 7, 35],
                  ["C(4,8)", 4, 8, 70],
                  ["C(5,13)", 5, 13, 1287],
                  ["C(6,13)", 6, 13, 1716],
                ]

    for test in adding_tests:
        r = MathStatPy.C(test[1], test[2])
        if r != test[3]:
            print(TEST_ERR_FORMAT.format(test[0], r,  test[3]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

if __name__ == "__main__":
    # Permutation_test()
    # Variations_test()
    Combinations_test()