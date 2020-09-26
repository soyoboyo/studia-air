// program with infinite loop

#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main(){
  int i = 0;
  struct timespec req = {0};
  req.tv_sec = 0;
  req.tv_nsec = 100 * 1000000L;
  while(1){
    i++;
    nanosleep(&req, (struct timespec*)NULL);
  }
  return 0;
}

/*
http://timmurphy.org/2009/09/29/nanosleep-in-c-c/
*/
