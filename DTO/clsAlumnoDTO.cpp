#include "clsAlumnoDTO.h"

void clsAlumnoDTO::Copy(clsAlumnoDTO dto)
{
    char nombre[50];
    this->SetLegajo(dto.GetLegajo());
    dto.GetNombre(nombre);
    this->SetNombre(nombre);
    this->SetDiaNacimiento(dto.GetDiaNacimiento());
    this->SetMesNacimiento(dto.GetMesNacimiento());
    this->SetAnioNacimiento(dto.GetAnioNacimiento());
    this->SetEliminado(dto.GetEliminado());
}
