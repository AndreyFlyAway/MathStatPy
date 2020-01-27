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
        ["init none", ProbabilityType(), 0.0],
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
        ["subtracting rvalue 1", ProbabilityType(1.0), 0.1, 1.0 - 0.1],
        ["subtracting rvalue 2", ProbabilityType(1.0), 0.2, 1.0 - 0.2],
        ["subtracting rvalue 3", ProbabilityType(1.0), 0.3, 1.0 - 0.3],
        ["subtracting rvalue 4", ProbabilityType(1.0), 0.99, 1 - 0.99],
        ["subtracting rvalue 5", ProbabilityType(1.0), 0.09, 1 - 0.09],
        ["subtracting rvalue 6", ProbabilityType(0.4), 0.31, 0.4 - 0.31],
        # lvalue
        ["subtracting lvalue 1", 1.0, ProbabilityType(0.1),  1.0 - 0.1],
        ["subtracting lvalue 2", 1.0, ProbabilityType(0.2), 1.0 - 0.2],
        ["subtracting lvalue 3", 1.0, ProbabilityType(0.3), 1.0 - 0.3],
        ["subtracting lvalue 4", 1.0, ProbabilityType(0.99), 1 - 0.99],
        ["subtracting lvalue 5", 1.0, ProbabilityType(0.09), 1 - 0.09],
        ["subtracting lvalue 6", 0.4, ProbabilityType(0.31), 0.4 - 0.31],
        # ProbabilityType
        ["subtracting ProbabilityType 1", ProbabilityType(1.0), ProbabilityType(0.1), 1.0 - 0.1],
        ["subtracting ProbabilityType 2", ProbabilityType(1.0), ProbabilityType(0.2), 1.0 - 0.2],
        ["subtracting ProbabilityType 3", ProbabilityType(1.0), ProbabilityType(0.3), 1.0 - 0.3],
        ["subtracting ProbabilityType 4", ProbabilityType(1.0), ProbabilityType(0.99), 1 - 0.99],
        ["subtracting ProbabilityType 5", ProbabilityType(1.0), ProbabilityType(0.09), 1 - 0.09],
        ["subtracting ProbabilityType 6", ProbabilityType(0.4), ProbabilityType(0.31), 0.4 - 0.31],
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
        ["multiply rvalue 0", ProbabilityType(0.0), 0.1, 0.0 * 0.1],
        ["multiply rvalue 1", ProbabilityType(1.0), 0.1, 1.0 * 0.1],
        ["multiply rvalue 2", ProbabilityType(0.0), 0.1, 0.0 * 0.1],
        ["multiply rvalue 3", ProbabilityType(0.3), 0.2, 0.3 * 0.2],
        ["multiply rvalue 4", ProbabilityType(0.12), 0.14, 0.12 * 0.14],
        ["multiply rvalue 5", ProbabilityType(1.0), 3, 1.0],
        # lvalue
        ["multiply rvalue 1", ProbabilityType(1.0), 0.1, 1.0 * 0.1],
        ["multiply rvalue 2", ProbabilityType(0.0), 0.1, 0.0 * 0.1],
        ["multiply rvalue 3", ProbabilityType(0.3), 0.2, 0.3 * 0.2],
        ["multiply rvalue 4", ProbabilityType(0.12), 0.14, 0.12 * 0.14],
        ["multiply rvalue 5", ProbabilityType(1.0), 3, 1.0],
        # ProbabilityType
        ["multiply ProbabilityType 1", ProbabilityType(1.0), ProbabilityType(0.1), 1.0 * 0.1],
        ["multiply ProbabilityType 2", ProbabilityType(0.0), ProbabilityType(0.1), 0.0 * 0.1],
        ["multiply ProbabilityType 3", ProbabilityType(0.3), ProbabilityType(0.2), 0.3 * 0.2],
        ["multiply ProbabilityType 4", ProbabilityType(0.12), ProbabilityType(0.14), 0.12 * 0.14],
        ["multiply ProbabilityType 5", ProbabilityType(1.0), ProbabilityType(3), 1.0],
    ]

    for test in multiply_tests:
        r = test[1] * test[2]
        if r.p_value != test[3]:
            print(TEST_ERR_FORMAT.format(test[0], r.p_value,  test[3]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

def div_t():
    """
    divmod operation test
    :return:
    """
    test_name = "div operation"
    test_faild = False
    div_tests = [
        # rvalue
        ["div rvalue 1", ProbabilityType(0.0), 0.1, 0.0/0.1],
        ["div rvalue 2", ProbabilityType(0.1), 0.1, 0.1/0.1],
        ["div rvalue 3", ProbabilityType(0.1), 0.3, 0.1/0.3],
        ["div rvalue 4", ProbabilityType(0.3), 0.3, 0.3/0.3],
        ["div rvalue 5", ProbabilityType(0.3), 0.1, 1.0],
        # lvalue
        ["div rvalue 1", 0.0, ProbabilityType(0.1), 0.0/0.1],
        ["div rvalue 2", 0.1, ProbabilityType(0.1), 0.1/0.1],
        ["div rvalue 3", 0.1, ProbabilityType(0.3), 0.1/0.3],
        ["div rvalue 4", 0.3, ProbabilityType(0.3), 0.3/0.3],
        ["div rvalue 5", 0.3, ProbabilityType(0.1), 1.0],
        # ProbabilityType
        ["div ProbabilityType 1", ProbabilityType(0.0), ProbabilityType(0.1), 0.0/0.1],
        ["div ProbabilityType 2", ProbabilityType(0.1), ProbabilityType(0.1), 0.1/0.1],
        ["div ProbabilityType 3", ProbabilityType(0.1), ProbabilityType(0.3), 0.1/0.3],
        ["div ProbabilityType 4", ProbabilityType(0.3), ProbabilityType(0.3), 0.3/0.3],
        ["div ProbabilityType 5", ProbabilityType(0.3), ProbabilityType(0.1), 1.0],
    ]

    for test in div_tests:
        r = test[1] / test[2]
        if r.p_value != test[3]:
            print(TEST_ERR_FORMAT.format(test[0], r.p_value,  test[3]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

def remainder_o():
    """
    remainder operation test
    :return:
    """
    test_name = "remainder operation"
    test_faild = False
    remainder_tests = [
        # rvalue
        ["remainder rvalue 1", ProbabilityType(0.0), 0.1, 0.0%0.1],
        ["remainder rvalue 2", ProbabilityType(0.3), 0.2, 0.3%0.2],
        ["remainder rvalue 3", ProbabilityType(0.5), 0.2, 0.5%0.2],
        ["remainder rvalue 4", ProbabilityType(0.7), 0.21, 0.7%0.21],
        ["remainder rvalue 5", ProbabilityType(0.0), 0.21312, 0.0%0.21312],
        # lvalue
        ["remainder rvalue 1", 0.0, ProbabilityType(0.1), 0.0%0.1],
        ["remainder rvalue 2", 0.3, ProbabilityType(0.2), 0.3%0.2],
        ["remainder rvalue 3", 0.5, ProbabilityType(0.2), 0.5%0.2],
        ["remainder rvalue 4", 0.7, ProbabilityType(0.21), 0.7%0.21],
        ["remainder rvalue 5", 0.0, ProbabilityType(0.21312), 0.0%0.21312],
        # ProbabilityType
        ["remainder ProbabilityType 1", ProbabilityType(0.0), ProbabilityType(0.1), 0.0%0.1],
        ["remainder rvalue 2", ProbabilityType(0.3), ProbabilityType(0.2), 0.3%0.2],
        ["remainder rvalue 3", ProbabilityType(0.5), ProbabilityType(0.2), 0.5%0.2],
        ["remainder rvalue 4", ProbabilityType(0.7), ProbabilityType(0.21), 0.7%0.21],
        ["remainder rvalue 5", ProbabilityType(0.0), ProbabilityType(0.21312), 0.0%0.21312],
    ]

    for test in remainder_tests:
        r = test[1] % test[2]
        if r.p_value != test[3]:
            print(TEST_ERR_FORMAT.format(test[0], r.p_value,  test[3]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

def pow_t():
    """
    power operation test
    :return:
    """
    test_name = "pow operation"
    test_faild = False
    pow_tests = [
        ["pow 1", ProbabilityType(0.0), 0, 0.0 ** 0],
        ["pow 1", ProbabilityType(0.1), 0, 0.1 ** 0],
        ["pow 2", ProbabilityType(0.1), 1, 0.1 ** 1],
        ["pow 3", ProbabilityType(0.1), 2, 0.1 ** 2],
        ["pow 4", ProbabilityType(0.13), 3, 0.13 ** 3],
        ["pow 5", ProbabilityType(0.1334), 4, 0.1334 ** 4],
    ]

    for test in pow_tests:
        r = test[1] ** test[2]
        if r.p_value != test[3]:
            print(TEST_ERR_FORMAT.format(test[0], r.p_value,  test[3]))
            test_faild = True

    if (not(test_faild)):
        print (TEST_OK_FORMAT.format(test_name))

def invert_t():
    """
    ivernt operation test
    :return:
    """
    test_name = "ivernt operation"
    test_faild = False
    pow_tests = [
        ["ivernt 1", ProbabilityType(0.0), 1.0 - 0.0],
        ["ivernt 2", ProbabilityType(0.1), 1.0 - 0.1],
        ["ivernt 3", ProbabilityType(0.4), 1.0 - 0.4],
        ["ivernt 4", ProbabilityType(0.31234), 1.0 - 0.31234],
        ["ivernt 5", ProbabilityType(0.999999), 1.0 - 0.999999],
        ["ivernt 6", ProbabilityType(1.0), 1.0 - 1.0],
    ]

    for test in pow_tests:
        r = ~test[1]
        if r.p_value != test[2]:
            print(TEST_ERR_FORMAT.format(test[0], r.p_value,  test[2]))
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
    div_t()
    remainder_o()
    pow_t()
    invert_t()

if __name__ == "__main__":
    ProbabilityObject_test()
