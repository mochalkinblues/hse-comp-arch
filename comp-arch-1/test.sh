#!/bin/bash

set -e

echo "[+] Testing..."
time ./build/matrix -f test/input/ti1 test/output/to1_1 test/output/to1_2
time ./build/matrix -f test/input/ti2 test/output/to2_1 test/output/to2_2
time ./build/matrix -f test/input/ti3 test/output/to3_1 test/output/to3_2
time ./build/matrix -f test/input/ti4 test/output/to4_1 test/output/to4_2
time ./build/matrix -f test/input/ti5 test/output/to5_1 test/output/to5_2
echo "[+] Testing complited"
