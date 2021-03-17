#include<stdio.h>
#include<string.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	String nombre;
	int categoria;
	int sueldo;
} TRegistro;

void main() {
	FILE *archivo;
	TRegistro registro;
	int sueldosCategoria, categoriaAnterior, empleadosCategoria, totalEmpleados = 0, mayorSueldo;
	String empleadoAnterior, empleadoMayorSueldo;
	archivo = fopen("EJ10_Personal.dat", "rb");

	printf("Listado de personal \n\n");
	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		sueldosCategoria = 0;
		empleadosCategoria = 0;
		mayorSueldo = 0;
		categoriaAnterior = registro.categoria;
		printf("Categoria %i \n", categoriaAnterior);

		while(!feof(archivo) && categoriaAnterior == registro.categoria) {
			sueldosCategoria += registro.sueldo;
			empleadosCategoria++;
			totalEmpleados++;
			printf("  %s \n", registro.nombre);
			if(registro.sueldo > mayorSueldo){
				mayorSueldo = registro.sueldo;
				strcpy(empleadoMayorSueldo, registro.nombre);
			}
			fread(&registro, sizeof(registro), 1, archivo);
		}
		printf("Total de sueldos: %i \n", sueldosCategoria);
		printf("Total de empleados: %i \n", empleadosCategoria);
		printf("El mayor sueldo es %i, empleado %s \n\n", mayorSueldo, empleadoMayorSueldo);
	}
	printf("Cantidad de empleados: %i", totalEmpleados);

	fclose(archivo);
}
