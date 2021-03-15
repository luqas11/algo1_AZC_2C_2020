#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void main() {
	FILE *archivo;
	FILE *archivoCorregido;

	char caracter;
	bool hayEspacio = false;

	archivo = fopen("archivo.txt", "r");
	archivoCorregido = fopen("archivoCorregido.txt", "w");

	caracter = fgetc(archivo);
	while(!feof(archivo)) {

		if(caracter == 32) {
			if(!hayEspacio) {
				fputc(caracter, archivoCorregido);
			}
			hayEspacio = true;
		} else {
			fputc(caracter, archivoCorregido);
			hayEspacio = false;
		}
		caracter = fgetc(archivo);
	}

	fclose(archivo);
	fclose(archivoCorregido);
}
