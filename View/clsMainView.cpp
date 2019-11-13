#include "clsMainView.h"
#include "../HELPER/clsHelp.h"
#include "../HELPER/clsMenuAyuda.h"

void clsMainView::Menu()
{
	clsHelp ext;
    char opc[500];
    bool continuar = true;
    while(continuar)
    {
        ext.LimpiarConsola();
        ext._EscribirSlow(" ______________________________________________ ");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|           G.I.G.E.R.O.A.B.L.A.C.K.           |");
        ext._EscribirSlow("|______________________________________________|");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|     M - Materias                             |");
        ext._EscribirSlow("|     A - Alumnos                              |");
        ext._EscribirSlow("|     X - Materias por alumnos                 |");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|     H - Ayuda                                |");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|     S - Salir                                |");
        ext._EscribirSlow("|______________________________________________|");
        ext.EscribirSlowParaIngresos("Ingrese una opcion: ");
        cin.getline(opc,500);
        if(opc[0] != '\0' && opc[1] == '\0')
        {
            switch(opc[0])
            {
            case 'm':
            case 'M':
                {
                    clsMateriaView matView;
                    matView.Menu();
                }break;
            case 'a':
            case 'A':
                {
                    clsAlumnoView aluView;
                    aluView.Menu();
                }break;
            case 'x':
            case 'X':
                {
                    clsMxA_View mxaView;
                    mxaView.Menu();
                }break;
            case 'h':
            case 'H':
                {
                    clsMenuAyuda mayuda;
                    mayuda.MenuPrincipal();
                }break;
            case 's':
            case 'S':
                {
                    continuar = false;
                }break;
            default:
                {
                    ext.Espacio();
                    ext.EscribirSlow("Opcion incorrecta...");
                    ext.Pausa();
                }break;
            }
        }
    }
}

void clsMainView::Presentacion()
{
    clsHelp ext;
    ext.LimpiarConsola();
    ext.MostrarLogo();
    ext.Espacio();
    ext.EscribirSlow("      BIENVENIDO AL SISTEMA DE ALUMNOS Y MATERIAS \"CLS\"");
    ext.Pausa();
    ext.LimpiarConsola();
}

void clsMainView::Despedida()
{
    clsHelp ext;
    ext.LimpiarConsola();
    ext.MostrarLogo();
    ext.Espacio();
    ext.EscribirSlow("  GRACIAS POR UTILIZAR EL SISTEMA DE ALUMNOS Y MATERIAS \"CLS\"");
    ext.Espacio();
    ext.EscribirSlow("                                        Por Guillermo Gigeroa");
    ext.Pausa();
    ext.LimpiarConsola();
}
