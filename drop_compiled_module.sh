#!/bin/bash

DIR=$1

if [ -z $DIR ]
then
    DIR="."
fi

rm -rf $DIR/{*.ko,*.mod,*.mod.c,*.o,*.order,*.symvers}
