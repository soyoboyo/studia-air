#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 
#define MAX_FILENAME_LEN 100
#define SHM_FILE "shm1" // It'll be placed in /dev/shm
#define SHM_FILE_PATH "/dev/shm/"SHM_FILE
 
void parentProcess();
void childProcess();
 
struct stat fileInfo; // struktura pomocnicza
int fileDescri; // deskryptor obrazka
 
// The program consists of two processes: a child and a parent.
// It creates the file and maps it to virtual memory adresses.
// The partent process asks user for names of files which will be readed
// and stored in shared memory. On the other hand, the subprocess reads
// data from mapped memory and displays images.


/*
	UWAGA UWAGA!!!
	
	część komentarzy jest po angielsku, bo szablon wziąłem ze strony http://mdrwiega.com/edu/scr1718/
	i nie usuwałem ich, bo są dobre
*/



int main(void)
{
    pid_t pid;
	
    if ((pid = fork()) == -1)
    {
        fprintf(stderr, "Error: couldn't create a subprocess.\n");
        exit(-2);
    }
    if (pid > 0)
    {
        parentProcess();
    }
    else
    {
        childProcess();
    }
    return 0;
}
 
void parentProcess()
{
    char fileName[MAX_FILENAME_LEN];
 
    // Create file used for data sharing
    FILE *memoryPtr = NULL;
	int imageFile = 0;
	char option = 'x'; // opcja
	
    while ((option != 'q') && (option != EOF))
    {
        // Unmap memory if necessary
		fclose(memoryPtr);
		
        printf("\nPlease enter the name of the image file.\n");
        scanf("%s", fileName);
        if ((imageFile = open(fileName, O_RDONLY)) == -1)
        {
            fprintf(stderr, "Error: Incorrect file path.\n");
            exit(-3);
        }
		memoryPtr = fopen(fileName, "w");
        // Get the image file statistic and resize memory file
		fstat(imageFile, &fileInfo);
		
		fileDescri = open(SHM_FILE, O_RDWR, 0666); // pobranie sektryptora pliku pamięci wspólnej
		
		ftruncate(fileDescri,fileInfo.st_size); // zmiana wielkosci pliku na wielkosz obrazka
		
        // Create a new mapping in virtual address space
		memoryPtr = mmap(NULL, fileInfo.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fileDescri, 0);
		
        // Read data from file and write it to the memory.
		read(imageFile, memoryPtr, fileInfo.st_size);
		
		msync((void*)memoryPtr, fileInfo.st_size, MS_SYNC); // synchornonizacja
	
		close(imageFile); // zamknięcie pliku
	
		close(fileDescri); // zamknięcie deskryptora pliku
		
        printf("\nPush 't' to load next file. Otherwise push 'q'.\n");
        while ((option = getc(stdin)) == '\n');
		
		munmap(&fileInfo, fileInfo.st_size); // zwolnienie obszaru
    }
}
 
void childProcess()
{
	// Check if first image has been written and print all received images
	while(fileInfo.st_size == 0){
		stat(SHM_FILE, &fileInfo);
	}
	execlp("dispay", "display", "-update", "1", SHM_FILE , NULL);
	
}
