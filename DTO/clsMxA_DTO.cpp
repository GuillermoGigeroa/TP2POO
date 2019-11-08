#include "clsMxA_DTO.h"

void clsMxA_DTO::Copy(clsMxA_DTO dto)
{
    this->SetID_Materia(dto.GetID_Materia());
    this->SetLegajo(dto.GetLegajo());
    this->SetEliminado(dto.GetEliminado());
}
