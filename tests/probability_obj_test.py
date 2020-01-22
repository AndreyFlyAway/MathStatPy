import sys
from MathStatPy import ProbabilityType

TEST_ERR_FORMAT = "Test {0} faild. Value is: {1}"
TEST_OK_FORMAT = "Test {0} OK."

def norm_val_t():
    """
    normal value test
    :return:
    """
    p = ProbabilityType()
    print(p)

    test_name = "normal value"
    # print(test_name)
    test_val = 0.123
    p.p_value = test_val
    if (p.p_value != test_val):
        print(TEST_ERR_FORMAT.format(test_name, p.p_value))
        return -1
    print(TEST_OK_FORMAT.format(test_name))
    return 0

def more_than_1_t():
    """
    More than 1.0 value test
    :return:
    """
    p = ProbabilityType()
    test_name = "More than 1.0 value"
    # print(test_name)
    test_val = 123.12
    p.p_value = test_val
    if (p.p_value != 1.0):
        print(TEST_ERR_FORMAT.format(test_name, p.p_value))
        return -1
    print(TEST_OK_FORMAT.format(test_name))
    return 0

def less_than_0_t():
    """
    More than 1.0 value test
    :return:
    """
    p = ProbabilityType()
    test_name = "Less than 0 value"
    # print(test_name)
    test_val = 0.0
    p.p_value = test_val
    if (p.p_value != 0.0):
        print(TEST_ERR_FORMAT.format(test_name, p.p_value))
        return -1
    print(TEST_OK_FORMAT.format(test_name))
    return 0

def negative_value_1_t():
    """
    negative value test
    :return:
    """
    p = ProbabilityType()
    test_name = "negative value"
    # print(test_name)
    try:
        test_val = -123.12
        p.p_value = test_val
    except TypeError:
        # print(sys.exc_info())
        pass
    except:
        print(TEST_ERR_FORMAT.format(test_name, p.p_value))
        return -1
    print(TEST_OK_FORMAT.format(test_name))
    return 0

def adding_value_t():
    """
    adding value
    :return:
    """
    p = ProbabilityType()
    b = ProbabilityType()
    test_name = "adding value"
    # print(test_name)
    p = ProbabilityType()
    test_val = 1.1
    v = p + test_val
    print(v)
    v = p + b
    print(v)


def ProbabilityObject_test():
    """
    ProbabilityObject test
    :return:
    """
    norm_val_t()
    more_than_1_t()
    less_than_0_t()
    negative_value_1_t()

def ProbabilityObject_test():
    """
    ProbabilityObject test
    :return:
    """
    norm_val_t()
    more_than_1_t()
    less_than_0_t()
    negative_value_1_t()
    adding_value_t()


if __name__ == "__main__":
    ProbabilityObject_test()
