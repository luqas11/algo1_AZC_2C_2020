#include <stdio.h>
#include <string.h>
#define MAX_NOM 100

typedef char String[MAX_NOM];

typedef struct {
	String Prov;
	String Ciu ;
	int DNI;
	char test;
} TRegistro;

void main() {
	FILE *archivoTest;
	FILE *archivoListado;

	TRegistro registro;
	int PaisContNeg = 0;
	int PaisContPos = 0;

	int ProvContNeg;
	int ProvContPos;
	String ProvAnt;

	int CiuContNeg;
	int CiuContPos;
	String CiuAnt;

	archivoTest = fopen("listadoTest.dat", "rb");
	archivoListado = fopen("resultadosTest.txt", "w");

	fread(&registro, sizeof(TRegistro), 1, archivoTest);

	fprintf(archivoListado, "Argentina\n");
	printf("Argentina\n");
	while(!feof(archivoTest)) {
		ProvContNeg = 0;
		ProvContPos = 0;
		strcpy(ProvAnt, registro.Prov);
		printf("%s", registro.Prov);
		fprintf(archivoListado, "%s", registro.Prov);

		while(!feof(archivoTest) && strcmp(ProvAnt, registro.Prov) == 0) {
			CiuContNeg = 0;
			CiuContPos = 0;
			strcpy(CiuAnt, registro.Ciu);

			while (!feof(archivoTest) && strcmp(ProvAnt, registro.Prov) == 0 && strcmp(CiuAnt, registro.Ciu) == 0) {
				if (registro.test == '+') {
					CiuContPos++;
				} else {
					CiuContNeg++;
				}
				fread(&registro, sizeof(TRegistro), 1, archivoTest);
			}

			printf("\t%s\t+%d -%d\n", CiuAnt, CiuContPos, CiuContNeg);
			fprintf(archivoListado, "\t%s\t+%d -%d\n", CiuAnt, CiuContPos, CiuContNeg);

			ProvContNeg = ProvContNeg + CiuContNeg;
			ProvContPos = ProvContPos + CiuContPos;
		}

		printf("Total %s+%d -%d\n", ProvAnt, ProvContPos, ProvContNeg);
		fprintf(archivoListado, "Total %s+%d -%d\n", ProvAnt, ProvContPos, ProvContNeg);
		PaisContNeg += ProvContNeg;
		PaisContPos += ProvContPos;

	}

	printf("Total Pais +%d -%d\n", PaisContPos, PaisContNeg);
	fprintf(archivoListado, "Total Pais +%d -%d\n", PaisContPos, PaisContNeg);

	fclose(archivoListado);
	fclose(archivoTest);
}
