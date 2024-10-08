#include <stdio.h>

int ev(float b ,float er,float s ,float d){
	float sd = s/100;
	float erws = er + (er*sd);
	float max = (b*erws) / d;
	return (int)max;
}

int main (){
	printf("%d" , ev(127.25, 1.2, 10, 20));
}
