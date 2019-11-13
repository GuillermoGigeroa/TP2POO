#ifndef CLSMXA_DAO_H
#define CLSMXA_DAO_H
#include "../DTO/clsMxA_DTO.h"

const char ARCHIVO_MXA[] = "Archivo_MXA.dat";
class clsMxA_DAO
{
    public:
        bool Insertar(clsMxA_DTO);
        bool EliminarPorLegajo(int Legajo);
        bool EliminarPorIdMateria(int ID);
        bool EliminarAlumnoDeMateria(int ID, int Legajo);
        bool Modificar(clsMxA_DTO);
        bool Listar(clsMxA_DTO *);
        int Count();
        bool CargarVectorDinamico(clsMxA_DTO *listaDto);
        bool GuardarEnDisco(clsMxA_DTO *listaDto);
    private:
        void CrearArchivoMxASiNoExiste();
};

#endif // CLSMXA_DAO_H
