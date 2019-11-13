#include "clsAlumnoBL.h"
#include "clsMxA_BL.h"
#include "../HELPER/clsHelp.h"
#include <cstdlib>

bool clsAlumnoBL::Insertar(clsAlumnoDTO dto)
{
    clsAlumnoDAO dao;
    int legajo = dao.GeneradorDeLegajo();
    dto.SetLegajo(legajo);
    dto.SetEliminado(false);
    return dao.Insertar(dto);
}
bool clsAlumnoBL::Eliminar(int legajo)
{
    clsAlumnoDAO dao;
    clsMxA_BL mxaBL;
    if(legajo < 0) return false;
    return dao.Eliminar(legajo) && mxaBL.EliminarPorLegajo(legajo);
}
bool clsAlumnoBL::Modificar(clsAlumnoDTO dto)
{
    clsAlumnoDAO dao;
    return dao.Modificar(dto);
}
bool clsAlumnoBL::Listar(clsAlumnoDTO *dto)
{
    clsAlumnoDAO dao;
    return dao.Listar(dto);
}
int clsAlumnoBL::Count()
{
    clsAlumnoDAO dao;
    return dao.Count();
}
bool clsAlumnoBL::BuscarNombreAlumno(int legajo, char *outNombre)
{
    clsAlumnoDTO *listaCompleta;
    listaCompleta = (clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*Count());
    Listar(listaCompleta);
    for(int x = 0; x < Count(); x++)
    {
        if(listaCompleta[x].GetLegajo() == legajo)
        {
            listaCompleta[x].GetNombre(outNombre);
            free(listaCompleta);
            return true;
        }
    }
    free(listaCompleta);
    return false;
}

bool clsAlumnoBL::VerificarSiYaExiste(clsAlumnoDTO dto)
{
    clsHelp ext;
    bool seEncontro = false;
    clsAlumnoDAO dao;
    clsAlumnoDTO *listaDto;
    char nombreAlumnoDTO[50];
    dto.GetNombre(nombreAlumnoDTO);
    ext.Mayusculas(nombreAlumnoDTO);
    int diaNacDTO = dto.GetDiaNacimiento();
    int mesNacDTO = dto.GetMesNacimiento();
    int anioNacDTO = dto.GetAnioNacimiento();

    char nombreAlumnoLista[50];
    int diaNacLista, mesNacLista, anioNacLista;

    listaDto = (clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*Count());
    if(dao.Listar(listaDto))
    {
        for(int x = 0; x < Count(); x++)
        {
            listaDto[x].GetNombre(nombreAlumnoLista);
            diaNacLista = listaDto[x].GetDiaNacimiento();
            mesNacLista = listaDto[x].GetMesNacimiento();
            anioNacLista = listaDto[x].GetAnioNacimiento();
            if(!listaDto[x].GetEliminado() && strcmp(nombreAlumnoDTO,nombreAlumnoLista)==0 && diaNacDTO==diaNacLista && mesNacDTO==mesNacLista && anioNacDTO==anioNacLista)
            {
                seEncontro = true;
                break;
            }
        }
    }
    free(listaDto);
    return seEncontro;
}

