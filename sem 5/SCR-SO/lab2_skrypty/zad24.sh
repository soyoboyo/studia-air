#!/bin/bash

usage() { echo "$0 usage: cos tam jakies poradnik uzywania"; exit 0; }
#default values
N="def"
mask="def"
tarName="def"


while getopts ":n:m:a:" opt; 
do
  case "${opt}" in
    n) N=${OPTARG}
       echo "N = ${N}"
      ;;
    m) mask=${OPTARG}
       echo "mask = ${mask}"
      ;;
    a) tarName=${OPTARG}
       echo "tar name is ${tarName}"
      ;;
    h | * ) usage 
      exit 0 ;;
  esac
done


if [ "$N" = "def" ]; then
  read -p "missing argument -n, input now please  " input 
  N=$input
fi

if [ "$mask" = "def" ]; then
  read -p "missing argument -m, input now please  " input
  mask="$input"
fi
if [ "$tarName" = "def" ]; then
  read -p "missing argument -a, input now please  " input
  tarName=$input
fi

echo "N = $N"
echo "mask = ${mask}"

files=$( find ${mask} -mtime $N )
tar -cf '$tarName' $pliki
