#include<stdio.h>
#include<math.h>
int calcularAltura(float x, float b, float a){
  return pow(1-pow(x/a,2.0/3.0),3.0/2.0)*b;
}
int main(){
  float areaA = 0, areaB = 0, m, a, b;
  float posibleM, yCalculado;
  printf("ingrese a:");
  scanf("%f",&a);
  printf("ingrese b:");
  scanf("%f",&b);
  float dx = a/100;
  for (int i=1; i<=100; i++){
    posibleM = i*dx;
    areaA = 0;
    for (float j=dx; j<posibleM; j=j+dx){
      yCalculado = calcularAltura(j,b,a);
      areaA = areaA+(b-yCalculado)*dx;
    }
    areaB=0;
    for (float j=posibleM+dx; j<a; j=j+dx){
      yCalculado = calcularAltura(j,b,a);
      areaB = areaB+(yCalculado)*dx;
    }
    printf("Area A: %f - Area B: %f - M: %f\n", areaA, areaB, posibleM);
    if(abs(areaA - areaB) <= 2*dx){
      i = 200;
      printf("El punto m es: %f",posibleM);
    }
  }
}