#include <stdio.h>

typedef struct {
	int codigo;
	char descripcion[30];
	float cantidad;
} t_producto;

void cargarProductos(FILE *archivo) {

	t_producto producto;

	printf("Ingrese el codigo de producto (o cero para finalizar):\n");
	scanf("%i", &producto.codigo);
	fflush(stdin);

	while(producto.codigo != 0)	{

		printf("Ingrese la descripcion del producto:\n");
		scanf("%30[^\n]s", &producto.descripcion);
		fflush(stdin);

		printf("Ingrese la cantidad en stock del producto:\n");
		scanf("%f", &producto.cantidad);
		fflush(stdin);

		fwrite(&producto, sizeof(producto), 1, archivo);

		printf("\nIngrese el codigo de producto (o cero para finalizar):\n");
		scanf("%i", &producto.codigo);
		fflush(stdin);
	}

}

void main() {

	FILE *archivo;

	archivo = fopen("productos.dat","wb");
	cargarProductos(archivo);
	fclose(archivo);
}
