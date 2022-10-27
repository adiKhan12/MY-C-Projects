#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <string.h>

typedef struct
{
  double complex *z;
} complex_array;

complex_array fft(complex_array x)
{
  int n = x.z, k;
  complex_array y;
  y.z = (double complex *) malloc(n * sizeof(double complex));
  if (n == 1)
    {
      y.z[0] = x.z[0];
      return y;
    }
  complex_array even;
  even.z = (double complex *) malloc((n/2) * sizeof(double complex));
  for(k = 0; k < n/2; k++)
    {
      even.z[k] = x.z[2*k];
    }
  complex_array q = fft(even);

  complex_array odd;
  odd.z = (double complex *) malloc((n/2) * sizeof(double complex));
  for(k = 0; k < n/2; k++)
    {
      odd.z[k] = x.z[2*k+1];
    }
  complex_array r = fft(odd);

  for(k = 0; k < n/2; k++)
    {
      double complex expn = cexp(-2.0 * M_PI * I * (double complex)k/(2.0 * n));
      y.z[k] = q.z[k] + expn * r.z[k];
      y.z[k + n/2] = q.z[k] - expn * r.z[k];
    }
  free(q.z);
  free(r.z);
  return y;
}

int main()
{
  int i, j;
  FILE *fp = fopen("fft.txt", "r");
  char buff[100];
  int n;
  fgets(buff, 100, fp);
  sscanf(buff, "%d", &n);
  double complex *x = (double complex *) malloc(n * sizeof(double complex));
  for(i = 0; i < n; i++)
    {
      double re, im;
      fgets(buff, 100, fp);
      sscanf(buff, "%lf %lf", &re, &im);
      x[i] = re + I*im;
    }
  complex_array X;
  X.z = x;
  complex_array y = fft(X);
  for(i = 0; i < n; i++)
    {
      printf("%lf + i%lf\n", creal(y.z[i]), cimag(y.z[i]));
    }
}