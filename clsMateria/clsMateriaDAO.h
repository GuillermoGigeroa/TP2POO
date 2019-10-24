#ifndef CLSMATERIADAO_H
#define CLSMATERIADAO_H
#include "clsMateriaDTO.h"
const char ARCHIVO_MATERIAS[] = "Archivo_Materias.dat";
class clsMateriaDAO
{
    public:
        bool GuardarMateria(clsMateriaDTO);
        void EliminarMateria(clsMateriaDTO);
        void CargarMateria(int);
};

#endif // CLSMATERIADAO_H
