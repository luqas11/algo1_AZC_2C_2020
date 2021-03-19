#include<stdio.h>
#include<string.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	int legajo;
	String nombre;
} TRegistro;

void main() {
	FILE *archivoAnalisis;
	FILE *archivoAlgebra;

	TRegistro registroAnalisis, registroAlgebra;

	archivoAnalisis = fopen("EJ12_Analisis.dat", "rb");
	archivoAlgebra = fopen("EJ12_Algebra.dat", "rb");

	fread(&registroAnalisis, sizeof(registroAnalisis), 1, archivoAnalisis);
	fread(&registroAlgebra, sizeof(registroAlgebra), 1, archivoAlgebra);

	while(!feof(archivoAnalisis) && !feof(archivoAlgebra)) {

		if(registroAnalisis.legajo == registroAlgebra.legajo) {
			printf("%s, %i \n", registroAnalisis.nombre, registroAnalisis.legajo);
			fread(&registroAnalisis, sizeof(registroAnalisis), 1, archivoAnalisis);

		} else if(registroAnalisis.legajo > registroAlgebra.legajo) {
			fread(&registroAlgebra, sizeof(registroAlgebra), 1, archivoAlgebra);

		} else {
			fread(&registroAnalisis, sizeof(registroAnalisis), 1, archivoAnalisis);
		}
	}

	fclose(archivoAnalisis);
	fclose(archivoAlgebra);
}
