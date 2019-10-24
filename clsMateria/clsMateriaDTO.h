#ifndef CLSMATERIADTO_H
#define CLSMATERIADTO_H


class clsMateriaDTO
{
    public:
        int GetId_materia() { return id_materia; }
        void SetId_materia(int val) { id_materia = val; }
        char GetNombre[50]() { return nombre[50]; }
        void SetNombre[50](char val) { nombre[50] = val; }
        char GetProfesor[50]() { return profesor[50]; }
        void SetProfesor[50](char val) { profesor[50] = val; }
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
