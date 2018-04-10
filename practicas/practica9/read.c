#include <stdio.h>
#include <string.h>

typedef struct s {
  char firstName[20];
  char lastName[20];
  short Id;
  char semester[3];
  char free;
} Student;

int main(int argc, char **argv){
  char *dbName = "student.dat";
  Student myStudent;
  if(argc<2) return 1;
  char *searchName = argv[1];

  FILE *data = fopen(dbName, "rb");
  while(1){
    fread(&myStudent, sizeof(Student), 1, data);
    if(feof(data)){
      break;
    }
    if(!strcmp(myStudent.firstName, searchName)){
      printf("Student info: \n");
      printf("first name: %s\n", myStudent.firstName);
      printf("last name: %s\n", myStudent.lastName);
      printf("id: %d\n", myStudent.Id);
      printf("semester: %s\n", myStudent.semester);
      break;
    }
  }
  fclose(data);
  return 0;
}
