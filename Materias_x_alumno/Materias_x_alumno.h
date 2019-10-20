#ifndef MATERIA_X_ALUMNO_H
#define MATERIA_X_ALUMNO_H

#include "Materias_x_alumno_Presentacion.h"
#include "Materias_x_alumno_Negocio.h"
#include "Materias_x_alumno_Datos.h"
#include "Materias_x_alumno_Entidad.h"

#include <cstring>
class Materia_x_alumno{
private:
    Materias_x_alumno_Presentacion p;
    Materias_x_alumno_Negocio n;
    Materias_x_alumno_Datos d;
    Materias_x_alumno_Entidad e;
	int id_materia;
	int legajo;
	bool eliminado;
public:
	//SETTERS
	void setId_materia(int ID){id_materia = ID;}
	void setLegajo(int legajo){this->legajo = legajo;}
	void setEliminado(bool eliminado){this->eliminado = eliminado;}
	//GETTERS
	int getId_materia(){return id_materia;}
	int getLegajo(){return legajo;}
	bool getEliminado(){return eliminado;}
	//FUNCIONES PARA EL ABM
	void altaMXA();
	void bajaMXA();
	void modificarMXA();
	//FUNCIONES LISTAR
	void listadoAlumnosPorMateria();
	void listadoMateriasPorAlumno();
	//FUNCIONES PARA DAR DE BAJA A UN ALUMNO
	void bajaAlumnoDeMateria();
};

#endif //MATERIA_X_ALUMNO_H
