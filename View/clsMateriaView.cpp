#include "clsMateriaView.h"
#include "../HELPER/clsHelp.h"
#include <iomanip>
#include <string>

void clsMateriaView::Menu()
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
        ext._EscribirSlow("|     N - Nueva materia                        |");
        ext._EscribirSlow("|     E - Eliminar materia                     |");
        ext._EscribirSlow("|     M - Modificar materia                    |");
        ext._EscribirSlow("|     L - Buscar materias                      |");
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
            case 'm':
            case 'M':
                {
                    Modificar();
                    ext.Pausa();
                }break;
            case 'l':
            case 'L':
                {
                    BuscarListado();
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

void clsMateriaView::Insertar()
{
    clsHelp ext;
    ext.LimpiarConsola();
    char nombre[50];
    char profesor[50];
    clsMateriaDTO dto;
    clsMateriaBL bl;
    ext.EscribirSlow(" ~~~~~~~~~~~~~~~ NUEVA MATERIA ~~~~~~~~~~~~~~~");
    ext.Espacio();
    ext.EscribirSlowParaIngresos("Ingrese el nombre de la materia: ");
    cin.getline(nombre,50);
    ext.Mayusculas(nombre);
    ext.EscribirSlowParaIngresos("Ingrese el nombre del profesor: ");
    cin.getline(profesor,50);
    ext.Mayusculas(profesor);
    while(!ext.VerificarSiEsTexto(profesor))
    {
        cin.getline(profesor,50);
        ext.Mayusculas(profesor);
    }
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
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

void clsMateriaView::Eliminar()
{
    clsHelp ext;
    char ID_char[50];
    ID_char[0] = 'a';
    while(!ext.VerificarSiEsNumero(ID_char))
    {
        ext.LimpiarConsola();
        Listar();
        ext.Espacio();
        ext.EscribirSlow(" ~~~~~~~~~~~~~~~ ELIMINAR MATERIA ~~~~~~~~~~~~~~~");
        ext.Espacio();
        ext.EscribirSlowParaIngresos("Ingrese el ID de la materia a eliminar: ");;
        cin.getline(ID_char,50);
        if(ext.VerificarSiEsNumero(ID_char))
        {
            int ID = atoi(ID_char);
            clsMateriaBL bl;
            if(bl.Eliminar(ID))
            {
                ext.Espacio();
                ext.EscribirSlow("Se ha eliminado la materia correctamente.");
            }
            else
            {
                ext.Espacio();
                ext.EscribirSlow("Error: No se ha eliminado la materia correctamente.");
            }
        }
    }

}

void clsMateriaView::Modificar()
{
    clsHelp ext;
    clsMateriaBL bl;
    clsMateriaDTO dto;
    clsMateriaDTO *listaDto;

    ext.LimpiarConsola();
    Listar();
    ext.EscribirSlow(" ~~~~~~~~~~~~~~~ MODIFICAR MATERIA ~~~~~~~~~~~~~~~");
    ext.Espacio();
    ext.EscribirSlowParaIngresos("Ingrese el ID de la materia a modificar: ");
    char ID_char[50];
    ID_char[0] = 'a';
    while(!ext.VerificarSiEsNumero(ID_char))
    {
        cin.getline(ID_char,50);
        if(ext.VerificarSiEsNumero(ID_char) && ID_char[0] != '\0')
        {
            int ID;
            ID = atoi(ID_char);

            listaDto = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*bl.Count());
            if(bl.Listar(listaDto))
            {
                bool seEncontro = false;
                for(int x = 0; x < bl.Count(); ++x)
                {
                    if(listaDto[x].GetID() == ID && !listaDto[x].GetEliminado())
                    {
                        dto.Copy(listaDto[x]);
                        seEncontro = true;
                    }
                }

                if (seEncontro)
                {
                    char nombre[50];
                    dto.GetNombre(nombre);
                    char profesor[50];
                    dto.GetProfesor(profesor);
                    ext.EscribirSlowParaIngresos("              ID: ");
                    cout<<dto.GetID()<<endl;
                    ext.EscribirSlowParaIngresos("  Nombre antiguo: ");
                    ext.Capitalizar(nombre);
                    ext.EscribirSlow(nombre);
                    ext.EscribirSlowParaIngresos("    Nombre nuevo: ");
                    cin.getline(nombre,50);
                    ext.Mayusculas(nombre);
                    ext.EscribirSlowParaIngresos("Profesor antiguo: ");
                    ext.Capitalizar(profesor);
                    ext.EscribirSlow(profesor);
                    ext.EscribirSlowParaIngresos("  Profesor nuevo: ");
                    cin.getline(profesor,50);
                    ext.Mayusculas(profesor);
                    while(!ext.VerificarSiEsTexto(profesor))
                    {
                        cin.getline(profesor,50);
                        ext.Mayusculas(profesor);
                    }
                    dto.SetNombre(nombre);
                    dto.SetProfesor(profesor);
                    if(bl.Modificar(dto))
                    {
                        ext.Espacio();
                        ext.EscribirSlow("Se ha modificado la materia correctamente.");
                    }
                    else
                    {
                        ext.Espacio();
                        ext.EscribirSlow("Error: No se ha modificado la materia.");
                    }
                }
                else
                {
                    ext.Espacio();
                    ext.EscribirSlow("Error: No se ha encontrado el ID ingresado.");
                }
            }
            else
            {
                ext.Espacio();
                ext.EscribirSlow("Error: Falla al leer listado de materias.");
            }
            free(listaDto);
        }
    }
}

void clsMateriaView::Mostrar(clsMateriaDTO dto)
{
    clsHelp ext;
    char nombre[50];
    dto.GetNombre(nombre);
    ext.Capitalizar(nombre);
    char profesor[50];
    dto.GetProfesor(profesor);
    ext.Capitalizar(profesor);
    cout<<"| "<<setw(4)<<left<<dto.GetID()
        <<" | "<<setw(42)<<left<<nombre
        <<" | "<<setw(42)<<left<<profesor
        <<" |"<<endl;
    cout<<"|______|____________________________________________|____________________________________________|"<<endl;
}

void clsMateriaView::Listar()
{
    clsHelp ext;
    clsMateriaDTO *dto;
    clsMateriaBL bl;
    dto = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*bl.Count());
    ext.LimpiarConsola();
    if(bl.Listar(dto))
    {
        ext._EscribirSlow(" ~~~~~~~~~~~~~~~~~~~~~~~~~ LISTADO DE MATERIAS ~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
        ext._EscribirSlow(" ______ ____________________________________________ ____________________________________________ ");
        ext._EscribirSlow("|      |                                            |                                            |");
        ext._EscribirSlow("|  ID  |            NOMBRE DE MATERIA               |              NOMBRE DE PROFESOR            |");
        ext._EscribirSlow("|______|____________________________________________|____________________________________________|");
        for(int x=0;x < bl.Count(); ++x)
        {
            Mostrar(dto[x]);
        }
    }
    else
    {
        ext.Espacio();
        ext.EscribirSlow("Error: No se ha podido listar las materias.");
    }
    free(dto);
}

void clsMateriaView::BuscarListado()
{
    clsHelp ext;
    ext.LimpiarConsola();
    char loQueIngresaUsuario[50];
    ext.EscribirSlow("Ingrese el nombre de la materia, o presione enter para listado completo: ");
    cin.getline(loQueIngresaUsuario,50);
    ext.Mayusculas(loQueIngresaUsuario);
    ext.LimpiarConsola();
    clsMateriaDTO *dto;
    clsMateriaBL bl;
    dto = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*bl.Count());
    char nombre[50];
    if(bl.Listar(dto))
    {
        ext._EscribirSlow("            ~~~~~~~~~~~~~~~~~~~~~~~~~ LISTADO DE MATERIAS ~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
        ext._EscribirSlow(" ______ ____________________________________________ ____________________________________________ ");
        ext._EscribirSlow("|      |                                            |                                            |");
        ext._EscribirSlow("|  ID  |            NOMBRE DE MATERIA               |              NOMBRE DE PROFESOR            |");
        ext._EscribirSlow("|______|____________________________________________|____________________________________________|");
        for(int x=0;x < bl.Count(); ++x)
        {
            dto[x].GetNombre(nombre);
            if(ext.strSub(nombre,loQueIngresaUsuario) != -1)
            {
                Mostrar(dto[x]);
            }
        }
    }
    else
    {
        ext.Espacio();
        ext.EscribirSlow("Error: No se ha podido listar las materias.");
    }
    free(dto);
}

