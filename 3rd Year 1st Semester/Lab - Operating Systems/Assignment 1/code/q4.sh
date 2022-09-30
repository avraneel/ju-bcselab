#!/bin/bash

DELETED='my-deleted-files'

while getopts ":c" option; do
  case $option in
    c) cd $DELETED; rm *; exit;;
  esac
done

read -p 'Enter filename: ' FILE

l=${#FILE}

check=$(ls $DELETED | grep $FILE)

c=0

if [ $check == $FILE ]      #file exists in folder
then
    #echo 'if block'
    OLD_FILE=${FILE:0:l-4}$c${FILE:l-4:l-1}
    touch $DELETED'/'$OLD_FILE
    c=$(expr $c + 1)
    NEW_FILE=${FILE:0:l-4}$c${FILE:l-4:l-1}
    touch $DELETED'/'$NEW_FILE
    mv $DELETED'/'$FILE $DELETED'/'$OLD_FILE
    mv $FILE $DELETED'/'$NEW_FILE
else
    #echo 'else block'
    mv $FILE $DELETED
fi

#echo $c