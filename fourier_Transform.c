#include<stdio.h>
#include<math.h>
#include<complex.h>

int main()
{
    float x[8],w[8],h[8],y[8];
    float a=0,b=0,c=0,d=0,sum=0,sum1=0,sum2=0,sum3=0;

    printf("Enter the values of the input signal:\n");
    for(int i=0; i<8; i++)
    {
        scanf("%f",&x[i]);
    }
    printf("Enter the values of the impulse response of the system:\n");
    for(int i=0; i<8; i++)
    {
        scanf("%f",&h[i]);
    }

    for(int n=0; n<8; n++)
    {
        for(int k=0; k<8; k++)
        {
            a=x[k]*cos((2*n*k*3.142)/8);
            b=x[k]*sin((2*n*k*3.142)/8);
            c=h[k]*cos((2*n*k*3.142)/8);
            d=h[k]*sin((2*n*k*3.142)/8);
            sum+=a+b;
            sum1+=c+d;
            sum2+=(a+b)*(c+d);
            sum3+=(a-b)*(c-d);
        }
        w[n]=sum1;
        y[n]=sum2*cos((2*n*3.142)/8)-sum3*sin((2*n*3.142)/8);

        printf("w[n]=%.2f\n",w[n]);
         printf("y[n]=%.2f\n",y[n]);
    }

    return 0;

    
}