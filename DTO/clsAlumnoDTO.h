#ifndef CLSALUMNODTO_H
#define CLSALUMNODTO_H
#include <cstring>

class clsAlumnoDTO
{
    public:
        int GetLegajo() { return legajo; }
        void GetNombre(char *val) { strcpy(val,nombre); }
        int GetDiaNacimiento() { return dia_nacimiento; }
        int GetMesNacimiento() { return mes_nacimiento; }
        int GetAnioNacimiento() { return anio_nacimiento; }
        bool GetEliminado() { return eliminado; }

        void SetNombre(char *val) { strcpy(nombre,val); }
        void SetLegajo(int val) { legajo = val; }
        void SetDiaNacimiento(int val) { dia_nacimiento = val; }
        void SetMesNacimiento(int val) { mes_nacimiento = val; }
        void SetAnioNacimiento(int val) { anio_nacimiento = val; }
        void SetEliminado(bool val) { eliminado = val; }

        void Copy(clsAlumnoDTO);

    private:
        int legajo;
        char nombre[50];
        int dia_nacimiento;
        int mes_nacimiento;
        int anio_nacimiento;
        bool eliminado;
};

#endif // CLSALUMNODTO_H
