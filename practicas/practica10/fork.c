#include <stdio.h>
#include <unistd.h>

int main(){
  int pid;

  pid = fork();
  if(pid == 0){
    printf("Soy proceso hijo\n");
    execl("/usr/bin/spotify", "spotify", (char *)0);
  }
  else {
    printf("Soy proceso padre\n");
  }
  return 0;
}
