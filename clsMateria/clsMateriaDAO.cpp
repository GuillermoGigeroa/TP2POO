#include "clsMateriaDAO.h"
#include <cstdio>
bool GuardarMateria(clsMateriaDTO)
{
    FILE *p;
    p = fopen(ARCHIVO_MATERIAS,"ab");
    if (p == NULL) return false;
    //TODO Continuar con esta funci�n.
    fclose(p);
}
void EliminarMateria(clsMateriaDTO)
{

}
void CargarMateria(int)
{

}

