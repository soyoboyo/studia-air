#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/*
  Utworzenie potoku FIFO i poprawne przesłanie danych między procesami – 6 pkt
  Obsługa wielu plików w pętli nieskończonej – 2 pkt
  Styl: formatowanie kodu, odpowiednie nazwy zmiennych, kompilacja bez ostrzeżeń – 2 pkt
*/

#define BUFFER 64
#define FIFONAME "potok"

void parentProcess(){
  
  // tworzenie potoku fifo
  mknod(FIFONAME, S_IFIFO|0666, 0);
  
  
  int potokOpen = open(FIFONAME, O_WRONLY); // otwarcie potoku do zapisu
	
  while(1){
  char fileName[100];
  printf("Enter file name: [q to exit]\n");
  scanf("%s", fileName);
  if(fileName[0] == 'q')
    break;

  int file = open(fileName, O_RDONLY);
  
  char fileMeat[BUFFER];
  int sliceLength;
  // wpisywanie zawartości pliku do potoku
    while((sliceLength = read(file, fileMeat, BUFFER)) > 0){
      write(potokOpen, fileMeat, sliceLength);
    }
  
  close(file);  
    
  } // while(1)
  
  close(potokOpen); // zamknięcie potoku 
}

void childProcess(){
  
  execlp("tail", "tail", "+1cf", FIFONAME, NULL);
 // execlp("display", "display", "-delay", "1", FIFONAME);
	
}

int main() {
  
  system("rm -f potok"); // usuwanie potoku
  
  pid_t pid;
  pid = fork();
  if (pid == -1) {
    fprintf(stderr, "Error: couldn't create a subprocess.\n");
  exit(-2);
  }
  if (pid > 0) {
	printf("Parent process\n");
	parentProcess();
	
	wait(NULL);
	
  } else {
	printf("Child process\n");
	childProcess();
  }
  
  return 0;
}
 
