#include <unistd.h>
#include <sys/mman.h>
#include <native/task.h>
#include <rtdk.h>
#include <native/mutex.h>

RT_TASK task1, task2, task3;
int questions_num = 5;
int have_tickets = 1;

void func(void *arg)
{
	int answered_num = 0;

	RT_TASK_INFO info;
	rt_task_inquire(rt_task_self(), &info);
	while(have_tickets) {
		rt_task_sleep(1000000);
		if (questions_num == 0)
		  break;
		questions_num--;
		answered_num++;
		rt_printf("%s got point! (%d questions left)\n", info.name, questions_num);
	}
	rt_printf("Game over. %s got %d points.\n", info.name, answered_num);
}

int main(int argc, char *argv[])
{
	rt_print_auto_init(1);
	mlockall(MCL_CURRENT | MCL_FUTURE);

	//int rt_mutex_create(RT_MUTEX *mutex, const char *name);

	rt_task_spawn(&task1, "A", 0, 0, T_JOINABLE, &func, NULL);
	rt_task_spawn(&task2, "B", 0, 0, T_JOINABLE, &func, NULL);
	rt_task_spawn(&task3, "C", 0, 0, T_JOINABLE, &func, NULL);

	/* oczekiwanie na zakonczenie sie zadan */
	rt_task_join(&task1);
	rt_task_join(&task2);
	rt_task_join(&task3);
	return 0;
}

