import sys
from MathStatPy import ProbabilityType

TEST_ERR_FORMAT = "Test {0} faild. Value is: {1}"
TEST_OK_FORMAT = "Test {0} OK."

def init_del_obj_t():
    """
    init del object test
    :return:
    """
    va = 1 ; a_p_val = 1.0
    vb = 1.0 ; b_p_val = 1.0
    vc = 2.0 ; c_p_val = 1.0
    ve = 0.0 ; e_p_val = 0.0
    vf = -3.0 ; f_p_val = 0.0
    vs = "sadas"
    test_name = "init del object test"
    a = ProbabilityType()
    b = ProbabilityType(1)
    c = ProbabilityType(1.0)
    d = ProbabilityType(2.0)
    e = ProbabilityType(0.0)
    # f = ProbabilityType(-3.0)
    if (a.p_value != a_p_val):
        print(TEST_ERR_FORMAT.format(test_name, a.p_value))
        return -1
    if (b.p_value != b_p_val):
        print(TEST_ERR_FORMAT.format(test_name, b.p_value))
        return -1
    if (c.p_value != c_p_val):
        print(TEST_ERR_FORMAT.format(test_name, c.p_value))
        return -1
    if (e.p_value != e_p_val):
        print(TEST_ERR_FORMAT.format(test_name, e.p_value))
        return -1
    # if (f.p_value != f_p_val):
    #     print(TEST_ERR_FORMAT.format(test_name, f.p_value))
    #     return -1







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
    test_val = 0.12
    p = ProbabilityType()
    b = ProbabilityType()
    p.p_value = 0.2
    b.p_value = 0.3
    test_val = 1.1
    v = p.p_value + test_val
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
    # init_del_obj_t()
    norm_val_t()
    more_than_1_t()
    less_than_0_t()
    negative_value_1_t()
    adding_value_t()


if __name__ == "__main__":
    ProbabilityObject_test()
