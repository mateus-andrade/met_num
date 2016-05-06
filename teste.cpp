#include <cstdio>
#include "header.h"

using namespace std;

int main(){

	int i,j,k,n=3,o,p;
	double m,soma;
	//valores dos dados experimentais
  double x[10] =  {0.10, 0.20, 0.30, 0.40, 0.50, 0.60, 0.70, 0.80, 0.90, 1.00};
  double y[10] = {0.62, 0.63, 0.64,0.66 , 0.68, 0.71, 0.76, 0.81, 0.89, 1.00};
	//declaracao das matrizes do sistema na forma Ax = B
	double a[3][3] = {{10.0, soma_x(x), soma_xi_pot(x,2)}, {soma_x(x), soma_xi_pot(x,2), soma_xi_pot(x,3)}, {soma_xi_pot(x,2), soma_xi_pot(x,3), soma_xi_pot(x,4)}};
	double ai[3]; //B
	double b[3] =  {soma_x(y), soma_xy(x,y), soma_x2y(x,y)};

	for(k=0; k<n-1; k++){
		for(i=k+1; i<n; i++){
			m=a[i][k]/a[k][k];
			for(j=k+1; j<n; j++)
				// pivoteacao, modificando a matriz A
				a[i][j] = a[i][j] - (m*a[k][j]);
			//modificando o vetor coluna B
			b[i] = b[i] - m*b[k];
			//zerando elementos antes da diagonal para tranformar em matriz triangular superior
			a[i][k] = 0.0;
		}

		//imprimindo a matriz a cada substituicao
		for(o=0; o<n;o++){
			printf("|");
			for(p=0; p<n; p++)
				printf(" %+g\t",a[o][p]);
			printf("%+g | \n",b[o]);
		}
	printf("\n");
	}

	/*encontrando os valores das incognitas, o ultimo valor e encontrado fora do laco
	  isto e possivel pois a matriz ja esta na forma triangula superior*/
	ai[n-1] = b[n-1]/a[n-1][n-1];

	for(i = n-2; i>=0; --i){
		soma = 0.0;
		for(j=i+1; j<n; j++)
			soma = soma + a[i][j]*ai[j];
		ai[i] = (b[i]-soma)/a[i][i];
	}

	for(int i=0; i<3; i++)
		printf("a%d = %.4lf\n",i+1,ai[i]);
return 0;
}
