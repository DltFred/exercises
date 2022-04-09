#include <stdio.h>
#include <math.h>

float calculaPendiente(float x1, float y1, float x2, float y2)
{
  return (y2 - y1) / (x2 - x1);
}
float calculaB(float m, float x, float y)
{
  return y - m * x;
}
float calculaInterseccionX(float m1, float b1, float m2, float b2)
{
  return (b1 - b2) / (m2 - m1);
}
float calculaInterseccionY(float m1, float b1, float x)
{
  return m1 * x + b1;
}

int main()
{
  int n;
  printf("Ingrese la cantidad de rectas a ingresar: \n");
  scanf("%d", &n);
  float puntoX1, puntoY1, puntoX2, puntoY2;
  float puntoX3, puntoY3, puntoX4, puntoY4;
  float m2, b2, x2Interseccion, y2Interseccion;
  float distancia = 0;

  printf("Ingrese los puntos (x1,y1,x2,y2) de la recta: \n");
  scanf("%f %f %f %f", &puntoX1, &puntoY1, &puntoX2, &puntoY2);
  float m1 = calculaPendiente(puntoX1, puntoY1, puntoX2, puntoY2);
  float b1 = calculaB(m1, puntoX1, puntoY1);

  printf("\n---------------\n");
  printf("%d \n", n);
  printf("%f %f %f %f \n", puntoX1, puntoY1, puntoX2, puntoY2);

  for (int i = 2; i <= n; i++)
  {
    puntoX3 = puntoX1;
    puntoY3 = puntoY1;
    puntoX4 = puntoX2;
    puntoY4 = puntoY2;
    m2 = m1;
    b2 = b1;
    scanf("%f %f %f %f", &puntoX1, &puntoY1, &puntoX2, &puntoY2);
    m1 = calculaPendiente(puntoX1, puntoY1, puntoX2, puntoY2);
    b1 = calculaB(m1, puntoX1, puntoY1);
    float Xinterseccion = calculaInterseccionX(m1, b1, m2, b2);
    float Yinterseccion = calculaInterseccionY(m1, b1, Xinterseccion);
    printf("%f %f \n", Xinterseccion, Yinterseccion);

    if (i > 2)
    {
      distancia = distancia + sqrt(pow(Xinterseccion - x2Interseccion, 2) + pow(Yinterseccion - y2Interseccion, 2));
    }
    x2Interseccion = Xinterseccion;
    y2Interseccion = Yinterseccion;
  }
  printf("\nEl perimetro es= %f \n", distancia);
}