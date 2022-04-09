#include <stdio.h>
int main()
{
  int x[200];
  int n;
  bool bandera = false;
  printf("Ingrese la cantidad de elementos: ");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    printf("Ingrese el elemento %d: ", i);
    scanf("%d", &x[i]);
  }
  for (int i = 0; i < n; i = i + 2)
  {
    for (int j = 1; j < n; j = j + 2)
    {
      if (x[i] < x[j])
      {
        printf("NO ES PARTIDARIO :%d\n", x[i]);
        bandera = true;
        j = n;
        i = n;
      }
    }
  }
  if (bandera == false)
  {
    printf("ES PARTIDARIO\n");
  }
}
