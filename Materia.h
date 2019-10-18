//ABM DE MATERIAS
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
	|	> DATOS:																														|
	|		Se encarga de recibir datos para agregar, actualizar o eliminar en el sistema de persistencia y de obtener los datos	|
	|		almacenados.																											|
	|	> ENTIDADES:																													|
	|		Son las clases que se encargan de transportar la información entre las capas. Son muy similares a las estructuras ya 	|
	|		que poseen un comportamiento mínimo.																					|
	|_______________________________________________________________________________________________________________________________|
*/
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
