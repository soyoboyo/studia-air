#!/bin/bash
ad="adresy.txt"
tre=$(cat tresc.txt)
zal=$(find spec*.pdf)
while read line;
do  
  echo $line
  echo $tre
  echo $zal
done < $ad
