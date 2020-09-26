#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  pid_t childPid = fork();

  if(childPid > )) { 
    sleep(60);
  } else {
    exit(0);
  }
  return 0;
}
