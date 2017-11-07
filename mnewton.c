#include <stdio.h>
#include <math.h>

double f(double x)
{
	return cos(x) - x;
}
double fd(double x)
{
	return (-sin(x) - 1);
}


main()
{
	double x1=1., x, er=1e-4;
	int i=0;
	
	do
	{
		x=x1;
		
		x1 = x - f(x1)/fd(x1);
	
		i++;
		
	}while(fabs(x-x1)>er);
	
	printf("Valor: %lf\n", x1);
	printf("Nº de iterações: %d\n", i);

}
