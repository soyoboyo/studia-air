#!/bin/bash
trap 'echo "Jestem kuloodporny, strzelaj sobie ..."' 2
trap 'echo "Teraz już nie jestem kulodporny, możesz mnie unicestwić"; trap - 2 ' 1
trap 'echo "SIGALRM trap";   ' 14
trap 'echo "SIGUSR1 trap";   ' 10
trap 'echo "SIGUSR2 trap";   ' 12
trap 'echo "SIGTERM trap";   ' 15

i=0

while : 
do
  echo $i
  i=$((i + 1))
  sleep 1  
done
