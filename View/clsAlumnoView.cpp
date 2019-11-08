#include "clsAlumnoView.h"
#include "../HELPER/clsHelp.h"
#include <iomanip>
#include <string>


void clsAlumnoView::Menu()
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
        ext._EscribirSlow("|     N - Nuevo alumno                         |");
        ext._EscribirSlow("|     E - Eliminar alumno                      |");
        ext._EscribirSlow("|     M - Modificar alumno                     |");
        ext._EscribirSlow("|     L - Buscar alumnos                       |");
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

void clsAlumnoView::Insertar()
{
    clsHelp ext;
    ext.LimpiarConsola();
    char nombre[50];
    char anio_char[50];
    char mes_char[50];
    char dia_char[50];
    clsAlumnoDTO dto;
    clsAlumnoBL bl;

    ext.EscribirSlow(" ~~~~~~~~~~~~~~~ NUEVO ALUMNO ~~~~~~~~~~~~~~~");
    ext.Espacio();
    ext.EscribirSlowParaIngresos("Ingrese el nombre del alumno: ");
    cin.getline(nombre,50);
    ext.Mayusculas(nombre);
    while(!ext.VerificarSiEsTexto(nombre))
    {
        cin.getline(nombre,50);
        ext.Mayusculas(nombre);
    }
    dto.SetNombre(nombre);

    ext.EscribirSlowParaIngresos("Ingrese el anio de nacimiento alumno: ");
    cin.getline(anio_char,50);
    while(!ext.ValidarAnio(anio_char))
    {
        cin.getline(anio_char,50);
    }
    int anio = atoi(anio_char);
    dto.SetAnioNacimiento(anio);

    ext.EscribirSlowParaIngresos("Ingrese el mes de nacimiento alumno: ");
    cin.getline(mes_char,50);
    while(!ext.ValidarMes(mes_char))
    {
        cin.getline(mes_char,50);
    }
    int mes = atoi(mes_char);
    dto.SetMesNacimiento(mes);

    ext.EscribirSlowParaIngresos("Ingrese el dia de nacimiento alumno: ");
    cin.getline(dia_char,50);
    while(!ext.ValidarDia(dia_char))
    {
        cin.getline(dia_char,50);
    }
    int dia = atoi(dia_char);
    dto.SetDiaNacimiento(dia);

    if(bl.Insertar(dto))
    {
        ext.Espacio();
        ext.EscribirSlow("Se ha creado el nuevo alumno correctamente.");
    }
    else
    {
        ext.Espacio();
        ext.EscribirSlow("Error: No se ha creado el nuevo alumno correctamente.");
    }
}

void clsAlumnoView::Eliminar()
{
    clsHelp ext;
    char legajo_char[50];
    legajo_char[0] = 'a';
    while(!ext.VerificarSiEsNumero(legajo_char))
    {
        ext.LimpiarConsola();
        Listar();
        ext.Espacio();
        ext.EscribirSlow(" ~~~~~~~~~~~~~~~ ELIMINAR MATERIA ~~~~~~~~~~~~~~~");
        ext.Espacio();
        ext.EscribirSlowParaIngresos("Ingrese el legajo del alumno a eliminar: ");;
        cin.getline(legajo_char,50);
        if(ext.VerificarSiEsNumero(legajo_char))
        {
            int ID = atoi(legajo_char);
            clsAlumnoBL bl;
            if(bl.Eliminar(ID))
            {
                ext.Espacio();
                ext.EscribirSlow("Se ha eliminado el alumno correctamente.");
            }
            else
            {
                ext.Espacio();
                ext.EscribirSlow("Error: No se ha eliminado el alumno correctamente.");
            }
        }
    }

}

void clsAlumnoView::Modificar()
{
    clsHelp ext;
    clsAlumnoBL bl;
    clsAlumnoDTO dto;
    clsAlumnoDTO *listaDto;

    ext.LimpiarConsola();
    Listar();
    ext.EscribirSlow(" ~~~~~~~~~~~~~~~ MODIFICAR MATERIA ~~~~~~~~~~~~~~~");
    ext.Espacio();
    ext.EscribirSlowParaIngresos("Ingrese el legajo del alumno a modificar: ");
    char legajo_char[50];
    legajo_char[0] = 'a';
    while(!ext.VerificarSiEsNumero(legajo_char))
    {
        cin.getline(legajo_char,50);
        if(ext.VerificarSiEsNumero(legajo_char) && legajo_char[0] != '\0')
        {
            int legajo;
            legajo = atoi(legajo_char);

            listaDto = (clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*bl.Count());
            if(bl.Listar(listaDto))
            {
                bool seEncontro = false;
                for(int x = 0; x < bl.Count(); ++x)
                {
                    if(listaDto[x].GetLegajo() == legajo && !listaDto[x].GetEliminado())
                    {
                        dto.Copy(listaDto[x]);
                        seEncontro = true;
                    }
                }

                if (seEncontro)
                {
                    char nombre[50];
                    char anio_char[50];
                    char mes_char[50];
                    char dia_char[50];
                    dto.GetNombre(nombre);
                    ext.EscribirSlowParaIngresos("             Legajo: ");
                    cout<<dto.GetLegajo()<<endl;
                    ext.EscribirSlowParaIngresos("     Nombre antiguo: ");
                    ext.Capitalizar(nombre);
                    ext.EscribirSlow(nombre);
                    ext.EscribirSlowParaIngresos("       Nombre nuevo: ");
                    cin.getline(nombre,50);
                    while(!ext.VerificarSiEsTexto(nombre))
                    {
                        cin.getline(nombre,50);
                        ext.Mayusculas(nombre);
                    }
                    ext.Mayusculas(nombre);
                    dto.SetNombre(nombre);

                    ext.EscribirSlowParaIngresos("Fecha de nacimiento antigua: ");
                    ext.EscribirFecha(dto.GetDiaNacimiento(),dto.GetMesNacimiento(),dto.GetAnioNacimiento());
                    ext.EscribirSlow("Nueva fecha de nacimiento: ");
                    ext.EscribirSlowParaIngresos("Ingrese el anio de nacimiento alumno: ");
                    cin.getline(anio_char,50);
                    while(!ext.ValidarAnio(anio_char))
                    {
                        cin.getline(anio_char,50);
                    }
                    int anio = atoi(anio_char);
                    dto.SetAnioNacimiento(anio);

                    ext.EscribirSlowParaIngresos("Ingrese el mes de nacimiento alumno: ");
                    cin.getline(mes_char,50);
                    while(!ext.ValidarMes(mes_char))
                    {
                        cin.getline(mes_char,50);
                    }
                    int mes = atoi(mes_char);
                    dto.SetMesNacimiento(mes);

                    ext.EscribirSlowParaIngresos("Ingrese el dia de nacimiento alumno: ");
                    cin.getline(dia_char,50);
                    while(!ext.ValidarDia(dia_char))
                    {
                        cin.getline(dia_char,50);
                    }
                    int dia = atoi(dia_char);
                    dto.SetDiaNacimiento(dia);

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

void clsAlumnoView::Mostrar(clsAlumnoDTO dto)
{
    clsHelp ext;
    char nombre[50];
    dto.GetNombre(nombre);
    ext.Capitalizar(nombre);
    cout<<"| "<<setw(8)<<left<<dto.GetLegajo()
        <<" | "<<setw(42)<<left<<nombre
        <<" | "<<setw(16)<<left<<dto.GetDiaNacimiento()
        <<'\\'<<dto.GetMesNacimiento()
        <<'\\'<<dto.GetAnioNacimiento()
        <<setw(16)<<left<<""
        <<" |"<<endl;
    cout<<"|__________|____________________________________________|____________________________________________|"<<endl;
}

void clsAlumnoView::Listar()
{
    clsHelp ext;
    clsAlumnoDTO *dto;
    clsAlumnoBL bl;
    dto = (clsAlumnoDTO*)malloc(sizeof(clsAlumnoDTO)*bl.Count());
    ext.LimpiarConsola();
    if(bl.Listar(dto))
    {
        ext._EscribirSlow("           ~~~~~~~~~~~~~~~~~~~~~~~~~ LISTADO DE MATERIAS ~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
        ext._EscribirSlow(" __________ ____________________________________________ ____________________________________________ ");
        ext._EscribirSlow("|          |                                            |                                            |");
        ext._EscribirSlow("|  LEGAJO  |             NOMBRE DE ALUMNO               |             FECHA DE NACIMIENTO            |");
        ext._EscribirSlow("|__________|____________________________________________|____________________________________________|");
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

void clsAlumnoView::BuscarListado()
{

    ///TODO Configurar para que funcione con clsAlumnos
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
        ext._EscribirSlow(" __________ ____________________________________________ ____________________________________________ ");
        ext._EscribirSlow("|          |                                            |                                            |");
        ext._EscribirSlow("|  LEGAJO  |            NOMBRE DE MATERIA               |              NOMBRE DE PROFESOR            |");
        ext._EscribirSlow("|__________|____________________________________________|____________________________________________|");
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
