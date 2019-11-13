#ifndef CLSMXA_BL_H
#define CLSMXA_BL_H
#include "../DAO/clsMxA_DAO.h"
#include "../DTO/clsMxA_DTO.h"

class clsMxA_BL
{
    public:
        bool Insertar(clsMxA_DTO);
        bool EliminarAlumnoDeMateria(int ID, int legajo);
        bool EliminarPorLegajo(int Legajo);
        bool EliminarPorIdMateria(int ID);
        bool Modificar(clsMxA_DTO);
        bool Listar(clsMxA_DTO*);
        int Count();
        bool VerificarSiYaExiste(clsMxA_DTO);
};

#endif // CLSMXA_BL_H
