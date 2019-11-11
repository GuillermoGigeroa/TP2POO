#ifndef CLSMXA_BL_H
#define CLSMXA_BL_H
#include "../DAO/clsMxA_DAO.h"
#include "../DTO/clsMxA_DTO.h"

class clsMxA_BL
{
    public:
        bool Insertar(clsMxA_DTO);
        bool Eliminar(int ID_Materia, int Legajo);
        bool Modificar(clsMxA_DTO);
        bool Listar(clsMxA_DTO*);
        int Count();
};

#endif // CLSMXA_BL_H
