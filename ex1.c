/*	Sintese
	Objetivo: Achar a aproximacao raiz da equacao de Kepler atraves do
						metodo de Newton Rhapson
	Entrada: -
	Saida: Resultado da aproximacao em cada iteracao, numero da iteracao,
				 e o valor da raiz aproximada garantindo 10 casas decimais
	Autor: Mateus Andrade
*/

#include <stdio.h>
#include <math.h>

double f(double x){ // f(x)
	return x - 0.2 * sin(x) - 0.5;
}

double fdx(double x){ // derivada de f(x)
	return 1 - 0.2 * cos(x);
}

int main(){

	int iteracao = 0; //contador de iteracoes
	double x_i, x_i1, tol;
	//x_new = novo candidato a raiz, x_old = candidato testado que nao deu certo
	tol = 1.0e-10; // para a precisao de 10 casas decimais
	// valores iniciais escolhidos para xi e xi+1
	x_i = 0.1;
	x_i1 = 1;

	//laco com criterio de parada de quando o erro for menor que 10^(-10) para garantir a precisao de 10 casa decimais
	while(fabs(x_i - x_i1)/fabs(x_i1) > tol){
		x_i = x_i1; // atualizacao de valores para a possivel proxima etapa
		x_i1 = x_i - f(x_i)/fdx(x_i); // metodo de newton rhapson
		iteracao++;//contador de iteracoes
		printf("Interacao %d: x = %.10lf\n",iteracao,x_i1);
	}

	printf("x = %.10lf\n",x_i1);// resultado da raiz aproximada
return 0;
}
