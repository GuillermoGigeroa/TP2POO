#include "clsMxA_View.h"
#include "clsMateriaView.h"
#include "clsAlumnoView.h"
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
        ext._EscribirSlow("|     E - Eliminar alumno de una materia       |");
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
                    EliminarAlumnoDeMateria();
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
    while(!ext.VerificarSiEsNumero(ID_Materia_char))
    {
        cin.getline(ID_Materia_char,50);
    }
    int ID_Materia = atoi(ID_Materia_char);
    dto.SetID_Materia(ID_Materia);
    ext.LimpiarConsola();

    ext.EscribirSlow(" ~~~~~~~~~~~~~~~ NUEVO REGISTRO ~~~~~~~~~~~~~~~");
    clsAlumnoView listaAlumnos;
    listaAlumnos.Listar();
    ext.EscribirSlowParaIngresos("Ingrese el legajo del alumno: ");
    cin.getline(legajo_char,50);
    while(!ext.VerificarSiEsNumero(legajo_char))
    {
        cin.getline(legajo_char,50);
    }
    int legajo = atoi(legajo_char);
    dto.SetLegajo(legajo);
    if(!bl.VerificarSiYaExiste(dto))
    {
        if(bl.Insertar(dto))
        {
            ext.Espacio();
            ext.EscribirSlow("Se ha creado la nueva asignacion correctamente.");
        }
        else
        {
            ext.Espacio();
            ext.EscribirSlow("Error: No se ha creado la nueva asignacion correctamente.");
        }
    }
    else
    {
        ext.EscribirSlow("Error: Alumno ya fue registrado en esa materia.");
    }
}

void clsMxA_View::EliminarAlumnoDeMateria()
{
    clsHelp ext;
    clsAlumnoView aluView;
    char legajo_char[50];
    char ID_char[50];
    ID_char[0] = 'a';
    legajo_char[0] = 'a';
    while(!ext.VerificarSiEsNumero(ID_char) && !ext.VerificarSiEsNumero(legajo_char))
    {
        clsMxA_BL bl;
        ext.LimpiarConsola();
        ext.Espacio();
        ext.EscribirSlow(" ~~~~~~~~~~~~~~~ ELIMINAR ALUMNO DE MATERIA ~~~~~~~~~~~~~~~");
        ext.Espacio();
        aluView.Listar();
        ext.Espacio();
        ext.EscribirSlowParaIngresos("Ingrese el legajo del alumno: ");
        cin.getline(legajo_char,50);
        while(!ext.VerificarSiEsNumero(legajo_char))
        {
            cin.getline(legajo_char,50);
        }
        int legajo = atoi(legajo_char);
        ext.LimpiarConsola();
        ext.EscribirSlow(" ~~~~~~~~~~~~~~~ ELIMINAR ALUMNO DE MATERIA ~~~~~~~~~~~~~~~");
        ext.Espacio();
        MostrarListadoAXM(legajo);
        ext.Espacio();
        ext.EscribirSlowParaIngresos("Ingrese el ID de la materia: ");
        cin.getline(ID_char,50);
        while(!ext.VerificarSiEsNumero(ID_char))
        {
            cin.getline(ID_char,50);
        }
        int ID = atoi(ID_char);

        if(bl.EliminarAlumnoDeMateria(ID,legajo))
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

void clsMxA_View::MostrarMXA(clsMxA_DTO dto)
{
    if(!dto.GetEliminado())
    {
        clsHelp ext;
        clsMateriaBL blMat;
        clsAlumnoBL blAl;
        char nombreMateria[50];
        blMat.BuscarNombreMateria(dto.GetID_Materia(),nombreMateria);
        ext.Capitalizar(nombreMateria);
        char nombreAlumno[50];
        blAl.BuscarNombreAlumno(dto.GetLegajo(),nombreAlumno);
        ext.Capitalizar(nombreAlumno);
        cout<<"| "<<setw(42)<<left<<nombreMateria
            <<" | "<<setw(42)<<left<<nombreAlumno
            <<" |"<<endl;
        cout<<"|____________________________________________|____________________________________________|"<<endl;
    }
}

void clsMxA_View::MostrarAXM(clsMxA_DTO dto, bool mostrarIDMateria)
{
    if(!dto.GetEliminado())
    {
        clsHelp ext;
        clsMateriaBL blMat;
        clsAlumnoBL blAl;
        char nombreMateria[50];
        char nombreAlumno[50];
        if(!mostrarIDMateria)
        {
            blMat.BuscarNombreMateria(dto.GetID_Materia(),nombreMateria);
            ext.Capitalizar(nombreMateria);
            blAl.BuscarNombreAlumno(dto.GetLegajo(),nombreAlumno);
            ext.Capitalizar(nombreAlumno);
            cout<<"| "<<setw(42)<<left<<nombreAlumno
                <<" | "<<setw(42)<<left<<nombreMateria
                <<" |"<<endl;
            cout<<"|____________________________________________|____________________________________________|"<<endl;
        }
        else
        {
            blMat.BuscarNombreMateria(dto.GetID_Materia(),nombreMateria);
            ext.Capitalizar(nombreMateria);
            blAl.BuscarNombreAlumno(dto.GetLegajo(),nombreAlumno);
            ext.Capitalizar(nombreAlumno);
            cout<<"| "<<setw(42)<<left<<nombreAlumno
                <<" | "<<setw(42)<<left<<nombreMateria
                <<" | "<<setw(4)<<dto.GetID_Materia()
                <<" |"<<endl;
            cout<<"|____________________________________________|____________________________________________|______|"<<endl;
        }
    }
}

void clsMxA_View::BuscarListadoMXA()
{
    clsHelp ext;
    ext.LimpiarConsola();
    char ID_Materia_char[50];
    clsMateriaView viewMaterias;
    viewMaterias.Listar();
    ext.Espacio();
    ext.EscribirSlow("Ingrese el ID de la materia:");
    cin.getline(ID_Materia_char,50);
    while(!ext.VerificarSiEsNumero(ID_Materia_char))
    {
        cin.getline(ID_Materia_char,50);
    }
    int ID = atoi(ID_Materia_char);
    ext.LimpiarConsola();
    clsMxA_DTO *dto;
    clsMxA_BL bl;
    dto = (clsMxA_DTO*)malloc(sizeof(clsMxA_DTO)*bl.Count());
    if(bl.Listar(dto))
    {
        ext._EscribirSlow("            ~~~~~~~~~~~~~~~~~~~~~~~~~ LISTADO SEGUN MATERIA ~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
        ext._EscribirSlow(" ____________________________________________ ____________________________________________ ");
        ext._EscribirSlow("|                                            |                                            |");
        ext._EscribirSlow("|             NOMBRE DE MATERIA              |              NOMBRE DE ALUMNO              |");
        ext._EscribirSlow("|____________________________________________|____________________________________________|");
        for(int x=0;x < bl.Count(); ++x)
        {
            if(dto[x].GetID_Materia() == ID && !dto[x].GetEliminado())
            {
                MostrarMXA(dto[x]);
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

void clsMxA_View::MostrarListadoAXM(int legajo)
{
    clsHelp ext;
    clsMxA_DTO *dto;
    clsMxA_BL bl;
    dto = (clsMxA_DTO*)malloc(sizeof(clsMxA_DTO)*bl.Count());
    if(bl.Listar(dto))
    {
        ext._EscribirSlow("            ~~~~~~~~~~~~~~~ LISTADO DE INSCRIPCIONES DEL ALUMNO ~~~~~~~~~~~~~~~ ");
        ext._EscribirSlow(" ____________________________________________ ____________________________________________ ______");
        ext._EscribirSlow("|                                            |                                            |      |");
        ext._EscribirSlow("|             NOMBRE DE ALUMNO               |              NOMBRE DE MATERIA             |  ID  |");
        ext._EscribirSlow("|____________________________________________|____________________________________________|______|");
        for(int x=0;x < bl.Count(); ++x)
        {
            if(dto[x].GetLegajo() == legajo && !dto[x].GetEliminado())
            {
                MostrarAXM(dto[x],true);
            }
        }
        ext.Espacio();
    }
    else
    {
        ext.Espacio();
        ext.EscribirSlow("Error: No se ha podido listar las materias.");
    }
    free(dto);
}

void clsMxA_View::BuscarListadoAXM()
{
    clsHelp ext;
    ext.LimpiarConsola();
    char legajo_char[50];
    clsAlumnoView viewAlumnos;
    viewAlumnos.Listar();
    ext.Espacio();
    ext.EscribirSlow("Ingrese el legajo del alumno:");
    cin.getline(legajo_char,50);
    while(!ext.VerificarSiEsNumero(legajo_char))
    {
        cin.getline(legajo_char,50);
    }
    int legajo = atoi(legajo_char);
    ext.LimpiarConsola();
    clsMxA_DTO *dto;
    clsMxA_BL bl;
    dto = (clsMxA_DTO*)malloc(sizeof(clsMxA_DTO)*bl.Count());
    if(bl.Listar(dto))
    {
        ext._EscribirSlow("            ~~~~~~~~~~~~~~~~~~~~~~~~~ LISTADO SEGUN MATERIA ~~~~~~~~~~~~~~~~~~~~~~~~~~ ");
        ext._EscribirSlow(" ____________________________________________ ____________________________________________ ");
        ext._EscribirSlow("|                                            |                                            |");
        ext._EscribirSlow("|             NOMBRE DE ALUMNO               |              NOMBRE DE MATERIA             |");
        ext._EscribirSlow("|____________________________________________|____________________________________________|");
        for(int x=0;x < bl.Count(); ++x)
        {
            if(dto[x].GetLegajo() == legajo)
            {
                MostrarAXM(dto[x], false);
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
