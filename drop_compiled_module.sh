#!/bin/bash

TEST=$1

if [ -z $TEST ]
then
    TEST="."
fi

rm -rf $TEST/{*.ko,*.mod,*.mod.c,*.o,*.order,*.symvers}
