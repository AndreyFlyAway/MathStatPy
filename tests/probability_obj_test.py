import sys

def ProbabilityObject_test():
    """
    ProbabilityObject test
    :return:
    """
    from MathStatPy import ProbabilityType
    p = ProbabilityType()
    print(p)
    p.p_value = 1.1
    print(p.p_value)
    print(p.persentage())
    p.p_value = 1

if __name__ == "__main__":
    ProbabilityObject_test()
