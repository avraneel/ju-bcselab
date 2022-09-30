#!/bin/bash

read -p 'Enter filename: ' f
read -p 'Enter words: ' w

#f='files/q6.txt'
#w='sky'

file=$(<$f) 
c=0

for var in $file
do 
    if [ $var == $w ]; then
        c=$(expr $c + 1)
    fi
done

echo 'Total no. of occurences: ' $c

echo 'Line numbers: '
grep -n $w $f 

c=0

echo 'Number of occurences in each line: '

while read line;
do
    for i in $line;
    do
        if [ $i == $w ]; then
            c=$(expr $c + 1)
        fi
    done
    echo $c
    c=0
done < $f

