#include <stdio.h>

int obtenerFactorial(int numero){
	int i, factorial = 1;
	
	for(i = 1; i <= numero; i++){
		factorial = factorial * i;
	}
	return factorial;
}

void main() {
	FILE *archivoNumeros;
	FILE *archivoFactoriales;
	int numero, factorial;

	archivoNumeros = fopen("EJ1_numeros.dat", "rb");
	archivoFactoriales = fopen("EJ1_factoriales.dat", "wb");

	fread(&numero, sizeof(numero), 1, archivoNumeros);

	while(!feof(archivoNumeros)) {

		factorial = obtenerFactorial(numero);
		fwrite(&factorial, sizeof(factorial), 1, archivoFactoriales);
		fread(&numero, sizeof(numero), 1, archivoNumeros);
	}

	fclose(archivoNumeros);
	fclose(archivoFactoriales);
}
