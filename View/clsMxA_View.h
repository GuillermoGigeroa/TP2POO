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
        void EliminarAlumnoDeMateria();
        void BuscarListadoMXA();
        void BuscarListadoAXM();
        void MostrarMXA(clsMxA_DTO);
        void MostrarAXM(clsMxA_DTO, bool mostrarIDMateria);
    private:
        void MostrarListadoAXM(int legajo);
};

#endif // CLSMXA_VIEW_H
