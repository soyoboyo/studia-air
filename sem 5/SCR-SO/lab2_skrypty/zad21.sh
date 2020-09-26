#!/bin/bash
DAY=`date +%u`
export LC_ALL=C.UTF8

if [ "$DAY" -le 5 ]; then
  echo "workday"
else 
  echo "weekend"
fi
