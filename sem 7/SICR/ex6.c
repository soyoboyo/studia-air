#include <rtdk.h>
#include <unistd.h>
#include <sys/mman.h>
#include <native/task.h>
#include <native/mutex.h>


const long SLEEP_TIME = 10000000;

RT_TASK task1, task2, task3;
RT_MUTEX mutex;

int licz = 0;


void taskOne()
{
    int liczLocal, i = 20;
	RT_TASK_INFO info;
	rt_task_inquire(rt_task_self(), &info);
    
    while(i) {
        liczLocal = licz;
        liczLocal++;
        
        rt_mutex_acquire(&mutex, TM_INFINITE);
        licz = liczLocal;
        rt_mutex_release(&mutex);
        
        rt_printf("1 licz = %d\n", licz);
        rt_task_sleep(SLEEP_TIME);
		i--;
	}
}

void taskTwo()
{
    int liczLocal, i = 20;
	RT_TASK_INFO info;
	rt_task_inquire(rt_task_self(), &info);
    
    while(i) {
        liczLocal = licz;
        liczLocal++;
        
        rt_mutex_acquire(&mutex, TM_INFINITE);
        licz = liczLocal;
        rt_mutex_release(&mutex);
        
        rt_printf("1 licz = %d\n", licz);
        rt_task_sleep(SLEEP_TIME);
		i--;
	}

}

void taskThree(void *arg)
{
   
	int i = 20;
	RT_TASK_INFO info;
	rt_task_inquire(rt_task_self(), &info);
    
    while(i) {
        
        rt_mutex_acquire(&mutex, TM_INFINITE);
        licz++;
        rt_mutex_release(&mutex);
        
        rt_printf("3 licz = %d\n", licz);
        rt_task_sleep(SLEEP_TIME);
		i--;
	}

}


void catch_sig(int s)
{
	rt_task_delete(&task1);
    rt_task_delete(&task2);
    rt_task_delete(&task3);
}


int main()
{
    signal(SIGINT, catch_sig);

    rt_print_auto_init(1);
	mlockall(MCL_CURRENT | MCL_FUTURE);

    rt_mutex_create(&mutex, "Mutex");

	rt_task_spawn(&task1, "task1", 0, 0, 0, &taskOne, NULL);
    rt_task_spawn(&task2, "task2", 0, 10, 0, &taskTwo, NULL);
    rt_task_spawn(&task3, "task3", 0, 20, 0, &taskThree, NULL);
	
    rt_task_join(&task1);
	rt_task_join(&task2);
	rt_task_join(&task3);

	rt_task_delete(&task1);
    rt_task_delete(&task2);
    rt_task_delete(&task3);
	
	
    rt_mutex_delete(&mutex);

    pause();

	return 0;
}
