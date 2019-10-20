#ifndef ALUMNO_H
#define ALUMNO_H

//ABM DE ALUMNOS
#include <cstring>
/*
	 _______________________________________________________________________________________________________________________________
	|																																|
	| 													Programación en capas														|
	|_______________________________________________________________________________________________________________________________|
	|																																|
	|				El desarrollo de debe realizar en un sistema de clases que distribuya las responsabilidades						|
	|											según la arquitectura de 3 capas.													|
	|_______________________________________________________________________________________________________________________________|
	|																																|
	|	> PRESENTACIÓN:																												|
	|		Es la encargada de la comunicación con el usuario. Presenta los datos y valida los datos ingresados por el usuario.		|
	|	> NEGOCIO:																													|
	|		Se encarga de hacer todas las operaciones llamando a los distintos accesos de datos, agrupando, validando y haciendo	|
	|		de intermediario entre los datos y la presentación.																		|
	|	> DATOS:																													|
	|		Se encarga de recibir datos para agregar, actualizar o eliminar en el sistema de persistencia y de obtener los datos	|
	|		almacenados.																											|
	|	> ENTIDADES:																												|
	|		Son las clases que se encargan de transportar la información entre las capas. Son muy similares a las estructuras ya 	|
	|		que poseen un comportamiento mínimo.																					|
	|_______________________________________________________________________________________________________________________________|
*/
const char ALUMNOS[12] = "Alumnos.dat";
class Alumno{
private:
	int legajo;
	char nombre[50];
	int dia_nac;
	int mes_nac;
	int anio_nac;
	bool eliminado;
public:
	//SETTERS
	void setLegajo(int legajo){this->legajo = legajo;}
	void setNombre(char *nombre);
	void setDia(int dia){dia_nac = dia;}
	void setMes(int mes){mes_nac = mes;}
	void setAnio(int anio){anio_nac = anio;}
	void setEliminado(bool eliminado){this->eliminado = eliminado;}
	//GETTERS
	int getLegajo(){return legajo;}
	char *getNombre(){return nombre;}
	int getDia(){return dia_nac;}
	int getMes(){return mes_nac;}
	int getAnio(){return anio_nac;}
	int getEliminado(){return eliminado;}
	//FUNCIONES PARA EL ABM
	void altaAlumno();
	void bajaAlumno();
	void modificarAlumno();
	//FUNCION PARA LISTAR CON BUSQUEDA POR NOMBRE
	void listarMaterias(char *estaMateria);
};

#endif // ALUMNO_H
