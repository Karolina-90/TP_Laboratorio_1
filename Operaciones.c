#include "Operaciones.h"

//Realizar SUMA

float suma(float num1, float num2) {

	float resultado;

	resultado = num1 + num2;

	return resultado;

}

float resta(float num1, float num2) {

	float resultado;

	resultado = num1 - num2;

	return resultado;
}

float division(float num1, float num2) {

	float resultado;

	if (num2 != 0){
		resultado = num1 / num2;
		return resultado;
	} else {
		return 1;
	}
}

float multiplicacion(float num1, float num2) {

	float resultado;

	resultado = num1 * num2;

	return resultado;

}

float factorial(float num) {

    float resultado;

    resultado = num;

        for(int i = 1; i < num; i++) {
        resultado = resultado * i;
        }

return resultado;

}


