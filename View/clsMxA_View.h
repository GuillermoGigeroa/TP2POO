#ifndef CLSMXA_VIEW_H
#define CLSMXA_VIEW_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../DTO/clsMxA_DTO.h"
#include "../DAO/clsMxA_DAO.h"
#include "../BL/clsMxA_BL.h"

class clsMxA_View
{
    public:
        void Menu();
        void Insertar();
        void Eliminar();
        void BuscarListadoMXA();
        void BuscarListadoAXM();
        void Mostrar(clsMxA_DTO);
};

#endif // CLSMXA_VIEW_H
