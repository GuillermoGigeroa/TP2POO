#ifndef CLSMATERIADAO_H
#define CLSMATERIADAO_H
#include "../DTO/clsMateriaDTO.h"

const char ARCHIVO_MATERIAS[] = "Archivo_Materias.dat";
class clsMateriaDAO
{
    public:
        bool Insertar(clsMateriaDTO);
        bool Eliminar(int);
        bool Modificar(clsMateriaDTO);
        bool Listar(clsMateriaDTO *);
        int Count();
};

#endif // CLSMATERIADAO_H
