#include <cmath>

double soma_x(double v[]){
	double soma = 0;
	for(int i=0; i<10;i++){
		soma += v[i];
	}
return soma;
}

double soma_xy(double x[], double y[]){
	double soma = 0;
	for(int i=0; i<10; i++){
		soma += y[i]*x[i];
	}
return soma;
}

double soma_xi_pot(double v[], int pot){
	double soma = 0;
	for(int i=0; i<10; i++){
		soma += pow(v[i],pot);
	}
return soma;
}

double soma_x2y (double x[], double y[]){

	double soma = 0;
	for(int i=0; i<10;i++){
		soma += pow(x[i],2)*y[i];
	}
return soma;
}
