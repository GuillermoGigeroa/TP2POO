#ifndef CLSMATERIABL_H
#define CLSMATERIABL_H
#include "../DAO/clsMateriaDAO.h"
#include "../DTO/clsMateriaDTO.h"

class clsMateriaBL
{
    public:
        bool Insertar(clsMateriaDTO);
        bool Eliminar(int);
        bool Modificar(clsMateriaDTO);
        bool Listar(clsMateriaDTO*);
        int Count();
};

#endif // CLSMATERIABL_H
