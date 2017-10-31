#include <stdio.h>
#include <math.h>

#define N 3

double f1(double x[N]){
	return cos(x[1]*x[2])/3. + (1./6.) ;	
}

double f2(double x[N]){
	return sqrt( (x[0]*x[0]) + sin(x[2]) +1.06) /9. - 0.1;
}

double f3(double x[N]){
	return -(1./20.)*exp(-x[0]*x[1]) - (10.*M_PI -3.)/60.;
}

main(int argc, char **argv)
{
	double x[N]={0}, x0[N]={1,-1,1};
	double eps = 1e-7, tol=0., norm, norma;
	double (*equacao[N])()={f1,f2,f3};
	int i;
	
	do
	{
		norma=0;
		
		for(i=0; i<N; i++){
			
			x[i] = x0[i];			//valor inicial de x
			
			x0[i] = equacao[i](x0);
			
			printf("\nX1: %lf\t fx: %lf\n", x0[i], x[i]);
			
			norma += pow((x[i]-x0[i]),2.);
		}
		tol++;
		
	}while(sqrt(norma)>eps);
	
	//Número de iterações
	printf("Nº de iterações: %lf", tol);
	
	for(i=0; i<N; i++)
		printf("\nX[i] = %lf\t", x0[i]);
	printf("\n");
	

}
