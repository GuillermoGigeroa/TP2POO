#ifndef CLSALUMNOBL_H
#define CLSALUMNOBL_H
#include "../DAO/clsAlumnoDAO.h"
#include "../DTO/clsAlumnoDTO.h"

class clsAlumnoBL
{
    public:
        bool Insertar(clsAlumnoDTO);
        bool Eliminar(int);
        bool Modificar(clsAlumnoDTO);
        bool Listar(clsAlumnoDTO*);
        int Count();
        bool BuscarNombreAlumno(int legajo, char *outNombre);
        bool VerificarSiYaExiste(clsAlumnoDTO);
};

#endif // CLSALUMNOBL_H
