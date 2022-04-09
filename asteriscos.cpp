#include <stdio.h>
#include <math.h>

int cantAsteriscos(){
  char x;
  int contador = 0;
  for (int i = 0; x != '\n';)
  {
    scanf("%c", &x);
    if (x == '*')
      contador++;
  }
  x='A';
  return contador;
}

void imprimirAsteriscos(int numero){
  for (int i = 0; i < numero; i++){
    printf("*");
  }
  printf("\n");
}

int cantidadCifras(int numero){
  int contador = 0;
  while(numero !=0){
    numero = numero/10;
    contador ++;
  }
  return contador;
}

int main(){
  int factor1, factor2, auxiliar;
  factor1= cantAsteriscos();
  factor2= cantAsteriscos();
  int numero = factor1 * factor2;
  printf("\n");
  for (int i = cantidadCifras(numero)-1; i >= 0; i--){
    auxiliar = numero/pow(10,i);
    printf("%d: ",auxiliar);
    imprimirAsteriscos(auxiliar); 
    numero = numero - auxiliar*pow(10,i); 
  }
  printf("\n");
}