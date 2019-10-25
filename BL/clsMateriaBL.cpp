#include "clsMateriaBL.h"

void clsMateriaBL::Insertar(clsMateriaDTO materia)
{
    clsMateriaDAO dao;
    int id = dao.Count()+1;
    materia.SetID(id);
    dao.Insertar(materia);
    //Inserta la materia en el archivo.
}
void clsMateriaBL::Eliminar(int ID)
{
    clsMateriaDAO dao;
    dao.Eliminar(ID);
    //Elimina la materia del archivo de manera lógica.
}
void clsMateriaBL::Modificar(clsMateriaDTO materia)
{
    clsMateriaDAO dao;
    dao.Modificar(materia);
    //Igual que eliminar, pero pisa el registro completo con otro registro.
}
void clsMateriaBL::Listar(clsMateriaDTO *listaDeMaterias)
{
    //Expulsa a una dirección de memoria para generar un vector.
}
int clsMateriaBL::Count()
{
    //Cuenta la cantidad de registros sin eliminar.
    return 0;
}
