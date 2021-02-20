/*
Se tiene un archivo de números telefónicos cuyos registros son de la forma:
Característica de localidad (4 dígitos)
Característica central (3 dígitos)
Número (4 dígitos)

Dado un número que representa una característica de localidad, listar todos los números telefónicos con dicha característica.
Suponer los siguientes casos:

a) El archivo no cabe en memoria y está desordenado.
b) El archivo no cabe en memoria y está ordenado según números telefónicos completos crecientes.
*/

#include <stdio.h>

typedef struct {
	int localidad;
	int central;
	int numero;
} t_telefono;

void mostrarTelefonosPorCaracteristica(FILE *archivo, int caracteristica) {

	t_telefono telefono;

	fread(&telefono, sizeof(telefono), 1, archivo);
	while(!feof(archivo) && telefono.localidad <= caracteristica) {
		if(telefono.localidad == caracteristica) {
			printf("%i-%i-%i \n", telefono.localidad, telefono.central, telefono.numero);
		}
		fread(&telefono, sizeof(telefono), 1, archivo);
	}
}

void main() {
	FILE *archivo;
	int caracteristica;

	archivo = fopen("telefonos.dat","rb");
	if(archivo == NULL) {
		printf("No se pudo abrir el archivo");
	} else {
		printf("Ingrese una caracteristica para ver los numeros telefonicos: \n");
		scanf("%i", &caracteristica);
		fflush(stdin);

		mostrarTelefonosPorCaracteristica(archivo, caracteristica);
		fclose(archivo);
	}
}
