#include <stdio.h>
#include <math.h>

int main()
{
  float peso, coef, angulo = 0.0, fFriccion, tensionX, tensionY;
  bool condicion = false;
  float anguloSexa;

  printf("Ingrese el peso:  ");
  scanf("%f", &peso);
  printf("Ingrese el coeficiente de friccion:  ");
  scanf("%f", &coef);

  printf("angulo \t FF \t FcX \t FcY \n");
  while (!condicion)
  {
    fFriccion = (10 * peso + 1000 * sin(angulo)) * coef;
    tensionX = 1000 * cos(angulo);
    tensionY = 1000 * sin(angulo);
    if (fabs(tensionX - fFriccion) < 0.3)
    {
      condicion = true;
    }
    anguloSexa = asin(sin(angulo)) * 180 / M_PI;
    printf("%f \t %f \t %f \t %f \n", anguloSexa, fFriccion, tensionX, tensionY);

    angulo = angulo + 0.1;
  }
}