#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 3
#define n 4

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
		xb[j]=x[j];
	
	xb[k] = x[k] + h/2.;			//x modificado
	
	M = f(xb);
	
	xb[k] = x[k] - h/2.;			//x modificado
	
	M = (M-f(xb)) / h;				//Calculo da derivada
	
	return M;
}
double imprimi(double y[N][n])
{
	int i, j;
		
	for(i=0; i<N; i++)
	{
		for(j=0; j<n; j++)
			printf("%.2lf\t", y[i][j]);
		printf("\n");	
	}
	printf("\n");
}

double escalonamento(double M[N][n])
{
	int i, j, v;
	double pivo;

	//Fazendo o escalonamento
	for(v=0; v<N; v++)
	{
		for(i=v+1; i<N; i++)
		{
			pivo = -1 * (M[i][v] / M[v][v]);

			for(j=0; j<N+1; j++)
				M[i][j] = M[i][j] + (pivo * M[v][j]);
		}
	}
}


double Reversa(double M[N][n])
{
	double b, x[n], aux, xn;
	int i, j;
	
	b = M[N-1][N];
	x[N] = b / M[N-1][N-2];

	for(i=N-1; i>=0; i--)
	{
		b = M[i][N];
		for(j=i+1; j<N; j++)
			aux += M[i][j]*x[j];
		x[i] = (b - aux) / M[i][i];

		aux=0;
	}

	printf("\n--------Solução da Equação--------\n");
	for(i=0; i<N; i++){
		printf("X%d = %.2lf \t", i+1, x[i]);
		
	}
	printf("\n\n");
	for(i=0;i<N;i++)
		return x[i];
}

main(int argc, char **argv)
{
	double x[N]={0}, x0[N]={0.1,0.1,-0.1}, F[N], J[N][N], y[N][n], m, rev[N];
	double er = 1e-6, tol=0., norma, norm;
	double (*equacao[N])()={f1,f2,f3};
	int i, j, cont=0.;
	
	//do{
		norma=0.;
	
		for(i=0; i<N; i++){
			
			F[i] = -equacao[i](x0);			//Calculo do vetor -F(x0)				
			for(j=0; j<N; j++)
				J[i][j]=df(equacao[i], x0, j);			//Calculando o jacobiano
		}
	
		for(i=0; i<N; i++)
		{
			for(j=0; j<N; j++)
				y[i][j] = J[i][j];
			y[i][j] = F[i];
		}
	
		imprimi(y);			//Imprimindo matriz completa
		escalonamento(y);		//Fazendo o escalonamento da matriz
		imprimi(y);				//Imprimindo a matriz escalonada
		
		for(i=0; i<N; i++)			
			rev[i]=Reversa(y);	//Substituição reversa
		for(i=0; i<N; i++)
			printf("%.2lf\t", rev[i]);				
		printf("\n");
		
		
		cont++;				//contador para as iterações
		
		
	//}while(sqrt(norma)>er);
	
	printf("\nNº de iterações: %d\n\n", cont);



} 
