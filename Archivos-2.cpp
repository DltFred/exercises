#include <stdio.h>
#include <math.h>

float aRadianes(float grados)
{
  return grados * (M_PI / 180);
}
float cordenadasX(float grados, float radio, float a)
{
  return radio * cos(aRadianes(grados)) + a;
}
float cordenadasY(float grados, float radio, float b)
{
  return radio * sin(aRadianes(grados)) + b;
}
float distancia(float x1, float y1, float x2, float y2)
{
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
  FILE *archivo;
  archivo = fopen("Archivos-2.txt", "r");
  int flag = 0;
  float grados, radio, a, b, x1, y1, x2, y2, xfin, yfin, perimetro = 0;
  while (!feof(archivo))
  {

    if (flag == 0)
    {
      fscanf(archivo, "%f %f", &a, &b);
      printf("A y B: %f %f\n", a, b);
      flag = 1;
    }
    else
    {
      x2 = x1;
      y2 = y1;
      fscanf(archivo, "%f %f", &grados, &radio);
      x1 = cordenadasX(grados, radio, a);
      y1 = cordenadasY(grados, radio, b);
      if (flag == 1)
      {
        xfin = x1;
        yfin = y1;
      }
      printf("X1: %f Y1: %f\n", x1, y1);
      if (flag > 1)
      {
        perimetro += distancia(x2, y2, x1, y1);
      }
      flag++;
    }
  }
  fclose(archivo);
  perimetro += distancia(xfin, yfin, x1, y1);
  printf("Perimetro: %.2f\n", perimetro);
}