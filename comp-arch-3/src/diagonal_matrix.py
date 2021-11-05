from typing import IO

from matrix import Matrix
from random_generator import get_rand_int


class DMatrix(Matrix):
    def __init__(self, dimensionality: int):
        super().__init__(dimensionality)
        self.matrix_data.elements = []

    def input(self, read_file: IO) -> IO:
        self.matrix_data.elements = list(map(float, read_file.readline().split()))

        return read_file

    def input_random(self) -> None:
        size = self.matrix_data.dimensionality

        self.matrix_data.elements = [get_rand_int() for _ in range(size)]

    def output(self, write_file: IO) -> None:
        size: int = self.matrix_data.dimensionality
        col: int = 0
        row: int = 0
        curr: int = 0

        write_file.write(
            f'Diagonal matrix:\n'
            f'Dimensionality: {size}\n'
            f'Arithmetic mean: {self.arithmetic_mean()}\n'
            f'Elements: \n'
        )

        for i in range(size ** 2):
            col = i % size
            row = i // size

            if col == row:
                write_file.write(f'{self.matrix_data.elements[curr]} ')
                curr += 1
            else:
                write_file.write('0 ')

            col += 1

            if col == size:
                write_file.write('\n')

    def arithmetic_mean(self) -> float:
        size: int = self.matrix_data. dimensionality
        elements_sum: float = 0

        for i in range(size):
            elements_sum += self.matrix_data.elements[i]

        return elements_sum / size
