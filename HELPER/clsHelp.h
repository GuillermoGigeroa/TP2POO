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
        void EscribirSlow(char *texto);
        void EscribirSlowParaIngresos(char *texto);
        void _EscribirSlow(char *texto);
        void MostrarLogo();
        void Mayusculas(char *texto);
        void Capitalizar(char *texto);
        void Espacio();
        int strSub(char *cad, char *subCad);
};

#endif
