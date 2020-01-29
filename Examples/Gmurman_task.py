"""
Here some examples of applying MathStatPy using task from Gmurman Victor Efimovich's tasks
book (the year of publishing is 2018). In his book there are tasks description and result answers.
"""

from MathStatPy import C
from MathStatPy import ProbabilityType as P_Type

ANSWER_FMT = "Exersize: {0:5} Answer is {1}"

def answer(ex, s):
    print(ANSWER_FMT.format(ex, s))

def ex_46():
    """
    Exercise 46 page 20.
    Text: On a library shelf in random order 15 textbooks have been placed,
    five of which with hardcover. The librarian takes three random textbooks .
    Find the probability that at least one of the textbooks taken have hardcover.
    Answer in the book: 76 / 91
    :return:
    """
    total_c = C(3, 15)
    PB = C(1, 5) * C(2, 10) / total_c
    PC = C(2, 5) * C(1, 10) / total_c
    PD = C(3, 5) / total_c
    res = PB + PC + PD
    answer("46", res)

def ex_51():
    """
    Exercise 51 page 21.
    Text: Two shooters shoot at a target. Probability hit the target with one shot for
    the first the arrow is 0.7, and for the second is 0.8. Find probability that with
    one hall the target hits only one of the shooters.
    Answer in the book: 0.38
    :return:
    """
    p1 = P_Type(0.7)
    p2 = P_Type(0.8)
    res = p1 * (~p2) + (~p1) * p2
    answer("51", res.p_value)

def ex_68():
    """
    Exercise 68 page 22.
    Text: There are five balls in the urn with numbers from 1 to 5. At random, three
    balls are taken one at a time without returning. Find the probabilities of the
    following events:
    a) balls with numbers 1, 4, 5 will appear sequentially
    b) extracted balls will have numbers 1, 4, 5 no matter in what order they
       appeared.
    Answer in the book: a) 1/60 b) 0.1
    :return:
    """
    p_A = P_Type(1/5) * P_Type(1/4) * P_Type(1/3)
    p_B = P_Type(3/5) * P_Type(2/4) * P_Type(1/3)
    answer("68 a", p_A.p_value)
    answer("68 b", p_B.p_value)

if __name__ == "__main__":
    ex_46()
    ex_51()
    ex_68()