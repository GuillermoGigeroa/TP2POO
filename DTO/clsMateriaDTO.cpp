#include "clsMateriaDTO.h"

void clsMateriaDTO::Copy(clsMateriaDTO dto)
{
    char nombre[50];
    char profesor[50];
    this->SetID(dto.GetID());
    dto.GetNombre(nombre);
    this->SetNombre(nombre);
    dto.GetProfesor(profesor);
    this->SetProfesor(profesor);
}
