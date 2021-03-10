/*Una institucion educativa posee los siguientes archivos binarios:
Archivo de socios (socios.dat) contiene todos los socios actuales de la institucion
Formato de registro: DNI (entero), Numero de socio (entero), Nombre y apellido (string).

Archivo de Socios Nuevos (nuevos.dat) contiene los socios nuevos
Formato de registro: DNI (entero), Numero de socio (entero), Nombre y apellido (string), Sucursal (entero)

Todos los dias se recibe el archivo de Socios nuevos con la altas realizadas el dia anterior
y se desea actualizar el archivo de socios agregando los socios nuevos.
Ambos archivos estan ordenados por DNI en forma ascendente.
En caso de que el DNI de un socio nuevo ya existiera en el archivos de socios se debe actualizar el campo Nombre y apellido
y agregar el DNI a un archivo de texto llamado actualizaciones.txt

Escribir un programa en lenguaje C que genere un tercer archivo de socios actualizado
(sociosAct.dat)
Este archivo debe quedar ordenado por DNI en forma ascendente.
*/

#include <stdio.h>
#include <string.h>
#define MAX_NOM 100

typedef char String[MAX_NOM];

typedef struct  {
	int dni;
	int socio;
	String nombre;
} TRSocio;
typedef struct  {
	int dni;
	int socio;
	String nombre;
	int sucursal;
} TRSocioNuevo;

void main() {
	FILE *archSocios;
	FILE *archNuevos;
	FILE *archSociosAct;
	FILE *archActualizaciones;
	TRSocio regSocios, regActualizar;
	TRSocioNuevo regNuevos;

	// Abrir archivos
	archSocios = fopen("socios.dat", "rb");
	archNuevos = fopen("nuevos.dat", "rb");
	archSociosAct = fopen("sociosAct.dat", "wb");
	archActualizaciones = fopen("actualizaciones.txt", "w");

	// leer archivos
	fread(&regSocios, sizeof(TRSocio), 1, archSocios);
	fread(&regNuevos, sizeof(TRSocioNuevo), 1, archNuevos);

	while(!feof(archSocios) && !feof(archNuevos)) {

		if (regSocios.dni == regNuevos.dni) {
			
			strcpy(regSocios.nombre, regNuevos.nombre);
			fwrite(&regSocios, sizeof(TRSocio), 1, archSociosAct);
			fprintf(archActualizaciones, "%d\n", regSocios.dni);
			fread(&regSocios, sizeof(TRSocio), 1, archSocios);
			fread(&regNuevos, sizeof(TRSocioNuevo), 1, archNuevos);
		} else if(regSocios.dni < regNuevos.dni) {
			
			fwrite(&regSocios, sizeof(TRSocio), 1, archSociosAct);
			fread(&regSocios, sizeof(TRSocio), 1, archSocios);
		}
		else {
			
			regActualizar.dni = regNuevos.dni;
			regActualizar.socio = regNuevos.socio;
			strcpy(regActualizar.nombre, regNuevos.nombre);
			fwrite(&regActualizar, sizeof(TRSocio), 1, archSociosAct);
			fread(&regNuevos, sizeof(TRSocioNuevo), 1, archNuevos);
		}
	}

	while(!feof(archSocios)) {
		
		fwrite(&regSocios, sizeof(TRSocio), 1, archSociosAct);
		fread(&regSocios, sizeof(TRSocio), 1, archSocios);
	}

	while(!feof(archNuevos)) {
		
		regActualizar.dni = regNuevos.dni;
		regActualizar.socio = regNuevos.socio;
		strcpy(regActualizar.nombre, regNuevos.nombre);
		fwrite(&regActualizar, sizeof(TRSocio), 1, archSociosAct);
		fread(&regNuevos, sizeof(TRSocioNuevo), 1, archNuevos);
	}

	fclose(archSociosAct);
	fclose(archActualizaciones);
	fclose(archNuevos);
	fclose(archSocios);
}
