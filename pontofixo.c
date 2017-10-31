#include <stdio.h>
#include <math.h>


main()
{
	double x=1.0, fx, e=1e-7;
	int cont=0;
	
	do
	{
		
		fx = x;	//valor inicial de x
		
		x = cos(x);
		
		printf("\nX1: %lf\t fx: %lf\n", x, fx);
		
		cont++;
		
	}while(fabs(fx-x)>e);
	
	printf("\nNº de Iterações: %d\n", cont);
	printf("\nX = %lf\n\n", x);


}
