/* ENUNCIADO EJERCICIO 2:

Un banco dispone de un programa escrito en lenguaje C que almacena la informacion de sus clientes en una tabla, segun las siguientes declaraciones:

// Constantes
#define TAMANIO 3000

// Tipos
typedef char cadena[50];

// definimos una estructura T_Libro
typedef struct
{
     int Id_Cliente; // Identificado del cliente
     cadena NomApel; // Nombre y Apellido del cliente
     int Categoria; // Categoria del cliente ( inicialmente hay 3 cat: 1, 2 y 3)
     float Saldo;  // Saldo del cliente
     int Puntos;  // Puntos que tiene el cliente en el plan de fidelizacion del banco
} T_RegCliente;

// Variables
T_RegCliente Tabla[TAMANIO];

int ML_Tabla;

Dada la decision de agregar una nueva categoria de cliente, se solicita desarrollar una funcion que será invocada para procesar y actualizar los registros en la mencionada tabla, segun el siguiente criterio:

- los clientes Categoria 3 cuyo Saldo sea superior a $130.000 (ciento treinta mil pesos) pasan a ser categoria 4
- como premio por su promocion, al cliente promovido se le "regala" un 5% en sus Puntos (por ejemplo, si tenia 200 puntos, pasara a tener 210 puntos).

La funcion solicitada debe dejar la tabla actualizada con las nuevas Categorias y Puntos, y devolver la cantidad de clientes que fueron promovidos.

Nota:
- La tabla, su maximo logico, y los demas datos utilizados deben pasarse a traves de parametros.
- Codificar el programa principal con las estructuras de datos necesarias y la invocacion al modulo desarrollado.

*/

#include<stdio.h>
// Constantes
#define TAMANIO 3000
#define MIN_SALDO 130000
#define PREMIO_PUNTOS 0.05

// Tipos
typedef char cadena[50];

// definimos una estructura T_Libro
typedef struct {
	int Id_Cliente; // Identificado del cliente
	cadena NomApel; // Nombre y Apellido del cliente
	int Categoria; // Categoria del cliente ( inicialmente hay 3 cat: 1, 2 y 3)
	float Saldo;  // Saldo del cliente
	int Puntos;  // Puntos que tiene el cliente en el plan de fidelizacion del banco
} T_RegCliente;

int actualizarTabla(T_RegCliente Tabla[], int ML_Tabla) {
	int i,sumatoria = 0;;
	
	for (i=0; i<ML_Tabla; i++) {
		if (Tabla[i].Categoria == 3 && Tabla[i].Saldo > MIN_SALDO) {
			Tabla[i].Categoria = 4;
			Tabla[i].Puntos += Tabla[i].Puntos * PREMIO_PUNTOS;
			sumatoria++;
		}
	}
	return sumatoria;
}

void main() {
	// Variables
	T_RegCliente Tabla[TAMANIO];
	int ML_Tabla;

	printf("La cantidad de clientes que fueron promovidos es %i", actualizarTabla(Tabla, ML_Tabla));

}
