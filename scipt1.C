#include <iostream>

int plot_eq(){

	TF1 *fa1 = new TF1("fa1","sin(x)/x",0,10); 
	fa1 -> Draw();
}
