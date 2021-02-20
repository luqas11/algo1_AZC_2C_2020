#include <stdio.h>
#include <string.h>
#define MAX_NOM 100

typedef char String[MAX_NOM];

typedef struct {
	int DNI;
	String Nombre;
	String Email;
} TRegistro;

void main() {
	FILE *archivoFiuba;
	FILE *archivoExuba;
	FILE *archivoFinal;
	TRegistro reg_fiuba;
	TRegistro reg_exuba;

	archivoFiuba = fopen("fiuba.dat", "rb");
	archivoExuba = fopen("exuba.dat", "rb");
	archivoFinal = fopen ("merge.dat", "wb");

	fread(&reg_fiuba, sizeof(reg_fiuba), 1, archivoFiuba);
	fread(&reg_exuba, sizeof(reg_exuba), 1, archivoExuba);

	while(!feof(archivoExuba) && !feof(archivoFiuba)) {
		if (reg_fiuba.DNI > reg_exuba.DNI) {
			fwrite(&reg_exuba, sizeof(reg_exuba), 1, archivoFinal);
			fread(&reg_exuba, sizeof(reg_exuba), 1, archivoExuba);
		} else {
			fwrite(&reg_fiuba, sizeof(reg_fiuba), 1, archivoFinal);
			fread(&reg_fiuba, sizeof(reg_fiuba), 1, archivoFiuba);
		}
	}

	while(!feof(archivoFiuba)) {
		fwrite(&reg_fiuba, sizeof(reg_fiuba), 1, archivoFinal);
		fread(&reg_fiuba, sizeof(reg_fiuba), 1, archivoFiuba);
	}

	while(!feof(archivoExuba)) {
		fwrite(&reg_exuba, sizeof(reg_exuba), 1, archivoFinal);
		fread(&reg_exuba, sizeof(reg_exuba), 1, archivoExuba);
	}
	fclose(archivoExuba);
	fclose(archivoFiuba);
	fclose(archivoFinal);
}
