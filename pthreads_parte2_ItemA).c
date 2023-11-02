// Raul Vilhora Cardoso Matias - 32267274
// Bruno Lauand Ferrão - 32217994

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_ITERATIONS 10000000

int n = NUM_ITERATIONS;
int thread_count = NUM_THREADS;
double sum = 0.0;
pthread_mutex_t mutex;

void* Thread_sum(void* rank) {
    long my_rank = (long) rank;
    double factor;
    long long i;
    long long my_n = n / thread_count;
    long long my_first_i = my_n * my_rank;
    long long my_last_i = my_first_i + my_n;
    double local_sum = 0.0;

    if (my_first_i % 2 == 0) /* my_first_i is even */
        factor = 1.0;
    else /* my_first_i is odd */
        factor = -1.0;

    for (i = my_first_i; i < my_last_i; i++, factor = -factor) {
        local_sum += factor / (2 * i + 1);
    }

    pthread_mutex_lock(&mutex);
    sum += local_sum;
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t* thread_handles;
    long thread;

    thread_handles = (pthread_t*) malloc(thread_count * sizeof(pthread_t));
    pthread_mutex_init(&mutex, NULL);

    for (thread = 0; thread < thread_count; thread++) {
        pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*) thread);
    }

    for (thread = 0; thread < thread_count; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    pthread_mutex_destroy(&mutex);
    free(thread_handles);

    double pi = 4.0 * sum;

    printf("Quantidade de threads: %d\n", NUM_THREADS);
    printf("Valor de pi calculado: %f\n", pi);

    return 0;
}
