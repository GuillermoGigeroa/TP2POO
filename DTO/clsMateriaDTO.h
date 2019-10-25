#ifndef CLSMATERIADTO_H
#define CLSMATERIADTO_H
#include <cstring>

class clsMateriaDTO
{
    public:
        int  GetID() { return id_materia; }
        void GetNombre(char *val) { strcpy(val,nombre); }
        void GetProfesor(char *val) { strcpy(nombre,val); }
        bool GetEliminado() { return eliminado; }

        void SetID(int val) { id_materia = val; }
        void SetNombre(char *val) { strcpy(nombre,val); }
        void SetProfesor(char *val) { strcpy(profesor,val); }
        void SetEliminado(bool val) { eliminado = val; }

        void Copy(clsMateriaDTO);

    private:
        int id_materia;
        char nombre[50];
        char profesor[50];
        bool eliminado;
};

#endif // CLSMATERIADTO_H
