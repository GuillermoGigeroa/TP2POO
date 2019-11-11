#ifndef CLSMXA_DTO_H
#define CLSMXA_DTO_H


class clsMxA_DTO
{
    public:
        int GetID_Materia() { return ID_Materia; }
        int GetLegajo() { return legajo; }
        bool GetEliminado() { return eliminado; }
        int GetID() {return ID;}

        void SetID_Materia(int val) { ID_Materia = val; }
        void SetLegajo(int val) { legajo = val; }
        void SetEliminado(bool val) { eliminado = val; }
        void SetID(int ID){this->ID = ID;}

        void Copy(clsMxA_DTO);
    private:
        int ID;
        int ID_Materia;
        int legajo;
        bool eliminado;
};

#endif // CLSMXA_DTO_H
