#include "clsMateriaBL.h"
#include <cstdlib>

bool clsMateriaBL::Insertar(clsMateriaDTO dto)
{
    clsMateriaDAO dao;
    int id = dao.GeneradorDeID();
    dto.SetID(id);
    dto.SetEliminado(false);
    return dao.Insertar(dto);
}
bool clsMateriaBL::Eliminar(int ID)
{
    clsMateriaDAO dao;
    return dao.Eliminar(ID);
}
bool clsMateriaBL::Modificar(clsMateriaDTO dto)
{
    clsMateriaDAO dao;
    return dao.Modificar(dto);
}
bool clsMateriaBL::Listar(clsMateriaDTO *dto)
{
    clsMateriaDAO dao;
    return dao.Listar(dto);
}
int clsMateriaBL::Count()
{
    clsMateriaDAO dao;
    return dao.Count();
}
