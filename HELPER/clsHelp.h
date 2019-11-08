#ifndef CLSHELP_H
#define CLSHELP_H
#include <string>
using namespace std;

class clsHelp
{
	public:
        void LimpiarConsola();
        void Pausa();
        bool VerificarSiEsNumero(char *numEnTexto);
        bool VerificarSiEsTexto(char *esteChar);
        void EscribirSlow(const char *texto);
        void EscribirSlowParaIngresos(const char *texto);
        void _EscribirSlow(const char *texto);
        void MostrarLogo();
        void Mayusculas(char *texto);
        void Capitalizar(char *texto);
        void Espacio();
        int strSub(char *cad, char *subCad);
        void ConfigurarConsola();
        bool ValidarAnio(char *esteNumero);
        bool ValidarMes(char *esteNumero);
        bool ValidarDia(char *esteNumero);
        void EscribirFecha(int dia, int mes, int anio);
};

#endif
