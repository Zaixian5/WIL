// pr10_04.c

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREAD 10

void* t_gugu(void*);

pthread_mutex_t m_lock;

int main(void){
    pthread_t tid[MAX_THREAD];

    pthread_mutex_init(&m_lock, NULL);
    
    for(int i = 2; i <= 9; i++){
        pthread_create(&tid[i], NULL, t_gugu, &i);
        pthread_join(tid[i], NULL);
    }

    return 0;
}

void* t_gugu(void* dan){
    pthread_mutex_lock(&m_lock);
    
    for(int i = 1; i <= 9; i++){
        printf("%d * %d = %d\n", *((int*)dan), i, *((int*)dan) * i);
    }

    pthread_mutex_unlock(&m_lock);
}
