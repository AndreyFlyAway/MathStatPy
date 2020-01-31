import MathStatPy
import sys
import math
# TODO: make more complete test

TEST_ERR_FORMAT = "Test {0} failed. Result: {1} instead {2}"
TEST_OK_FORMAT = "Test {0} OK."

def Permutation_test():
    """
    Permutation test
    :return:
    """
    test_name = "Permutation value"
    test_faild = False
    adding_tests = [
        ["P(0)", 0, math.factorial(0)],
        ["P(1)", 1, math.factorial(1)],
        ["P(2)", 2, math.factorial(2)],
        ["P(3)", 3, math.factorial(3)],
        ["P(4)", 4, math.factorial(4)],
        ["P(5)", 5, math.factorial(5)],
        ["P(6)", 6, math.factorial(6)],
        ["P(7)", 7, math.factorial(7)],
        ["P(8)", 8, math.factorial(8)],
        ["P(9)", 9, math.factorial(9)],
        ["P(10)", 10, math.factorial(10)],
        ["P(20)", 20, math.factorial(20)],
    ]

    for test in adding_tests:
        r = MathStatPy.P(test[1])
        if r != test[2]:
            print(TEST_ERR_FORMAT.format(test[0], r,  test[2]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

def Variations_test():
    """
    Variations test
    :return:
    """
    test_name = "Variations value"
    test_faild = False
    adding_tests = [
        ["A(1, 1)", 1, 1, 1],
        ["A(1, 2)", 1, 2, 2],
        ["A(2, 3)", 2, 3, 6],
        ["A(3, 5)", 3, 5, 60],
    ]

    for test in adding_tests:
        r = MathStatPy.A(test[1], test[2])
        if r != test[3]:
            print(TEST_ERR_FORMAT.format(test[0], r,  test[3]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

def Combinations_test():
    """
    Permutation test
    :return:
    """
    test_name = "Combinations value"
    test_faild = False
    adding_tests = [
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
    Permutation_test()
    Variations_test()
    Combinations_test()