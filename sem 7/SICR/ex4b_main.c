#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <rtdk.h>
#include <math.h>
#include <sys/mman.h>
#include <native/task.h>
#include <native/mutex.h>
#include <native/queue.h>

#define BUFF_LEN 3
#define ZIARNO 32574156

RT_TASK task1, task2, task3;
RT_MUTEX moj_mutex;
RT_QUEUE kolejka;

int iteracja= 10000;

void func(void *arg){
	int i = 0;
	double x = 0;
	double y = 0;
	double z = 0;
	int pi = 0;
	srand(ZIARNO);
	for (i = 0; i < iteracja; i++){
		// dopisac co nieco	
		if(z <= 1){
			pi+=1;
		}
	}
//mutex, zapis do kolejk, zwolnienie muteksu
}


int main(int argc, char *argv[])
{	
	int odczytane = 0;
	int buff = 0;
	int wynik = 0;
	int N = 3;	
	rt_queue_create(&kolejka,"kolejka", 255, N, 0);
	rt_mutex_create(&moj_mutex,"MojMutex");
	rt_print_auto_init(1);
	mlockall(MCL_CURRENT | MCL_FUTURE);

//mieso do odczytywania

	rt_task_join(&task1);
	rt_task_join(&task2);
	rt_task_join(&task3);

	rt_printf("Wynik %d\n", wynik);
	rt_mutex_release(&moj_mutex);
	return 0;
}
