#!/bin/bash

echo 'Enter filename:'
read n

file='files/'$n

if [ -f $file ]
then
    wc -l $file
else
    touch $file
fi

