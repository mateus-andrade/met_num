#include <cstdio>
#include <cmath>

using namespace std;

double f(double x){ // f(x)
	return 1000*pow(x,5.0)-3*x+9.04;
}

double fdx(double x){ // derivada de f(x)
	return 5000*pow(x,4.0)-3;
}

int main(){

	double x_old, x_new, tol;
	//x_new = novo candidato a raiz, x_old = candidato testado que nao deu certo
	tol = 1.0e-10; // para a precisao de 10 casas decimais
	x_old = 1.0;
	x_new = 1.1;

	while(fabs(x_old - x_new)/fabs(x_new) > tol){
		x_old = x_new;
		x_new = x_old - f(x_old)/fdx(x_old);
	}

	printf("x = %.10lf\n",x_new);
return 0;
}
