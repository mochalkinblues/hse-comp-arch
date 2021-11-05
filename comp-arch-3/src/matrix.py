from __future__ import annotations
from abc import ABC, abstractmethod
from dataclasses import dataclass
from typing import List, Any, IO


@dataclass
class MatrixData:
    dimensionality: int
    elements: List[Any]


class Matrix(ABC):
    def __init__(self, dimensionality: int):
        self._matrix_data = MatrixData(
            dimensionality=dimensionality,
            elements=[]
        )

    @property
    def matrix_data(self) -> MatrixData:
        return self._matrix_data

    @abstractmethod
    def input(self, input_file: IO) -> IO:
        raise NotImplementedError()

    @abstractmethod
    def output(self, output_file: IO) -> None:
        raise NotImplementedError()

    @abstractmethod
    def input_random(self):
        raise NotImplementedError()

    @abstractmethod
    def arithmetic_mean(self) -> float:
        raise NotImplementedError()
