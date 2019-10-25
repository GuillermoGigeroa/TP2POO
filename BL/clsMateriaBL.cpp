#include "clsMateriaBL.h"
#include <cstdlib>

void clsMateriaBL::Insertar(clsMateriaDTO dto)
{
    clsMateriaDAO dao;
    int id = dao.Count()+1;
    dto.SetID(id);
    dto.SetEliminado(false);
    dao.Insertar(dto);
}
void clsMateriaBL::Eliminar(int ID)
{
    clsMateriaDAO dao;
    dao.Eliminar(ID);
}
void clsMateriaBL::Modificar(clsMateriaDTO dto)
{
    clsMateriaDAO dao;
    dao.Modificar(dto);
}
void clsMateriaBL::Listar(clsMateriaDTO *listaDto)
{
    clsMateriaDAO dao;
    listaDto = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*dao.Count());
    dao.Listar(listaDto);
}
int clsMateriaBL::Count()
{
    clsMateriaDAO dao;
    return dao.Count();
}
