#ifndef ALUMNO_H
#define ALUMNO_H

#include <cstring>
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
