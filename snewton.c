#include <stdio.h>
#include <math.h>

#define N 3

double f1(double x[N]){
	return (pow(x[0], 2)) - 81.*(pow(x[1] + 0.1,2)) + sin(x[2]) + 1.06;
}
double f2(double x[N]){
	return exp(x[0]*x[1]) + 20.*x[2] + (((10.*M_PI )- 3.)/3.);
}
double f3(double x[N]){
	return 3.*x[0] - cos(x[1]*x[2]) - 0.5;
}

double df(double f(), double x[N], int k){
	
	double h=1e-6, M, xb[N];
	int i, j;
	
	for(j=0; j<N; j++)
	{
		xb[j]=x[j];
	}
	
	xb[k] = x[k]+h/2.;
	
	M = f(xb);
	
	xb[k] = x[k]-h/2.;
	
	M = (M-f(xb))/h;
	return M;

}

main(int argc, char **argv)
{
	double x[N]={0}, x0[N]={0.1,0.1,-0.1}, F[N], J[N][N];
	double er = 1e-6, tol=0., norm, norma;
	double (*equacao[N])()={f1,f2,f3};
	int i, j;
	
	
	norma=0.;
	
	//Calculo do vetor -F(x0)
	for(i=0; i<N; i++){
			
		F[i] = -equacao[i](x0);			
				
		//printf("\nX[%d]: %lf\t Fx: %lf\n", i, x[i], F[i]);
		for(j=0; j<N; j++)
		{
			J[i][j]=df(equacao[i], x0, j);
			printf("%lf ", J[i][j]);
		}
		printf("\n");
	}
	
	//Calculando o jacobiano
	
	
		
	//for(i=0; i<N; i++)
	//	printf("\nF[%d] = %lf\t", i, F[i]);
	//printf("\n");
	//printf("Nº de iterações: %lf\n", tol);

} 
