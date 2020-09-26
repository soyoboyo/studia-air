#!/bin/bash

echo $1
echo $2
echo $3

pliki=$( find $1 -mtime $3 )
tar -cf $2 $pliki


