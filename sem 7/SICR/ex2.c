#include <signal.h>
#include <unistd.h>
#include <sys/mman.h>
#include <native/task.h>
#include <native/timer.h>
#include <rtdk.h>

const long long SLEEP_TIME = 1000000000; /* 1 000 000 000 ns = 1 s */

RT_TASK task1;
RT_TASK task2;
RTIME time1;
RTIME time2;

/* Funkcja wywolywana przy starcie zadania, do ktorego jest przypisany
 * jej adres (zobacz funkcje 'main') */
void func1(void *arg)
{
  int temp2=0;
	/* Ustawienie trybu wykonywania zadania na cykliczny. Oznacza to, ze
	 * sygnal budzenia tego watku bedzie wysylany co okreslony czas
	 * (SLEEP_TIME) az do jego zakonczenia */
	rt_task_set_periodic(NULL, TM_NOW, SLEEP_TIME);

	for(temp2=0;temp2<20;temp2++) {
		/* odczytanie aktualnego czasu w nanosekundach */
		time1 = rt_timer_read();
		/* oczekiwanie na kolejny sygnal budzenia */
		rt_task_wait_period(NULL);
		/* wypisanie roznicy czasu */
		rt_printf("1 %12lld\n", (rt_timer_read()-time1));
	}
}

/* Funkcja odpowiedzialna za przechwycenie sygnalu systemowego */
void catch_sig(int s)
{
	rt_task_delete(&task1);
}

void func2(void *arg)
{
  int temp1=0;
  for(temp1=0;temp1<10;temp1++)
    {    time2=rt_timer_read();
    rt_timer_spin(SLEEP_TIME);
    rt_task_sleep(SLEEP_TIME);
    rt_printf("2 %12lld\n\n", (rt_timer_read()-time2));
  }
}


int main()
{
	/* polaczenie wcisniecia ^C z wywolaniem funkcji catch_sig */
	signal(SIGINT, catch_sig);
	rt_print_auto_init(1);
	mlockall(MCL_CURRENT | MCL_FUTURE);
	/* rownoczesne utworzenie i wystartowanie zadania */
	rt_task_spawn(&task1, "task1", 0, 0, 0, &func1, NULL);
	rt_task_spawn(&task2, "task2", 0, 0, 0, &func2, NULL);
	/* oczekiwanie na nadejscie sygnalu systemowego */
	pause();
	return 0;
}

