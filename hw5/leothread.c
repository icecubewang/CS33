#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* thread(void *vargp);

int max_thread;
int N;

int leonardo(int n) {
  if (n == 0 || n == 1)
    return 1;
  return leonardo(n - 1) + leonardo(n - 2) + 1;
}

typedef struct {
  int thread_number;
  int fibNumber;
} argu;
//main thread is at layer 1

void *thread(void* arg) {
  argu* m_arg = (argu*) arg;
  argu* m_children_arg = malloc(sizeof(argu) * 2);
  
  m_children_arg[0].thread_number = m_arg->thread_number + 1;
  m_children_arg[0].fibNumber = (m_arg->fibNumber) - 1;
  m_children_arg[1].thread_number = leonardo((m_arg->fibNumber) - 1) + 1 + m_arg->thread_number;
  m_children_arg[1].fibNumber = (m_arg->fibNumber) - 2;
  if (m_children_arg[1].fibNumber == 0)
    m_children_arg[1].fibNumber = 1;

  int i;
  if (m_arg->fibNumber > 1) {
    printf("(%d\n", m_arg->thread_number);
    pthread_t thread_id[2];
    for (i = 0; i < 2; i++) {
      pthread_create(thread_id + i, NULL, thread, m_children_arg + i);
    }
    for (i = 0; i < 2; i++) {
      pthread_join(*(thread_id + i), NULL);
    }
    printf("%d)\n", m_arg->thread_number);
  }
  else {
    printf("[%d]\n", m_arg->thread_number);
  }

  free(m_children_arg);
  return NULL;
}

int main(int argc, const char * argv[]) {
  N = atoi(argv[1]);
  max_thread = leonardo(N) - 1;
  argu m_arg;
  m_arg.thread_number = 0;
  m_arg.fibNumber = N;
  if (N >= 1)
    thread(&m_arg);
}
