#include <stdio.h>

int main(){
  int a = 4;
  int *p;
  float f = 7.5;
  int max = 2147483647;   // biggest int possible
  long int d;

  int b = a+(int)f;     // 11. Y, para hacer la operación sin tener que tratar con flotantes (que su ALU es más tardada),
                        // primero lo convierto a int
  float c = a*f;
  d = max*(long)max; // se hace casting a uno de los dos para que al momento de hacer la operación el resultado sea un
                     // long, no un int. Aunque solo uno de ellos es long, el resultado es del tipo de dato del más grande
  int arreglo[5] = {0}; // de esta manera, se inicializan todos los elementos del arreglo a 0.
  // int arreglo[5] = {0,2}; // de esta manera, se inicializa el primer elemento a 0, el segundo a 2 y los demás a 0.
  p = arreglo;
  for(int k=0; k<sizeof(arreglo)/sizeof(arreglo[0]); k++){
    *p++ = 67;
    // que es lo mismo que hacer *p = 67; p++;
  } // para acceder a todos los elementos del arreglo con un apuntador

  // p = &a;
  // *p = 7;
  // p++;      // incrementar la dirección en memoria a la que apunta el pointer.
  // *p = 8;
  printf(" a=%d, aEnHexadecimal=%p b=%d d=%ld\n", a, &a, b, d); // p:pointer. La dirección de memoria en que se almacena
                                                                // esa variable en memoria RAM
  printf(" f=%f c=%f\n", f, c);
  printf(" p=%p\n", &p);

  return 0;
}
