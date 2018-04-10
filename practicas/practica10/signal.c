#include <stdio.h>
#include <signal.h>

void receiveSignal(int sig){
  printf("Recibi sennal %d\n", sig);
}

int main(){
  signal(SIGTERM, receiveSignal);
  while(1){

  }
  return 0;
}
