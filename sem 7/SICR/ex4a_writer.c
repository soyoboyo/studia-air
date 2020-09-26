#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <rtdk.h>
#include <sys/mman.h>
#include <native/task.h>
#include <native/heap.h>


#define BUFF_LEN 16
#define ZIARNO 32574156

RT_HEAP heap;
char *cheap_buffer;
RT_TASK wri_task;
RT_SEM empty, full;

void cleanup(){
	rt_heap_unbind(%heap);
}

int main(int argc, char *argv[])
{	
	// inicjalizacja semaforów
	rt_sem_create(&empty, "readerSemaphore", BUFF_LEN, S_FIFO);
	rt_sem_create(&full, "writerSemaphore", 0, S_FIFO);
	
	rt_print_auto_init(1);
	mlockall(MCL_CURRENT | MCL_FUTURE);

	rt_heap_create(&heap, "heap", 1024, H_SHARED);
	rt_heap_alloc(&heap, 0, TM_NONBLOCK, (void **)&heap_buffer);
	
	
	rt_task_spawn(&writer, "writer", 0, 0, T_JOINABLE, &writer_func, NULL);                             v                                                 
	
	for(int i = 0; i < BUFF_LEN; i++){
		// otoczenie semaforami sekcji krytycznej
		rt_sem_p(&empty, 0); 
		
		rt_task_join(&reader); 
		
		rt_sem_v(&empty);
		rt_task_sleep(100000); 
		
		
		rt_sem_p(&full, 0);
		
		rt_task_join(&writer); 
		
		rt_sem_v(&full);
		rt_task_sleep(100000); 
	}
		
	rt_sem_delete(&empty);
	rt_sem_delete(&full);
	

	

	rt_task_join(&task1);
	
	return 0;
}
