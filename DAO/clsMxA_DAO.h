#ifndef CLSMXA_DAO_H
#define CLSMXA_DAO_H
#include "../DTO/clsMxA_DTO.h"

const char ARCHIVO_MXA[] = "Archivo_MXA.dat";
class clsMxA_DAO
{
    public:
        bool Insertar(clsMxA_DTO);
        bool Eliminar(int);
        bool Modificar(clsMxA_DTO);
        bool Listar(clsMxA_DTO *);
        int Count();
        int GeneradorDeID();
    private:
        void CrearArchivoMxASiNoExiste();
};

#endif // CLSMXA_DAO_H
