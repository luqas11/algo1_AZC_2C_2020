#include<stdio.h>
#include<stdbool.h>

#define MAX 30

void main(){
	FILE *archivo;
	char caracter;
	bool finPalabra = false;;
	int longitud = 0;
	int palabras = 0;
	int monosilabos = 0;
	int caracteres = 0;
		
	archivo = fopen("archivo.txt", "r");
	
	caracter = fgetc(archivo);
	while(!feof(archivo)){
		if((caracter > 64 && caracter < 91) || (caracter > 96 && caracter < 123)){
			longitud++;
			caracteres++;
			finPalabra = false;
		}else{
			if(finPalabra == false){
				if(longitud < 4){
					monosilabos++;
				}
				longitud = 0;
				palabras++;
			}
			finPalabra = true;
		}
		caracter = fgetc(archivo);
	}
	printf("Cantidad de palabras: %i \nCantidad de monosilabos: %i \nLongitud promedio de las palabras: %i", palabras, monosilabos, caracteres/palabras);
	fclose(archivo);
}
