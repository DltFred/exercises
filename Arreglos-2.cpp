#include <stdio.h>
int main()
{
  int n, m;
  printf("Ingrese la cantidad de elementos del arreglo 1: ");
  scanf("%d", &n);
  int x[n];
  printf("Ingrese la cantidad de elementos del arreglo 2: ");
  scanf("%d", &m);
  int y[m];
  for (int i = 0; i < n; i++)
  {
    printf("Ingrese el elemento %d del arreglo 1: ", i + 1);
    scanf("%d", &x[i]);
  }
  for (int i = 0; i < m; i++)
  {
    printf("Ingrese el elemento %d del arreglo 2: ", i + 1);
    scanf("%d", &y[i]);
  }
  int z[n + m];
  for (int i = 0; i < n; i++)
  {
    z[i] = x[i];
  }
  for (int i = 0; i < m; i++)
  {
    z[i + n] = y[i];
  }
  //ordenar el arreglo z
  for (int i = 0; i < n + m; i++)
  {
    for (int j = i + 1; j < n + m; j++)
    {
      if (z[i] > z[j])
      {
        int aux = z[i];
        z[i] = z[j];
        z[j] = aux;
      }
    }
  }
  printf("El arreglo ordenado es: ");
  for (int i = 0; i < n + m; i++)
  {
    printf("%d ", z[i]);
  }
  printf("\n");
}