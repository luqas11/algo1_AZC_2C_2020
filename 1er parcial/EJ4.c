/* ENUNCIADO
Realizar una función en C llamada MostrarCuenta(int Cuenta), que reciba un numero (9 digitos) y muestre la cuenta con el formato: XXX-XXXXX-X. En caso que la longitud sea incorrecta se debera informar: LONGITUD INCORRECTA

 Ejemplo:
Cuenta: 201200118
Mostrar: 201-20011-8

NOTA:
No se pueden usar String ni vectores para resolver este ejercicio.
Los numeros parciales no tienen ceros a izquierda

*/

#define MAX_CUENTA 1000000000

void MostrarCuenta(int Cuenta) {
	int i,j,k;

	if(Cuenta > MAX_CUENTA) {
		printf("LONGITUD INCORRECTA");
	} else {
		for(i=0; i<9; i++) {
			k=1;
			for(j=0; j<9-i-1; j++) {
				k = k*10;
			}
			k = Cuenta / k;
			printf("%i", k % 10);
			if(i== 7 || i == 2) {
				printf("-");
			}
		}
	}
}
