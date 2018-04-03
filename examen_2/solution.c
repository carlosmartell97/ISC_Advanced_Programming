/*
  Carlos Emmanuel Martell Aviña. A01225920.
  Mi razonamiento para este problema es el siguiente:
  Almacenaré cada renglón en un apuntador de caracteres.

  Según investigué, la función fgets() me permite separar la entrada del usuario en saltos de linea
  almacenarla en una varialbe.

  Después, tendré 2 variables, a y b para llevar control del rango de caracteres donde no hay espacios.
  Leyendo de derecha a izquierda, en cuanto encuentre un espacio en blanco, actualizaré estas variables e imprimiré
  los caracteres del rango que no tiene espacios. Por último, imprimiré también los caracteres que estén al
  principio de la palabra, antes del primer espacio.
*/

#include <stdio.h>
#include <string.h>

int main(){
  int n;
  scanf("%d", &n); // guardar el número de renglones

  char *read;
  if(fgets(read, 80, stdin)!=NULL){
    puts(read);
  }
  for(int i=0; i<n; i++){
    if(fgets(read, 80, stdin)!=NULL){ // leer linea por linea
      // printf("%s", read);
      int len = strlen(read) - 1;
      // printf("len:%d\n", len);
      int a = len+1;
      int b = len;
      for(int j=len-1; j>=0; j--){
        // printf("%c", read[j]);
        if(read[j]==' '){
          b = a-1;
          a = j+1;
          // printf("a:%d  b:%d\n", a, b);
          for(int p=a; p<b; p++){
            printf("%c", read[p]);
          }
          printf(" ");
        }
      }
      for(int p=0; p<a; p++){
        printf("%c", read[p]);
      }
      printf(" ");
    }
    printf("\n");
  }
  return 0;
}
