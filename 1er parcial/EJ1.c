/* ENUNCIADO:
Escribir una funcion para validar una nueva clave de acceso.
La función debera recibir una cadena de caracteres, que contendra la clave candidata, que ya fue ingresada por el usuario.
Devolvera true o false, dependiendo de si cumple o no, con las siguientes condiciones:

- La clave debe estar formada unicamente por, entre 6 y 12 caracteres numericos

- La sumatoria de los digitos numericos no puede ser menor a 20

A los sumo debe recorrer una vez la cadena.
Evite realizar ciclos innecesarios.

Ejemplos:
validar("j20893") devuelve false
validar("20893a") devuelve false
validar("208X930") devuelve false
validar("20201") devuelve false
validar("23445776") devuelve true
validar("089010") devuelve false
validar("02784532132567") devuelve false
validar("027845320011") devuelve true

*/

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef char String[];

bool validar(String clave) {
	int i=0,sumatoria=0;
	bool valida = true;
	if(strlen(clave) < 6 || strlen(clave) > 12) {
		valida = false;
	}
	while(valida==true && i<strlen(clave)) {
		if (clave[i]<'0' || clave[i]>'9') {
			valida = false;
		}
		sumatoria += clave[i] - '0'; // La resta del caracter 0 realiza la conversion de char a int. Su función es corregir la diferencia que provoca la posición en la tabla ASCII, haciéndolos coincidir con sus valores numéricos.
		i++;
	}
	if (sumatoria < 20) {
		valida = false;
	}
	return valida;
}

void main() {

	printf("%i", validar("j20893"));
	printf("%i", validar("20893a"));
	printf("%i", validar("208X930"));
	printf("%i", validar("20201"));
	printf("%i", validar("23445776"));
	printf("%i", validar("089010"));
	printf("%i", validar("02784532132567"));
	printf("%i", validar("027845320011"));
}
