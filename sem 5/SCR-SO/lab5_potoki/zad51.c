#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>


#define SIZE 1048576

/*
    Utworzenie procesu nadrzędnego i podprocesu – 2 pkt
    Utworzenie potoku i poprawne przesłanie danych między procesami – 4 pkt
    Przekierowanie strumienia stdin na potok i uruchomienie programu do wyświetlania obrazków – 2 pkt
    Styl: formatowanie kodu, odpowiednie nazwy zmiennych, kompilacja bez ostrzeżeń – 2 pkt
*/

int main()
{
  int pipeFd[2];
  pid_t pid;
  
  int fileSize; // ilosc bajtow
  char fileName[64]; // bufor na nazwe pliku
  char file[SIZE]; // bufor na plik
  FILE *fileIn = NULL;

  printf("Process PID = %d\n", getpid());
  
  pid = fork(); // utworzenie procesu nadrzędnego i podprocesu 
  
  pipe(pipeFd); // tworzenie potoku
  
  if(pid == -1) {
    fprintf(stderr, "Error - pid.\n");
    return 0;
  } else if(pid > 0){
    printf("Parent process PID = %d\n", getpid());
    close(pipeFd[0]); // zamkniecie potoku

    printf("Podaj nazwe pliku:\n");
    scanf("%s", fileName);
    printf("fileName = %s", fileName);
    sleep(5);

    fileIn = fopen(fileName, "r"); // otworzenia pliku
    if(fileIn == NULL){
      printf("Error - cant open file.\n");
    } else {
      fileSize = fread(file, 1, SIZE, fileIn); // wczytanie obrazka
      fclose(fileIn); 
      write(pipeFd[1], file, fileSize);
      close(pipeFd[1]); // zamkniecie deskryptora do pisania
      wait(NULL); // oczekiwanie na smierc dziecka (procesu)
    }
  } else if(pid == 0) { 
    printf("Child process PID = %d\n", getpid());
    close(0); // zamkniecie std
    dup(pipeFd[0]); // duplikacja
    close(pipeFd[0]); // zamkniecie potoku
    close(pipeFd[1]); // zamkniecie potoku
    close(1); // zamkniecie deskryptora
    execlp("display", "display", NULL); // wyswietlenie obrazka
  }

  return 0;
}

