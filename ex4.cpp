#include <cstdio>

using namespace std;

int main(){

	//variaveis necessarias para o codigo
	int i,j,k,n=3,o,p;

	double m,soma;

	//declaracao das matrizes do sistema na forma Ax = B
	double a[3][3] = {{100.0,-100.0,200.0}, {-100.0,10.0,110.0}, {0.0,110.0,10.0}};
	double x[3],I[6];
	double b[3] =  {0.0,0.0,20.0};

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
	  isto e possivel pois a matriz a esta na forma triangula superior*/
	x[n-1] = b[n-1]/a[n-1][n-1];

	for(i = n-2; i>=0; --i){
		soma = 0.0;
		for(j=i+1; j<n; j++)
			soma = soma + a[i][j]*x[j];
		x[i] = (b[i]-soma)/a[i][i];
	}

	I[1] = x[0], I[3] = x[1], I[4] = x[2];
	//substituicao dos valores de I dados no exercicio depois de achado os valores das incognitas
	I[0] = I[4]+I[3];
	I[2] = I[1]+I[4];
	I[5] = I[0]+I[1];

	//imprimindo os resultados
	for(i=0; i<6; i++)
		printf("I%d = %+.10f \n",i+1,I[i]);
	
return 0;
}
