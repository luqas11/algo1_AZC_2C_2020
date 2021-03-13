#include<stdio.h>

void main() {
	FILE *archivoNumeros1;
	FILE *archivoNumeros2;
	FILE *archivoNumerosMerge;

	int numero1, numero2;

	archivoNumeros1 = fopen("EJ4_Numeros1.dat", "rb");
	archivoNumeros2 = fopen("EJ4_Numeros2.dat", "rb");
	archivoNumerosMerge = fopen("EJ4_NumerosMerge.dat", "wb");

	fread(&numero1, sizeof(numero1), 1, archivoNumeros1);
	fread(&numero2, sizeof(numero2), 1, archivoNumeros2);
	
	while(!feof(archivoNumeros1)) {
		if(!feof(archivoNumeros2) && numero2 < numero1) {
			fwrite(&numero2, sizeof(numero2), 1, archivoNumerosMerge);
			fread(&numero2, sizeof(numero2), 1, archivoNumeros2);
		} else {
			fwrite(&numero1, sizeof(numero1), 1, archivoNumerosMerge);
			fread(&numero1, sizeof(numero1), 1, archivoNumeros1);
		}
	}
	while(!feof(archivoNumeros2)) {
		fwrite(&numero2, sizeof(numero2), 1, archivoNumerosMerge);
		fread(&numero2, sizeof(numero2), 1, archivoNumeros2);
	}
	
	fclose(archivoNumeros1);
	fclose(archivoNumeros2);
	fclose(archivoNumerosMerge);
}
