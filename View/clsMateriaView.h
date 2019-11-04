#ifndef CLSMATERIAVIEW_H
#define CLSMATERIAVIEW_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../DTO/clsMateriaDTO.h"
#include "../DAO/clsMateriaDAO.h"
#include "../BL/clsMateriaBL.h"
using namespace std;

class clsMateriaView
{
    public:
        void Menu();
        void Insertar();
        void Eliminar();
        void Modificar();
        void Listar();
        void BuscarListado();
        void Mostrar(clsMateriaDTO);
};

#endif // CLSMATERIAVIEW_H
