#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <rtdk.h>
#include <math.h>
#include <sys/mman.h>
#include <native/task.h>
#include <native/heap.h>


#define BUFF_LEN 16
#define ZIARNO 32574156

RT_TASK read_task;
RT_SEM empyt, full;

int main(int argc, char *argv[])
{	

	rt_task_spawn(&reader, "reader", 0, 0, T_JOINABLE, &reader_func, NULL);
	
	rt_sem_bind(&empty, "empty", TM_NONBLOCK);
	rt_sem_bind(&full, "full", TM_NONBLOCK);

	rt_sem_unbind();

	rt_task_join(&task1);

	return 0;
}

