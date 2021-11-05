#!/bin/sh

set -e


echo "[+] Testing..."

for number in 1 2 3 4 5
do
  echo "[+] test ${number} started" && python src/main.py -f test/input/ti${number} test/output/to${number}_1 test/output/to${number}_2 && echo ""
done

echo "[+] Testing complited"
