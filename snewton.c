#include <stdio.h>
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

}

double escalonamento(double M[N][N], int v)
{
	int i, j;
	double pivo;

	//Fazendo o escalonamento
	for(i=v+1; i<N; i++)
	{
		pivo = -1 * (M[i][v] / M[v][v]);

		for(j=v; j<N+1; j++)
			M[i][j] = M[i][j] + (pivo * M[v][j]);
	}

}

/*
void Reversa(double **M, int dim)
{
	double b, x[dim+1], aux;
	int i, j;

	b = M[dim-1][dim];
	x[3] = b / M[dim-1][dim-2];

	for(i=dim-1; i>=0; i--)
	{
		b = M[i][dim];
		for(j=i+1; j<dim; j++)
			aux += M[i][j]*x[j];
		x[i] = (b - aux) / M[i][i];

		aux=0;
	}

	printf("\n--------Solução da Equação--------\n");
	for(i=0; i<dim; i++)
		printf("X%d = %lf \t", i+1, x[i]);
	printf("\n\n");
}
*/
main(int argc, char **argv)
{
	double x[N]={0}, x0[N]={0.1,0.1,-0.1}, F[N], J[N][N], y[N][n];
	double er = 1e-6, tol=0., norm, norma;
	double (*equacao[N])()={f1,f2,f3};
	int i, j;
	
	
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
	
	imprimi(y);

	for(i=0; i<N; i++)
	{		
		if(y[i][i] != 0)
			escalonamento(y,i);
	}

	


} 
