#include<stdio.h>

void cargarDatos(FILE *archivo, int numero){
	
	fwrite(&numero, sizeof(numero), 1, archivo);
}

void main(){
	FILE* archivo;
	
	archivo = fopen("EJ3_archivo.dat", "wb");
	
	cargarDatos(archivo, 45);
	cargarDatos(archivo, 78);
	cargarDatos(archivo, 56);
	cargarDatos(archivo, 98);
	cargarDatos(archivo, 112);
	
	printf("Archivo generado.");
	fclose(archivo);
}
