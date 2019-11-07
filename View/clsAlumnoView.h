#ifndef CLSALUMNOVIEW_H
#define CLSALUMNOVIEW_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "../DTO/clsAlumnoDTO.h"
#include "../DAO/clsAlumnoDAO.h"
#include "../BL/clsAlumnoBL.h"
using namespace std;

class clsAlumnoView
{
    public:
        void Menu();
        void Insertar();
        void Eliminar();
        void Modificar();
        void Listar();
        void BuscarListado();
        void Mostrar(clsAlumnoDTO);
};

#endif // CLSALUMNOVIEW_H
