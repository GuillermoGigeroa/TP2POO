#include "clsMxA_View.h"
#include "clsMateriaView.h"
#include "../HELPER/clsHelp.h"
#include <iomanip>
#include <string>

void clsMxA_View::Menu()
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
        ext._EscribirSlow("|     N - Nueva asignacion de materia a alumno |");
        ext._EscribirSlow("|     E - Eliminar registro                    |");
        ext._EscribirSlow("|     M - Listado de materias por alumno       |");
        ext._EscribirSlow("|     A - Listado de alumnos por materia       |");
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
                    Insertar();
                    ext.Pausa();
                }break;
            case 'e':
            case 'E':
                {
                    Eliminar();
                    ext.Pausa();
                }break;
            case 'M':
            case 'm':
                {
                    BuscarListadoMXA();
                    ext.Pausa();
                }break;
            case 'a':
            case 'A':
                {
                    BuscarListadoAXM();
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

void clsMxA_View::Insertar()
{
    //TODO Modificar para que funcione con el clsMXA
    clsHelp ext;
    ext.LimpiarConsola();
    char ID_Materia_char[50];
    char legajo_char[50];
    clsMxA_DTO dto;
    clsMxA_BL bl;
    clsMateriaView listaMaterias;
    listaMaterias.Listar();
    ext.EscribirSlow(" ~~~~~~~~~~~~~~~ NUEVO REGISTRO ~~~~~~~~~~~~~~~");
    ext.Espacio();
    ext.EscribirSlowParaIngresos("Ingrese el ID de la materia: ");
    cin.getline(ID_Materia_char,50);
    ext.EscribirSlowParaIngresos("Ingrese el legajo del alumno: ");
    cin.getline(legajo_char,50);
    int ID_Materia = atoi(ID_Materia_char);
    int legajo = atoi(legajo_char);
    //TODO Continuar con esto
    dto.SetID_Materia(ID_Materia);
    dto.SetLegajo(legajo);

    if(bl.Insertar(dto))
    {
        ext.Espacio();
        ext.EscribirSlow("Se ha creado la nueva materia correctamente.");
    }
    else
    {
        ext.Espacio();
        ext.EscribirSlow("Error: No se ha creado la nueva materia correctamente.");
    }
}
//
//void clsMxA_View::Eliminar()
//{
//    //TODO Modificar para que funcione con el clsMXA
//    clsHelp ext;
//    char ID_char[50];
//    ID_char[0] = 'a';
//    while(!ext.VerificarSiEsNumero(ID_char))
//    {
//        ext.LimpiarConsola();
//        Listar();
//        ext.Espacio();
//        ext.EscribirSlow(" ~~~~~~~~~~~~~~~ ELIMINAR MATERIA ~~~~~~~~~~~~~~~");
//        ext.Espacio();
//        ext.EscribirSlowParaIngresos("Ingrese el ID de la materia a eliminar: ");;
//        cin.getline(ID_char,50);
//        if(ext.VerificarSiEsNumero(ID_char))
//        {
//            int ID = atoi(ID_char);
//            clsMateriaBL bl;
//            if(bl.Eliminar(ID))
//            {
//                ext.Espacio();
//                ext.EscribirSlow("Se ha eliminado la materia correctamente.");
//            }
//            else
//            {
//                ext.Espacio();
//                ext.EscribirSlow("Error: No se ha eliminado la materia correctamente.");
//            }
//        }
//    }
//
//}
//
//void clsMxA_View::Mostrar(clsMateriaDTO dto)
//{
//    //TODO Modificar para que funcione con el clsMXA
//    clsHelp ext;
//    char nombre[50];
//    dto.GetNombre(nombre);
//    ext.Capitalizar(nombre);
//    char profesor[50];
//    dto.GetProfesor(profesor);
//    ext.Capitalizar(profesor);
//    cout<<"| "<<setw(4)<<left<<dto.GetID()
//        <<" | "<<setw(42)<<left<<nombre
//        <<" | "<<setw(42)<<left<<profesor
//        <<" |"<<endl;
//    cout<<"|______|____________________________________________|____________________________________________|"<<endl;
//}
//
//void clsMxA_View::BuscarListadoMXA()
//{
//    //TODO Modificar para que funcione con el clsMXA
//    clsHelp ext;
//    ext.LimpiarConsola();
//    char loQueIngresaUsuario[50];
//    ext.EscribirSlow("Ingrese el nombre de la materia, o presione enter para listado completo: ");
//    cin.getline(loQueIngresaUsuario,50);
//    ext.Mayusculas(loQueIngresaUsuario);
//    ext.LimpiarConsola();
//    clsMateriaDTO *dto;
//    clsMateriaBL bl;
//    dto = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*bl.Count());
//    char nombre[50];
//    if(bl.Listar(dto))
//    {
//        ext._EscribirSlow("            ~~~~~~~~~~~~~~~~~~~~~~~~~ LISTADO DE MATERIAS ~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
//        ext._EscribirSlow(" ______ ____________________________________________ ____________________________________________ ");
//        ext._EscribirSlow("|      |                                            |                                            |");
//        ext._EscribirSlow("|  ID  |            NOMBRE DE MATERIA               |              NOMBRE DE PROFESOR            |");
//        ext._EscribirSlow("|______|____________________________________________|____________________________________________|");
//        for(int x=0;x < bl.Count(); ++x)
//        {
//            dto[x].GetNombre(nombre);
//            if(ext.strSub(nombre,loQueIngresaUsuario) != -1)
//            {
//                Mostrar(dto[x]);
//            }
//        }
//    }
//    else
//    {
//        ext.Espacio();
//        ext.EscribirSlow("Error: No se ha podido listar las materias.");
//    }
//    free(dto);
//}

void clsMxA_View::BuscarListadoAXM()
{

}
