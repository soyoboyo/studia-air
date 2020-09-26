/* include main */
#include	"unpipc.h"

#include <sys/times.h>
#include <stdio.h>
#include <inttypes.h>

void start_clock(void);
void end_clock(char *msg);

static clock_t st_time;
static clock_t en_time;
static struct tms st_cpu;
static struct tms en_cpu;

void start_clock() {
  st_time = times(&st_cpu);
}

void end_clock(char *msg) {
  en_time = times(&en_cpu);
  fputs(msg, stdout);
  printf("Real time: %jd, User Time %jd, System Time %jd\n",
    (intmax_t)(en_time - st_time),
    (intmax_t)(en_cpu.tms_utime - st_cpu.tms_utime),
    (intmax_t)(en_cpu.tms_stime - st_cpu.tms_stime)
  );
}

#define	MAXNITEMS 		1000000
#define	MAXNTHREADS			100

int		nitems;			/* read-only by producer and consumer */
struct {
  pthread_mutex_t	mutex;
  int	buff[MAXNITEMS];
  int	nput;
  int	nval;
} shared = { PTHREAD_MUTEX_INITIALIZER };

void	*produce(void *), *consume(void *);

int
main(int argc, char **argv)
{
  start_clock();
	int sum = 0;
	int			i, nthreads, count[MAXNTHREADS];
	pthread_t	tid_produce[MAXNTHREADS], tid_consume;

	if (argc != 3)
		err_quit("usage: prodcons2 <#items> <#threads>");
	nitems = min(atoi(argv[1]), MAXNITEMS);
	nthreads = min(atoi(argv[2]), MAXNTHREADS);

	Set_concurrency(nthreads);
		/* 4start all the producer threads */
	for (i = 0; i < nthreads; i++) {
		count[i] = 0;
		Pthread_create(&tid_produce[i], NULL, produce, &count[i]);
	}

		/* 4wait for all the producer threads */
	for (i = 0; i < nthreads; i++) {
		Pthread_join(tid_produce[i], NULL);
		printf("count[%d] = %d\n", i, count[i]);
		sum += count[i];	
	}
	printf("prods sum = %d", sum);
		/* 4start, then wait for the consumer thread */
	Pthread_create(&tid_consume, NULL, consume, NULL);
	Pthread_join(tid_consume, NULL);
  end_clock("");
	exit(0);
}
/* end main */

/* include producer */
void *
produce(void *arg)
{
	for ( ; ; ) {
		Pthread_mutex_lock(&shared.mutex);
		if (shared.nput >= nitems) {
			Pthread_mutex_unlock(&shared.mutex);
			return(NULL);		/* array is full, we're done */
		}
		shared.buff[shared.nput] = shared.nval;
		shared.nput++;
		shared.nval++;
		Pthread_mutex_unlock(&shared.mutex);
		*((int *) arg) += 1;
	}
}

void *
consume(void *arg)
{
	int		i;

	for (i = 0; i < nitems; i++) {
		if (shared.buff[i] != i)
			printf("buff[%d] = %d\n", i, shared.buff[i]);
	}
	return(NULL);
}
/* end producer */
