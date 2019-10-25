#!/bin/sh

for OUT in $(ls Tests/)
do
gcc get_next_line.c get_next_line_utils.c main.c -D FN=\"Tests/$OUT\"
./a.out > cmp
echo "$OUT:"
if cmp -s "cmp" "Tests/$OUT"
then
echo "test succeeded"
else
echo "TEST FAILED"
fi
#echo $DIFF
done