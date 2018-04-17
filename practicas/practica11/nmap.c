#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include "student.h"

int main(){
  char *fileName = "student.dat";
  int fd = open(fileName, O_RDWR);
  Student *pAvanzada = (Student *)mmap(
    NULL,
    10 * sizeof(Student),
    PROT_READ | PROT_WRITE,
    MAP_FILE | MAP_PRIVATE,
    fd,
    0
  );
  close(fd);
  for(int i=0; i<4; i++){

  }

  int pos = 5;
  printf("Student at %d:\n", pos);
  printf(" %s\n", pAvanzada[5].firstName);
  return 0;
}
