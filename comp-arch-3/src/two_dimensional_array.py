from matrix import Matrix
from random_generator import get_rand_int

from typing import IO


class TDArray(Matrix):
    def __init__(self, dimensionality: int):
        super().__init__(dimensionality)
        self.matrix_data.elements = [[]]

    def input(self, read_file: IO) -> IO:
        size: int = self.matrix_data.dimensionality
        col: int = 0
        row: int = 0

        all_data = list(map(float, read_file.readline().split()))[::-1]
        self.matrix_data.elements = [
            [all_data.pop() for _ in range(size)]
            for _ in range(size)
        ]

        return read_file

    def input_random(self) -> None:
        size: int = self.matrix_data.dimensionality

        self.matrix_data.elements = [
            [get_rand_int() for _ in range(size)]
            for _ in range(size)
        ]

    def output(self, write_file: IO) -> None:
        size: int = self.matrix_data.dimensionality
        col: int = 0
        row: int = 0

        write_file.write(
            f'Two dimensional array:\n'
            f'Dimensionality: {size}\n'
            f'Arithmetic mean: {self.arithmetic_mean()}\n'
            f'Elements: \n'
        )

        for i in range(size ** 2):
            col = i % size
            row = i // size

            write_file.write(
                f'{self.matrix_data.elements[row][col]}'
                + (' ' if col != size - 1 else '\n')
            )

            col += 1

    def arithmetic_mean(self) -> float:
        size: int = self.matrix_data.dimensionality
        count: int = size ** 2
        elements_sum: float = 0
        col: int = 0
        row: int = 0

        for i in range(size ** 2):
            col = i % size
            row = i // size

            elements_sum += self.matrix_data.elements[row][col]

            col += 1

        return elements_sum / count
