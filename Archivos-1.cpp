#include <stdio.h>
int main()
{
  FILE *f;
  f = fopen("Archivos-1.txt", "r");
  if (f == NULL)
  {
    printf("No se pudo abrir el archivo\n");
    return 1;
  }
  float x, y;
  float aX, aY, bX, bY, cX, cY, dX, dY;
  int i = 0;
  while (i < 2)
  {
    fscanf(f, "%f %f", &x, &y);
    if (i == 0)
    {
      bX = x;
      bY = y;
      aX = bX;
      aY = 0;
    }
    if (i == 1)
    {
      cX = x;
      cY = y;
      dX = cX;
      dY = 0;
    }
    i++;
  }
  printf("A=(%.2f,%.2f)\n", aX, aY);
  printf("B=(%.2f,%.2f)\n", bX, bY);
  printf("C=(%.2f,%.2f)\n", cX, cY);
  printf("D=(%.2f,%.2f)\n", dX, dY);

  float m = (cY - bY) / (cX - bX);
  float b = bY - m * bX;
  int contador = 0;
  while (fscanf(f, "%f %f", &x, &y) != EOF)
  {
    if (y > m * x + b || x < aX || x > cX)
    {
      contador++;
    }
  }
  fclose(f);
  printf("Existen %d puntos fuera de la región ABCD\n", contador);
}