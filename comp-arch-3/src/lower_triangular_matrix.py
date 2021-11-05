from typing import IO
from matrix import Matrix
from random_generator import get_rand_int


class LTMatrix(Matrix):
    def __init__(self, dimensionality: int):
        super().__init__(dimensionality)
        self.matrix_data.elements = []

    def input(self, read_file: IO) -> IO:
        size: int = self.matrix_data.dimensionality

        all_data = list(map(float, read_file.readline().split()))
        for i in range(1, size + 1):
            for _ in range(i):
                self.matrix_data.elements.append(all_data.pop())
            self.matrix_data.elements.extend([0] * (size - i))

        return read_file

    def input_random(self) -> None:
        size: int = self.matrix_data.dimensionality

        self.matrix_data.elements = [get_rand_int() for _ in range(size ** 2)]

    def output(self, write_file: IO) -> None:
        size: int = self.matrix_data.dimensionality
        col: int = 0

        write_file.write(
            f'Lower triangular matrix:\n'
            f'Dimensionality: {size}\n'
            f'Arithmetic mean: {self.arithmetic_mean()}\n'
            f'Elements: \n'
        )

        for i in range(size ** 2):
            col = i % size

            write_file.write(
                f'{self.matrix_data.elements[i]}'
                + (' ' if col != size - 1 else '\n')
            )

            col += 1

    def arithmetic_mean(self) -> float:
        size: int = self.matrix_data.dimensionality
        count: int = size ** 2
        elements_sum: int = 0
        col: int = 0

        for i in range(size ** 2):
            col = i % size

            elements_sum += self.matrix_data.elements[i]

            col += 1

        return elements_sum / count
