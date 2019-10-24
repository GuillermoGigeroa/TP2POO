#include <iostream>

#include "Alumnos.h"
#include "Materias.h"
#include "Materias_x_alumno.h"

/*
__________________________________________________________________________________________________________________________
|																															|
| 													Programaci�n en capas													|
|___________________________________________________________________________________________________________________________|
|																															|
|				El desarrollo de debe realizar en un sistema de clases que distribuya las responsabilidades					|
|											seg�n la arquitectura de 3 capas.												|
|___________________________________________________________________________________________________________________________|
|																															|
|> PRESENTACI�N:																											|
|	Es la encargada de la comunicaci�n con el usuario. Presenta los datos y valida los datos ingresados por el usuario.		|
|																															|
|> NEGOCIO:																													|
|	Se encarga de hacer todas las operaciones llamando a los distintos accesos de datos, agrupando, validando y haciendo	|
|	de intermediario entre los datos y la presentaci�n.																		|
|																															||> DATOS:																													|
|	Se encarga de recibir datos para agregar, actualizar o eliminar en el sistema de persistencia y de obtener los datos	|
|	almacenados.																											|
|																															|
|> ENTIDADES:																												|
|	Son las clases que se encargan de transportar la informaci�n entre las capas. Son muy similares a las estructuras ya 	|
|	que poseen un comportamiento m�nimo.																					|
|___________________________________________________________________________________________________________________________|
*/

using namespace std;

int main(){
    Alumno alumno;
    alumno.altaAlumno();
	return 0;
}
