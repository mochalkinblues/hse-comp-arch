from time import time
from typing import Callable


def with_timer(func: Callable):
    def wrapper():
        time_start = time()
        print('[+] its all started.')
        func()
        time_end = time()
        print(f'[+] finished. it took {time_end - time_start} secs.')
    return wrapper()
