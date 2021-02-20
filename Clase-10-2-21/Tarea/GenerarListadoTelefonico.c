#include <stdio.h>

typedef struct {
	int localidad;
	int central;
	int numero;
} t_telefono;

void cargarTelefonos(FILE *archivo) {

	t_telefono telefono;

	printf("\nIngrese la caracteristica de la localidad (o cero para finalizar):\n");
	scanf("%i", &telefono.localidad);
	fflush(stdin);

	while(telefono.localidad != 0)	{

		printf("\nIngrese la caracteristica central:\n");
		scanf("%i", &telefono.central);
		fflush(stdin);

		printf("\nIngrese el numero:\n");
		scanf("%i", &telefono.numero);
		fflush(stdin);

		fwrite(&telefono, sizeof(telefono), 1, archivo);

		printf("\nIngrese la caracteristica de la localidad (o cero para finalizar):\n");
		scanf("%i", &telefono.localidad);
		fflush(stdin);
	}

}

void main() {

	FILE *archivo;

	printf("Presione enter para crear un nuevo archivo...\n");
	getchar();
	archivo = fopen("telefonos.dat","wb");
	cargarTelefonos(archivo);
	fclose(archivo);
}
