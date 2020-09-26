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

/* include main */
int
main(int argc, char **argv)
{
	start_clock();
	//int sum = 0;
	int			i, nthreads, count[MAXNTHREADS];
	pthread_t	tid_produce[MAXNTHREADS], tid_consume;

	if (argc != 3)
		err_quit("usage: prodcons3 <#items> <#threads>");
	nitems = min(atoi(argv[1]), MAXNITEMS);
	nthreads = min(atoi(argv[2]), MAXNTHREADS);

		/* 4create all producers and one consumer */
	Set_concurrency(nthreads + 1);
	for (i = 0; i < nthreads; i++) {
		count[i] = 0;
		Pthread_create(&tid_produce[i], NULL, produce, &count[i]);
	}
	Pthread_create(&tid_consume, NULL, consume, NULL);

		/* 4wait for all producers and the consumer */
	for (i = 0; i < nthreads; i++) {
		Pthread_join(tid_produce[i], NULL);
		printf("count[%d] = %d\n", i, count[i]);
		//sum += count[i];	
	}
	//printf("prods sum = %d\n", sum);
	Pthread_join(tid_consume, NULL);
	
	end_clock("");

	exit(0);
}
/* end main */

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

/* include consume */
void
consume_wait(int i)
{
	for ( ; ; ) {
		Pthread_mutex_lock(&shared.mutex);
		if (i < shared.nput) {
			Pthread_mutex_unlock(&shared.mutex);
			return;			/* an item is ready */
		}
		Pthread_mutex_unlock(&shared.mutex);
	}
}

void *
consume(void *arg)
{
	int		i;

	for (i = 0; i < nitems; i++) {
		consume_wait(i);
		if (shared.buff[i] != i)
			printf("buff[%d] = %d\n", i, shared.buff[i]);
	}
	return(NULL);
}
/* end consume */
