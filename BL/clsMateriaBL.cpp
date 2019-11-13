#include "clsMateriaBL.h"
#include "clsMxA_BL.h"
#include "../HELPER/clsHelp.h"
#include <cstdlib>
#include <cstring>

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
    clsMxA_BL mxaBL;
    if(ID < 0)
        return false;
    return dao.Eliminar(ID) && mxaBL.EliminarPorIdMateria(ID);
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
bool clsMateriaBL::BuscarNombreMateria(int ID, char *outNombre)
{
    clsMateriaDTO *listaCompleta;
    listaCompleta = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*Count());
    Listar(listaCompleta);
    for(int x = 0; x < Count(); x++)
    {
        if(listaCompleta[x].GetID() == ID)
        {
            listaCompleta[x].GetNombre(outNombre);
            free(listaCompleta);
            return true;
        }
    }
    free(listaCompleta);
    return false;
}

bool clsMateriaBL::VerificarSiYaExiste(clsMateriaDTO dto)
{
    clsHelp ext;
    bool seEncontro = false;
    clsMateriaDAO dao;
    clsMateriaDTO *listaDto;
    char nombreMateriaDTO[50];
    dto.GetNombre(nombreMateriaDTO);
    ext.Mayusculas(nombreMateriaDTO);
    char nombreProfesorDTO[50];
    dto.GetProfesor(nombreProfesorDTO);
    ext.Mayusculas(nombreProfesorDTO);

    char nombreMateriaLista[50];
    char nombreProfesorLista[50];

    listaDto = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*Count());
    if(dao.Listar(listaDto))
    {
        for(int x = 0; x < Count(); x++)
        {
            listaDto[x].GetNombre(nombreMateriaLista);
            listaDto[x].GetProfesor(nombreProfesorLista);
            if(!listaDto[x].GetEliminado() && strcmp(nombreMateriaDTO,nombreMateriaLista)==0 && strcmp(nombreProfesorDTO,nombreProfesorLista)==0)
            {
                seEncontro = true;
                break;
            }
        }
    }
    free(listaDto);
    return seEncontro;
}
