#include<stdio.h>

void main(){
	FILE *archivo;
	int numero;
	
	archivo = fopen("EJ3_archivo.dat", "rb");
	
	fread(&numero, sizeof(numero), 1, archivo);
	while(!feof(archivo)){
		printf("%i\n", numero);
		fread(&numero, sizeof(numero), 1, archivo);
	}
	fclose(archivo);
}
