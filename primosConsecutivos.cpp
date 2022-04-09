#include <stdio.h>
#include <string.h>
//una funcion me permite guardar un procedimiento repetitivo
bool esPrimo(int numero){
  int contador = 0;
  for (int i = 2; i <= numero; i++){
    if (numero % i == 0)
      contador++;
  }
  if (contador == 1) return true;
  else return false;
}

void imprimir(int numero){
  int suma = 0;
  printf("%d: 2",numero);
  for(int i=3; i<=numero; i++){
    if(esPrimo(i)) {
       suma = suma + i;
      if (suma < numero) printf("+%d",i);
    }
  }
  printf("\n");
}

int main()
{
  //  Calcular el mayor primo que pueda ser escrito como la suma de primos consecutivos y que empiece desde el 2.
  int n, sumadePrimos = 0, candidato = 0;
  printf("Ingrese un numero entero: \n");
  scanf("%d", &n);
  for(int i=2; i<=n-1;i++){
    if(esPrimo(i)){
      sumadePrimos = sumadePrimos +i;
      if(esPrimo(sumadePrimos) && sumadePrimos<n) candidato = sumadePrimos;
    }
  }
  imprimir(candidato);
}

