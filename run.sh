#!/bin/sh

MAX_ITER=20
CUR_ITER=0
NUM=8
while [ "$CUR_ITER" -lt "$MAX_ITER" ]
do
    ./bitsor "$NUM"
    CUR_ITER=`expr $CUR_ITER + 1`
    NUM=`expr 2 \* $NUM`
done
