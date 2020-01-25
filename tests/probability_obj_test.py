import sys
from MathStatPy import ProbabilityType

TEST_ERR_FORMAT = "Test {0} failed. Result: {1} instead {2}"
TEST_OK_FORMAT = "Test {0} OK."

def init_del_obj_t():
    """
    init del object test
    :return:
    """
    test_name = "init del object"
    test_faild = False
    init_tests = [
        ["init 0.0", ProbabilityType(0.0), 0.0],
        ["init 0.1", ProbabilityType(0.1), 0.1],
        ["init 0.2", ProbabilityType(0.2), 0.2],
        ["init 1.0", ProbabilityType(1.0), 1.0],
        ["init 2.0", ProbabilityType(2.0), 1.0],
        ["init 1", ProbabilityType(1), 1.0],
        ["init 100000", ProbabilityType(100000), 1.0],
        ]
    false_init_tests = [
        ["init 0.0", -0.0],
        ["init 0.1", -210.1],
        ["init 0.2", -13],
        ["init 1.0", "kek str"],
        ["init 2.0", True],
        ]

    for test in init_tests:
        if test[1].p_value != test[2]:
            print(TEST_ERR_FORMAT.format(test[0], test[1].p_value,  test[2]))
            test_faild = True

    for test in false_init_tests:
        try:
            p = ProbabilityType(init_tests[1])
            test_faild = True
        except TypeError:
            pass
        except:
            print(TEST_ERR_FORMAT.format(test_name, init_tests[1]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

def add_t():
    """
    adding value
    :return:
    """
    test_name = "adding value"
    test_faild = False
    adding_tests = [
                  # rvalue
                  ["adding rvalue 1", ProbabilityType(0.0), 0.1, 0.1],
                  ["adding rvalue 2", ProbabilityType(0.0), 0.2, 0.2],
                  ["adding rvalue 3", ProbabilityType(0.1), 0.3, 0.4],
                  ["adding rvalue 4", ProbabilityType(0.2), 0.6, 0.8],
                  ["adding rvalue 5", ProbabilityType(0.0), 1.0, 1.0],
                  ["adding v 6", ProbabilityType(0.3), 2.0, 1.0],
                  # lvalue
                  ["adding lvalue 1", 0.1, ProbabilityType(0.0), 0.1],
                  ["adding lvalue 2", 0.2, ProbabilityType(0.0), 0.2],
                  ["adding lvalue 3", 0.3, ProbabilityType(0.1), 0.4],
                  ["adding lvalue 4", 0.6, ProbabilityType(0.2), 0.8],
                  ["adding lvalue 5", 1.0, ProbabilityType(0.0), 1.0],
                  ["adding lvalue 6", 2.0, ProbabilityType(0.3), 1.0],
                  # ProbabilityType
                  ["adding ProbabilityType 1", ProbabilityType(0.1), ProbabilityType(0.0), 0.1],
                  ["adding ProbabilityType 2", ProbabilityType(0.2), ProbabilityType(0.0), 0.2],
                  ["adding ProbabilityType 3", ProbabilityType(0.3), ProbabilityType(0.1), 0.4],
                  ["adding ProbabilityType 4", ProbabilityType(0.6), ProbabilityType(0.2), 0.8],
                  ["adding ProbabilityType 5", ProbabilityType(1.0), ProbabilityType(0.0), 1.0],
                  ["adding ProbabilityType 6", ProbabilityType(2.0), ProbabilityType(0.3), 1.0],
                ]

    for test in adding_tests:
        r = test[1] + test[2]
        if r.p_value != test[3]:
            print(TEST_ERR_FORMAT.format(test[0], r.p_value,  test[3]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

def subtruct_t():
    """
    subtracting operation test
    :return:
    """
    test_name = "subtracting operation"
    test_faild = False
    adding_tests = [
        # rvalue
        ["subtracting rvalue 1", ProbabilityType(1.0), 0.1, 0.9],
        ["subtracting rvalue 2", ProbabilityType(1.0), 0.2, 0.8],
        ["subtracting rvalue 3", ProbabilityType(1.0), 0.3, 0.7],
        ["subtracting rvalue 4", ProbabilityType(1.0), 0.99, 0.01],
        ["subtracting rvalue 5", ProbabilityType(1.0), 0.09, 0.91],
        ["subtracting rvalue 6", ProbabilityType(0.4), 0.31, 0.09],
        # lvalue
        ["subtracting lvalue 1", 1.0, ProbabilityType(0.1), 0.9],
        ["subtracting lvalue 2", 1.0, ProbabilityType(0.2), 0.8],
        ["subtracting lvalue 3", 1.0, ProbabilityType(0.3), 0.7],
        ["subtracting lvalue 4", 1.0, ProbabilityType(0.99), 0.01],
        ["subtracting lvalue 5", 1.0, ProbabilityType(0.09), 0.91],
        ["subtracting lvalue 6", 0.4, ProbabilityType(0.31), 0.09],
        # ProbabilityType
        ["subtracting ProbabilityType 1", ProbabilityType(1.0), ProbabilityType(0.1), 0.9],
        ["subtracting ProbabilityType 2", ProbabilityType(1.0), ProbabilityType(0.2), 0.8],
        ["subtracting ProbabilityType 3", ProbabilityType(1.0), ProbabilityType(0.3), 0.7],
        ["subtracting ProbabilityType 4", ProbabilityType(1.0), ProbabilityType(0.99), 0.01],
        ["subtracting ProbabilityType 5", ProbabilityType(1.0), ProbabilityType(0.09), 0.91],
        ["subtracting ProbabilityType 6", ProbabilityType(0.4), ProbabilityType(0.31), 0.09],
    ]

    for test in adding_tests:
        r = test[1] - test[2]
        if r.p_value != test[3]:
            print(TEST_ERR_FORMAT.format(test[0], r.p_value,  test[3]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

def multiply_t():
    """
    multiply operation test
    :return:
    """
    test_name = "multiply operation"
    test_faild = False
    multiply_tests = [
        # rvalue
        ["multiply rvalue 1", ProbabilityType(1.0), 0.1, 0.1],
        ["multiply rvalue 2", ProbabilityType(0.0), 0.1, 0.0],
        ["multiply rvalue 3", ProbabilityType(0.3), 0.2, 0.06],
        ["multiply rvalue 4", ProbabilityType(0.12), 0.14, 0.0168],
        ["multiply rvalue 5", ProbabilityType(1.0), 3, 3],
        # lvalue
        ["multiply rvalue 1", ProbabilityType(1.0), 0.1, 0.1],
        ["multiply rvalue 2", ProbabilityType(0.0), 0.1, 0.0],
        ["multiply rvalue 3", ProbabilityType(0.3), 0.2, 0.06],
        ["multiply rvalue 4", ProbabilityType(0.12), 0.14, 0.0168],
        ["multiply rvalue 5", ProbabilityType(1.0), 3, 3],
        # ProbabilityType
        ["multiply ProbabilityType 1", ProbabilityType(1.0), ProbabilityType(0.1), 0.1],
        ["multiply ProbabilityType 2", ProbabilityType(0.0), ProbabilityType(0.1), 0.0],
        ["multiply ProbabilityType 3", ProbabilityType(0.3), ProbabilityType(0.2), 0.06],
        ["multiply ProbabilityType 4", ProbabilityType(0.12), ProbabilityType(0.14), 0.0168],
        ["multiply ProbabilityType 5", ProbabilityType(1.0), ProbabilityType(3), 3],
    ]

    for test in multiply_tests:
        r = test[1] * test[2]
        if r.p_value != test[3]:
            print(TEST_ERR_FORMAT.format(test[0], r.p_value,  test[3]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

def ProbabilityObject_test():
    """
    ProbabilityObject test
    :return:
    """
    init_del_obj_t()
    add_t()
    subtruct_t()
    multiply_t()

if __name__ == "__main__":
    ProbabilityObject_test()
