"""
Here some examples of applying MathStatPy using task from Gmurman Victor Efimovich's tasks
book (the year of publishing is 2018). In his book there are tasks description and result answers.
"""

from MathStatPy import C

ANSWER_FMT = "Answer is {0}"

def answer(s):
    print(ANSWER_FMT.format(s))

def ex_46():
    """
    Exercise 46 page 20.
    Answer in the book: 76 / 91
    :return:
    """
    total_c = C(3, 15)
    PB = C(1, 5) * C(2, 10) / total_c
    PC = C(2, 5) * C(1, 10) / total_c
    PD = C(3, 5) / total_c
    res = PB + PC + PD
    print(PB)
    print(PC)
    print(PD)
    answer(res)

if __name__ == "__main__":
    ex_46()