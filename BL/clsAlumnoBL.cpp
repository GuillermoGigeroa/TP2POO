#include "clsAlumnoBL.h"
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
    if(legajo < 0)
        return false;
    return dao.Eliminar(legajo);
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

