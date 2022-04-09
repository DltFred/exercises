#include <stdio.h>
int main()
{
  FILE *a;
  a = fopen("MATRIZ.TXT", "r");
  int x[100], z[100], i = 0, j, c, m;
  char y = 'm';
  while (y != '\n')
  {
    fscanf(a, "%d%c", &x[i], &y);
    i++;
  }
  fclose(a);
  c = i;
  printf("#columnas= %d\n", c);
  a = fopen("MATRIZ.TXT", "r");
  for (int j = 1; !feof(a); j++)
  {
    fscanf(a, "%d", &x[j]);
  }
  for (int j = 1; j <= c; j++)
  {
    z[j] = x[c * (j - 1) + j];
  }
  fclose(a);
  for (int j = 1; j <= c; j++)
  {
    for (int k = j + 1; k <= c; k++)
    {
      if (z[j] > z[k])
      {
        int t = z[j];
        z[j] = z[k];
        z[k] = t;
      }
    }
  }

  for (int j = 1; j <= c; j++)
  {
    x[c * (j - 1) + j] = z[j];
  }
  FILE *b = fopen("MATRIZORDENADA.TXT", "w");
  for (int j = 1; j <= c; j++)
  {
    for (int k = 1; k <= c; k++)
    {
      fprintf(b, "%d ", x[c * (j - 1) + k]);
    }
    fprintf(b, "\n");
  }
}