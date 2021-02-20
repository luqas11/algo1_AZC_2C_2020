#include <stdio.h>

typedef struct {
	int codigo;
	char descripcion[30];
	float cantidad;
} t_producto;

void mostrarProductoPorCodigo(FILE *archivo, int codigo) {

	t_producto producto;

	rewind(archivo);
	while(!feof(archivo) && codigo != producto.codigo) {
		fread(&producto, sizeof(producto), 1, archivo);
	}

	if(feof(archivo)) {
		printf("Producto no encontrado \n");
	} else {
		printf("Codigo: %i \n", producto.codigo);
		printf("Descripcion: %-30s \n", producto.descripcion);
		printf("Cantidad en stock: %.0f \n", producto.cantidad);
	}

}

void ingresarCodigos(FILE *archivo) {
	int codigo;

	printf("Ingrese un codigo para ver los datos del producto (o cero para finalizar): \n");
	scanf("%i", &codigo);
	fflush(stdin);

	while(codigo != 0) {
		mostrarProductoPorCodigo(archivo, codigo);

		printf("\nIngrese un codigo para ver los datos del producto (o cero para finalizar): \n");
		scanf("%i", &codigo);
		fflush(stdin);
	}
}

void main() {
	FILE *archivo;

	archivo = fopen("productos.dat","rb");
	if(archivo == NULL) {
		printf("No se pudo abrir el archivo");
	} else {
		ingresarCodigos(archivo);
		fclose(archivo);
	}
}
