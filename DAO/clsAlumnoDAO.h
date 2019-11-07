#ifndef CLSALUMNODAO_H
#define CLSALUMNODAO_H
#include "../DTO/clsAlumnoDTO.h"

const char ARCHIVO_ALUMNOS[] = "Archivo_Alumnos.dat";
class clsAlumnoDAO
{
    public:
        bool Insertar(clsAlumnoDTO);
        bool Eliminar(int);
        bool Modificar(clsAlumnoDTO);
        bool Listar(clsAlumnoDTO *);
        int Count();
        int GeneradorDeLegajo();
    private:
        void CrearArchivoAlumnosSiNoExiste();
};

#endif // CLSALUMNODAO_H
