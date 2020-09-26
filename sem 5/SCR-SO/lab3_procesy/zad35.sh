#!/bin/bash

trap 'echo "SIGHUP trap"' 1
trap 'echo "SIGINT trap"' 2
trap 'echo "SIGQUIT trap"' 3
trap 'echo "SIGILL trap"' 4
trap 'echo "SIGTRAP trap"' 5
trap 'echo "SIGHABRT trap"' 6
trap 'echo "SIGBUS trap"' 7
trap 'echo "SIGFPE trap"' 8
trap 'echo "SIGKILL trap"' 9
trap 'echo "SIGUSR1 trap"' 10
trap 'echo "SIGSEGV trap"' 11
trap 'echo "SIGUSR2 trap"' 12
trap 'echo "SIGPIPE trap"' 13
trap 'echo "SIGALRM trap"' 14
trap 'echo "SIGTERM trap"' 15

echo "Current time and date:" 
while :
do
  date "+%H:%M:%S %d/%m/%y" &
  sleep 1 
done
