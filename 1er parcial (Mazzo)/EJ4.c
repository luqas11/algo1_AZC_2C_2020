/* ENUNCIADO 
Realizar una función en C llamada MostrarSOCIO(lint Socio), que reciba un numero (8 digitos) y muestre el socio con el formato: X-XXXX-XXX. En caso que la longitud sea incorrecta se debera informar: LONGITUD INCORRECTA

 Ejemplo:
SOCIO: 22345678
Mostrar 2-2345-678

NOTA: 
No se pueden usar String ni vectores para resolver este ejercicio.
Los numeros parciales no tienen ceros a izquierda

*/

#include <stdio.h>

int potencia(int a, int b)//función que devuelve el resultado de elevar cierto numero elevado a cierto exponente
{
     int i, resultado = 1;
     for(i = 0; i < b; i++)
     {
          resultado *= a;
     }
     return resultado;
}

int extraerDigito(int n, int d)
{
     return (n / potencia(10, d)) % 10;
}

void MostrarSOCIO(int Socio)
{
     int i;
     if(Socio < potencia(10, 7) || Socio >= potencia(10, 8))
     {
          printf("LONGITUD INCORRECTA");
     }
     else 
     {
          for(i = 7; i >= 0; i--)
          {
               putchar(extraerDigito(Socio, i) + '0');
               if(i == 7 || i == 3)
               {
                    putchar('-');
               }
          }
     }
     putchar('\n');
}

int main() // simplemente escribi el main para probar la función pedida
{
	int socio;
	printf("Ingrese numero de socio: ");
	scanf("%i", &socio);
	
     MostrarSOCIO(socio);
     
     return 0;
}
