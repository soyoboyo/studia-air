/* mlockall */
#include <sys/mman.h>
/* Xenomai
 * rtdk - rt_printf
 * native/task - obsluga zadan */
#include <rtdk.h>
#include <native/task.h>

/* deskryptor zadania RT */
RT_TASK task;

int main()
{
	/* wylaczenie stronicowania dla przestrzeni adresowej tego procesu
	 * teraz i w przyszlosci */
	mlockall(MCL_CURRENT|MCL_FUTURE);
	/* automatyczna inicjalizacja buforow dla rt_printf */
	rt_print_auto_init(1);
	/* konwersja obecnego procesu na zadanie RT o nazwie main_task*/
	rt_task_shadow(&task, "main_task", 0, 0);
	
	/* printf zawiera wywolanie systemowe Linuksa, ktore powoduje
	 * niechciane przelaczenie trybu wykonywania zadania */
	printf("\n");
	
	/* struktura zawierajaca informacje o zadaniu */
	RT_TASK_INFO info;
	/* pobranie informacji ze wskazanego zadania i umieszczenie ich w
	 * info */
	rt_task_inquire(&task, &info);
	/* wypisanie informacji odbywa sie bez opoznien spowodowanych
	 * wywolaniami systemowymi */
	rt_printf("name:       %s\n"	  /* nazwa zadania */
			  "switches:   %d\n"	  /* liczba przelaczen trybu */
			  "exectime:   %lld\n\n", /* czas wykonania zadania w ns */
			  info.name,
			  info.modeswitches,
			  info.exectime);
	return 0;
}

