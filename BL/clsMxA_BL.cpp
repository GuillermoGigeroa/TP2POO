#include "clsMxA_BL.h"
#include <cstdlib>

bool clsMxA_BL::Insertar(clsMxA_DTO dto)
{
    clsMxA_DAO dao;
    dto.SetEliminado(false);
    return dao.Insertar(dto);
}
bool clsMxA_BL::EliminarAlumnoDeMateria(int ID, int Legajo)
{
    clsMxA_DAO dao;
    if(ID < 0 || Legajo < 0) return false;
    return dao.EliminarAlumnoDeMateria(ID,Legajo);
}
bool clsMxA_BL::EliminarPorLegajo(int Legajo)
{
    clsMxA_DAO dao;
    if(Legajo < 0)
        return false;
    return dao.EliminarPorLegajo(Legajo);
}
bool clsMxA_BL::EliminarPorIdMateria(int ID)
{
    clsMxA_DAO dao;
    if(ID < 0)
        return false;
    return dao.EliminarPorIdMateria(ID);
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
bool clsMxA_BL::VerificarSiYaExiste(clsMxA_DTO dto)
{
    bool seEncontro = false;
    clsMxA_DAO dao;
    clsMxA_DTO *listaDto;
    listaDto = (clsMxA_DTO*)malloc(sizeof(clsMxA_DTO)*Count());
    if(dao.Listar(listaDto))
    {
        for(int x = 0; x < Count(); x++)
        {
            if(!dto.GetEliminado() && dto.GetID_Materia()==listaDto[x].GetID_Materia() && dto.GetLegajo()==listaDto[x].GetLegajo())
            {
                seEncontro = true;
                break;
            }
        }
    }
    free(listaDto);
    return seEncontro;
}
