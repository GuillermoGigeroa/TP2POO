#include "clsMxA_BL.h"
#include <cstdlib>

bool clsMxA_BL::Insertar(clsMxA_DTO dto)
{
    clsMxA_DAO dao;
    int id = dao.GeneradorDeID();
    dto.SetID(id);
    dto.SetEliminado(false);
    return dao.Insertar(dto);
}
bool clsMxA_BL::Eliminar(int ID_Materia, int Legajo)
{
    clsMxA_DAO dao;
    if(ID_Materia < 0 || Legajo < 0)
        return false;
    return dao.Eliminar(ID_Materia,Legajo);
}
bool clsMxA_BL::Modificar(clsMxA_DTO dto)
{
    clsMxA_DAO dao;
    return dao.Modificar(dto);
}
bool clsMxA_BL::Listar(clsMxA_DTO *dto)
{
    clsMxA_DAO dao;
    return dao.Listar(dto);
}
int clsMxA_BL::Count()
{
    clsMxA_DAO dao;
    return dao.Count();
}
