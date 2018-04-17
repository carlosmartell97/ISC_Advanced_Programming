#include <stdio.h>
#include <omp.h>

int main(){
  int tid;
  int gid = 1;

  #pragma omp parallel private(tid) shared(gid)   // the number of threads is set by the environment variable OMP_NUM_THREADS
  {
    tid = omp_get_thread_num();
    gid = tid;
    printf("Hello World tid:%d gid:%d\n", tid, gid);
  }

  return 0;
}
