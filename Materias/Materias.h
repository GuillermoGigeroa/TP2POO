#ifndef MATERIA_H
#define MATERIA_H

#include <cstring>
class Materia{
private:
	int id_materia;
	char nombre[50];
	char profesor[50];
	bool eliminado;
public:
	//SETTERS
	void setId_materia(int ID){id_materia = ID;}
	void setNombre(char *esteNombre);
	void setProfesor(char *esteProfesor);
	void setEliminado(bool eliminado){this->eliminado = eliminado;}
	//GETTERS
	int getId_materia(){return id_materia;}
	char *getNombre(){return nombre;}
	char *getProfesor(){return profesor;}
	bool getEliminado(){return eliminado;}
	//FUNCIONES PARA EL ABM
	void altaMateria();
	void bajaMateria();
	void modificarMateria();
	//FUNCION PARA LISTAR CON BUSQUEDA POR NOMBRE
	void listarMaterias(char *estaMateria);
};

#endif //MATERIA_H
