#include "clsMenuAyuda.h"
#include "clsHelp.h"
#include <iostream>

void clsMenuAyuda::MenuPrincipal()
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
        ext._EscribirSlow("|            MENU DE AYUDA UNIVERSAL           |");
        ext._EscribirSlow("|______________________________________________|");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|     M - Ayuda con el menu Materias           |");
        ext._EscribirSlow("|     A - Ayuda con el menu Alumnos            |");
        ext._EscribirSlow("|     X - Ayuda con menu Materias por alumnos  |");
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
                    MenuMaterias();
                }break;
            case 'a':
            case 'A':
                {
                    MenuAlumnos();
                }break;
            case 'x':
            case 'X':
                {
                    MenuMXA();
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

void clsMenuAyuda::MenuMaterias()
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
        ext._EscribirSlow("|            MENU DE AYUDA UNIVERSAL           |");
        ext._EscribirSlow("|______________________________________________|");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|     N - AYUDA: Nueva materia                 |");
        ext._EscribirSlow("|     E - AYUDA: Eliminar materia              |");
        ext._EscribirSlow("|     M - AYUDA: Modificar materia             |");
        ext._EscribirSlow("|     L - AYUDA: Buscar materias               |");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|     S - Salir                                |");
        ext._EscribirSlow("|______________________________________________|");
        ext.EscribirSlowParaIngresos("Ingrese una opcion: ");
        cin.getline(opc,500);
        if(opc[0] != '\0' && opc[1] == '\0')
        {
            switch(opc[0])
            {
            case 'n':
            case 'N':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes crear nuevas materias.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar:");
                    ext.EscribirSlow("> Nombre de la materia");
                    ext.EscribirSlow("> Nombre del profesor");
                    ext.EscribirSlow("Y cada materia creada tiene su propio identificador generado por el sistema.");
                    ext.Pausa();
                }break;
            case 'e':
            case 'E':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes eliminar las materias.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar el ID de la materia.");
                    ext.EscribirSlow("Pero no te preocupes si no sabes cuales son, porque antes te va");
                    ext.EscribirSlow("a aparecer un listado con todas las materias creadas hasta ahora.");
                    ext.Pausa();
                }break;
            case 'm':
            case 'M':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes modificar las materias creadas.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar el ID de la materia a modificar.");
                    ext.EscribirSlow("Pero no te preocupes si no sabes cuales son, porque antes te va");
                    ext.EscribirSlow("a aparecer un listado con todas las materias creadas hasta ahora.");
                    ext.Espacio();
                    ext.EscribirSlow("Luego te van a aparecer los nombres, y debajo solamente tenes que");
                    ext.EscribirSlow("ingresar los nuevos valores y seguir con las instrucciones pedidas.");
                    ext.Pausa();
                }break;
            case 'l':
            case 'L':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes listar las materias creadas.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar el nombre de la materia.");
                    ext.EscribirSlow("Pero no te preocupes si no sabes cuales hay, porque podes presionar");
                    ext.EscribirSlow("la tecla enter y el listado completo va a aparecer en pantalla.");
                    ext.EscribirSlow("O simplemente ingresar la parte del nombre de la materia que recuerdes.");
                    ext.Pausa();
                }break;
            case 's':
            case 'S':
                {
                    continuar = false;
                }break;
            default:
                {
                    cout<<endl;
                    ext.EscribirSlow("Opcion incorrecta.");
                    ext.Pausa();
                }break;
            }
        }
    }
}

void clsMenuAyuda::MenuAlumnos()
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
        ext._EscribirSlow("|            MENU DE AYUDA UNIVERSAL           |");
        ext._EscribirSlow("|______________________________________________|");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|     N - AYUDA: Nuevo alumno                  |");
        ext._EscribirSlow("|     E - AYUDA: Eliminar alumno               |");
        ext._EscribirSlow("|     M - AYUDA: Modificar alumno              |");
        ext._EscribirSlow("|     L - AYUDA: Buscar alumnos                |");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|     S - Salir                                |");
        ext._EscribirSlow("|______________________________________________|");
        ext.EscribirSlowParaIngresos("Ingrese una opcion: ");
        cin.getline(opc,500);
        if(opc[0] != '\0' && opc[1] == '\0')
        {
            switch(opc[0])
            {
            case 'n':
            case 'N':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes crear nuevos alumnos en sistema.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar en pantalla los datos:");
                    ext.EscribirSlow("> Nombre completo del alumno");
                    ext.EscribirSlow("> Anio de nacimiento (en numero)");
                    ext.EscribirSlow("> Mes de nacimiento (en numero)");
                    ext.EscribirSlow("> Dia de nacimiento (en numero)");
                    ext.Espacio();
                    ext.EscribirSlow("Y listo!");
                    ext.Pausa();
                }break;
            case 'e':
            case 'E':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes eliminar los alumnos.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar el ID del alumno.");
                    ext.EscribirSlow("Pero no te preocupes si no sabes cuales son, porque antes te va");
                    ext.EscribirSlow("a aparecer un listado con todos los alumnos creados hasta ahora.");
                    ext.Pausa();
                }break;
            case 'm':
            case 'M':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes modificar los alumnos creados.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar el legajo del alumno a modificar.");
                    ext.EscribirSlow("Pero no te preocupes si no sabes cuales son, porque antes te va");
                    ext.EscribirSlow("a aparecer un listado con todos los alumnos creados hasta ahora.");
                    ext.Espacio();
                    ext.EscribirSlow("Luego te van a aparecer los nombres, y debajo solamente tenes que");
                    ext.EscribirSlow("ingresar los nuevos valores y seguir con las instrucciones pedidas.");
                    ext.Pausa();
                }break;
            case 'l':
            case 'L':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes listar los alumnos creados.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar el nombre del alumno.");
                    ext.EscribirSlow("Pero no te preocupes si no sabes cual es, porque podes presionar");
                    ext.EscribirSlow("la tecla enter y el listado completo va a aparecer en pantalla.");
                    ext.EscribirSlow("O simplemente ingresar la parte del nombre de la materia que recuerdes.");
                    ext.Pausa();
                }break;
            case 's':
            case 'S':
                {
                    continuar = false;
                }break;
            default:
                {
                    cout<<endl;
                    ext.EscribirSlow("Opcion incorrecta.");
                    ext.Pausa();
                }break;
            }
        }
    }
}

void clsMenuAyuda::MenuMXA()
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
        ext._EscribirSlow("|            MENU DE AYUDA UNIVERSAL           |");
        ext._EscribirSlow("|______________________________________________|");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|     N - AYUDA: Nueva asignacion de materia...|");
        ext._EscribirSlow("|     E - AYUDA: Eliminar alumno de una materia|");
        ext._EscribirSlow("|     M - AYUDA: Listado de materias por alumno|");
        ext._EscribirSlow("|     A - AYUDA: Listado de alumnos por materia|");
        ext._EscribirSlow("|                                              |");
        ext._EscribirSlow("|     S - Salir                                |");
        ext._EscribirSlow("|______________________________________________|");
        ext.EscribirSlowParaIngresos("Ingrese una opcion: ");
        cin.getline(opc,500);
        if(opc[0] != '\0' && opc[1] == '\0')
        {
            switch(opc[0])
            {
            case 'n':
            case 'N':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes asignar alumnosa las materias.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar en pantalla los datos:");
                    ext.EscribirSlow("> ID de la materia");
                    ext.EscribirSlow("> Legajo del alumno");
                    ext.Espacio();
                    ext.EscribirSlow("Igualmente... antes te van a aparecer los listados");
                    ext.EscribirSlow("con todas las materias y alumnos, es facil!");
                    ext.Pausa();
                }break;
            case 'e':
            case 'E':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes eliminar los registros de alumnos a materias.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar el legajo del alumno,");
                    ext.EscribirSlow("y el ID de la materia a la cual lo vas a eliminar.");
                    ext.Espacio();
                    ext.EscribirSlow("Todo con un listado previo con informacion, obviamente.");
                    ext.Pausa();
                }break;
            case 'M':
            case 'm':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes listar los registros creados por materia.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar el ID de la materia.");
                    ext.EscribirSlow("Pero no te preocupes si no sabes cual es, porque antes");
                    ext.EscribirSlow("te va a aparecer un listado completo.");
                    ext.Pausa();
                }break;
            case 'a':
            case 'A':
                {
                    ext.LimpiarConsola();
                    ext.EscribirSlow("En este menu podes listar los registros creados por alumno.");
                    ext.Espacio();
                    ext.EscribirSlow("Solamente necesitas ingresar el legajo del alumno.");
                    ext.EscribirSlow("Pero no te preocupes si no sabes cual es, porque antes");
                    ext.EscribirSlow("te va a aparecer un listado completo.");
                    ext.Pausa();
                }break;
            case 's':
            case 'S':
                {
                    continuar = false;
                }break;
            default:
                {
                    cout<<endl;
                    ext.EscribirSlow("Opcion incorrecta.");
                    ext.Pausa();
                }break;
            }
        }
    }
}

