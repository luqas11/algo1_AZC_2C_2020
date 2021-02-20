/*
Se tiene un archivo de n�meros telef�nicos cuyos registros son de la forma:
Caracter�stica de localidad (4 d�gitos)
Caracter�stica central (3 d�gitos)
N�mero (4 d�gitos)

Dado un n�mero que representa una caracter�stica de localidad, listar todos los n�meros telef�nicos con dicha caracter�stica.
Suponer los siguientes casos:

a) El archivo no cabe en memoria y est� desordenado.
b) El archivo no cabe en memoria y est� ordenado seg�n n�meros telef�nicos completos crecientes.
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
