from matrix import Matrix
from typing import List, IO
from timer import with_timer
from random_generator import get_rand_int
import sys

from two_dimensional_array import TDArray
from lower_triangular_matrix import LTMatrix
from diagonal_matrix import DMatrix

MATRIX_ARR: List[Matrix] = []


def get_matrix_by_type(matrix_type: int, dimensionality: int) -> Matrix:
    if matrix_type == 1:
        return TDArray(dimensionality)

    if matrix_type == 2:
        return LTMatrix(dimensionality)

    if matrix_type == 3:
        return DMatrix(dimensionality)


def fill_random(count: int) -> None:
    for _ in range(count):
        rand_dim = get_rand_int() + 1
        rand_type = get_rand_int() % 3 + 1
        matrix = get_matrix_by_type(rand_type, rand_dim)
        matrix.input_random()
        MATRIX_ARR.append(matrix)


def fill(file: IO) -> None:
    m_type = file.readline()
    while m_type != '':
        m_type = int(m_type)
        m_dim = int(file.readline())
        matrix = get_matrix_by_type(m_type, m_dim)
        file = matrix.input(file)
        MATRIX_ARR.append(matrix)

        m_type = file.readline()


def print_matrix_arr(file:  IO) -> None:
    for matrix in MATRIX_ARR:
        matrix.output(file)
        file.write('\n')


def quick_sort(left: int, right: int) -> None:
    i = left
    j = right
    pivot: float = MATRIX_ARR[(i + j) // 2].arithmetic_mean()

    while i <= j:
        while MATRIX_ARR[i].arithmetic_mean() > pivot:
            i += 1
        while MATRIX_ARR[j].arithmetic_mean() < pivot:
            j -= 1

        if i <= j:
            MATRIX_ARR[i], MATRIX_ARR[j] = MATRIX_ARR[j], MATRIX_ARR[i]
            i += 1
            j -= 1

        if j > left:
            quick_sort(left, j)

        if i < right:
            quick_sort(i, right)


def sort() -> None:
    quick_sort(0, len(MATRIX_ARR) - 1)


class InvalidInputException(Exception):
    message: str = 'Incorrect command\n' \
                   ' Expected:\n ' \
                   '<main.py> -f <input file> <output file 1> <output file 2>\n ' \
                   'Or:\n' \
                   '<main.py> -n <container size> <output file 1> <output file 2>\n'

    def __init__(self):
        print(self.message)


@with_timer
def main():
    read_file: IO
    write_file: IO

    if len(sys.argv) != 5:
        raise InvalidInputException()

    if sys.argv[1] == '-n':
        length: int = 0
        try:
            length = int(sys.argv[2])
            if length < 0 or length > 10000:
                raise InvalidInputException()
        except InvalidInputException:
            pass

        fill_random(length)

    if sys.argv[1] == '-f':
        try:
            read_file = open(sys.argv[2], 'r')
        except Exception:
            raise InvalidInputException()

        fill(read_file)

    write_file: IO
    try:
        write_file = open(sys.argv[3], 'w')
    except Exception:
        raise InvalidInputException

    print_matrix_arr(write_file)
    sort()

    try:
        write_file = open(sys.argv[4], 'w')
    except Exception:
        raise InvalidInputException

    print_matrix_arr(write_file)
