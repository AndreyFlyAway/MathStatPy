import sys

def ProbabilityObject_test():
    """
    ProbabilityObject test
    :return:
    """
    from MathStatPy import ProbabilityType
    p = ProbabilityType()
    print(p)
    p.p_value = 0.785
    print(p.p_value)
    print(p.persentage())

if __name__ == "__main__":
    ProbabilityObject_test()
