import sys
from MathStatPy import ProbabilityType

TEST_ERR_FORMAT = "Test {0} failed. Result: {1}"
TEST_OK_FORMAT = "Test {0} OK."

def init_del_obj_t():
    """
    init del object test
    :return:
    """
    test_name = "init del object test"
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
            print(TEST_ERR_FORMAT.format(test[0], test[1].p_value))
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
    test_name = "adding value test"
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
                ]

    for test in adding_tests:
        r = test[1] + test[2]
        if r.p_value != test[3]:
            print(TEST_ERR_FORMAT.format(test[0], r.p_value))
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

if __name__ == "__main__":
    ProbabilityObject_test()
