#include <stdio.h>

typedef struct {
	int codigo;
	char descripcion[30];
	float cantidad;
} t_producto;

void mostrarProductos(FILE *archivo) {

	t_producto producto;

	fread(&producto, sizeof(producto), 1, archivo);
	printf("Codigo \t\t Descripcion \t\t\t Cantidad en stock \n");
	while(!feof(archivo)) {
		printf("%i \t\t %-30s  %.0f \n", producto.codigo, producto.descripcion, producto.cantidad);
		fread(&producto, sizeof(producto), 1, archivo);
	}
}

void main() {
	FILE *archivo;

	archivo = fopen("productos.dat","rb");
	mostrarProductos(archivo);
	fclose(archivo);
}
