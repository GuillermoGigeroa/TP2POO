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
        bool BuscarNombreMateria(int ID, char *outNombre);
        bool VerificarSiYaExiste(clsMateriaDTO);
};

#endif // CLSMATERIABL_H
