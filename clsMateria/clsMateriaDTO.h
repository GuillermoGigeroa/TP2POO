#ifndef CLSMATERIADTO_H
#define CLSMATERIADTO_H
#include <cstring>

class clsMateriaDTO
{
    public:
        int GetId_materia() { return id_materia; }
        void SetId_materia(int val) { id_materia = val; }
        char *GetNombre() { return nombre; }
        void SetNombre(const char *val) { strcpy(nombre,val); }
        char *GetProfesor() { return profesor; }
        void SetProfesor(const char *val) { strcpy(profesor,val); }
        bool GetEliminado() { return eliminado; }
        void SetEliminado(bool val) { eliminado = val; }

    protected:

    private:
        int id_materia;
        char nombre[50];
        char profesor[50];
        bool eliminado;
};

#endif // CLSMATERIADTO_H
