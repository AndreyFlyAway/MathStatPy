import MathStatPy

def Permutation_test():
    """
    Permutation test
    :return:
    """
    print("Permutation test.")
    #print(help(MathStatPy.P))
    for i in range(0, 10):
        print(MathStatPy.P(i))

if __name__ == "__main__":
    Permutation_test()