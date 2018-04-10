#include <stdio.h>

typedef struct s {
  char firstName[20];
  char lastName[20];
  short Id;
  char semester[3];
  char free;
} Student;

int main(){
  char *dbName = "student.dat";
  Student pAvanzada[10];

  for(int i=0; i<10; i++){
    sprintf(pAvanzada[i].firstName, "name%i", i);
    sprintf(pAvanzada[i].lastName, "last name%i", i);
    sprintf(pAvanzada[i].semester, "S%i", i);
    pAvanzada[i].Id = i;
    pAvanzada[i].free = 0;
  }
  FILE *data = fopen(dbName, "wb");
  fwrite(pAvanzada, sizeof(Student), 10, data);
  fclose(data);
  return 0;
}
