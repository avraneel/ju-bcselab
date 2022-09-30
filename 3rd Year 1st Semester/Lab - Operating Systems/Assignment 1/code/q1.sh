#!/bin/bash

echo 'Enter variable 1:'
read uv1
echo 'Enter variable 2:'
read uv2

echo "Values = $uv1 , $uv2"
echo "Values and = $uv1 and $uv2"

echo $uv1 | rev
echo $uv2 | rev

exit 0