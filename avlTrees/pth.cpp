#include <iostream>
#include <pthread.h>

using namespace std;

void *runner(void *v)
{
  cout << "Hi" << endl;
  pthread_exit(0);
}

int main(void)
{
  pthread_t tid;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_create(&tid, &attr, runner, NULL);
  pthread_join(tid, NULL);
  return 0;
}
