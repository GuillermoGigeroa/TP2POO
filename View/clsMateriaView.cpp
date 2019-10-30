#include "clsMateriaView.h"
#include "../EXTRA/Extra.h"

void clsMateriaView::Menu()
{
    Extra ext;
    char opc[50];
    bool continuar = true;
    while(continuar)
    {
        ext.LimpiarConsola();
        cout<<" _____________________________________________ "<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"|     N - Nueva materia                       |"<<endl;
        cout<<"|     E - Eliminar materia                    |"<<endl;
        cout<<"|     M - Modificar materia                   |"<<endl;
        cout<<"|     L - Listar materias                     |"<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"|     S - Salir                               |"<<endl;
        cout<<"|_____________________________________________|"<<endl;
        cout<<"Ingrese una opcion:";
        cin.getline(opc,50);
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
                    Listar();
                    ext.Pausa();
                }break;
            case 's':
            case 'S':
                {
                    continuar = false;
                }break;
            default:
                {
                    cout<<"Opcion incorrecta."<<endl;
                    ext.Pausa();
                }break;
            }
        }
    }
}

void clsMateriaView::Insertar()
{
    Extra ext;
    ext.LimpiarConsola();
    char nombre[50];
    char profesor[50];
    clsMateriaDTO dto;
    clsMateriaBL bl;
    cout<<"     *****     NUEVA MATERIA     *****"<<endl;
    cout<<"Ingrese el nombre de la materia: ";
    cin.getline(nombre,50);
    cout<<"Ingrese el nombre del profesor: ";
    cin.getline(profesor,50);
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    if(bl.Insertar(dto))
    {
        cout<<"Se ha creado la nueva materia correctamente."<<endl;
    }
    else
    {
        cout<<"Error: No se ha creado la nueva materia correctamente."<<endl;
    }
}

void clsMateriaView::Eliminar()
{
    Extra ext;
    ext.LimpiarConsola();
    char ID_char[50];
    Listar();
    cout<<"     *****     ELIMINAR MATERIA     *****"<<endl;
    cout<<"Ingrese el ID de la materia a eliminar: ";
    cin.getline(ID,50);
    if //todo continuar
    clsMateriaBL bl;
    if(bl.Eliminar(ID))
    {
        cout<<"Se ha eliminado la materia correctamente."<<endl;
    }
    else
    {
        cout<<"Error: No se ha eliminado la materia correctamente."<<endl;
    }
}

void clsMateriaView::Modificar()
{
    Extra ext;
    clsMateriaBL bl;
    clsMateriaDTO dto;
    clsMateriaDTO *listaDto;

    ext.LimpiarConsola();
    Listar();
    cout<<"     *****     MODIFICAR MATERIA     *****"<<endl;
    cout<<"Ingrese el ID de la materia a modificar: ";
    int ID;
    cin>>ID;//TODO Faltan validaciones
    cin.ignore();

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
        free(listaDto);

        if (seEncontro)
        {
            char nombre[50];
            dto.GetNombre(nombre);
            char profesor[50];
            dto.GetProfesor(profesor);
            cout<<"              ID: "<<dto.GetID()<<endl;
            cout<<"  Nombre antiguo: "<<nombre<<endl;
            cout<<"    Nombre nuevo: ";
            cin.getline(nombre,50);
            cout<<"Profesor antiguo: "<<profesor<<endl;
            cout<<"  Profesor nuevo: ";
            cin.getline(profesor,50);
            dto.SetNombre(nombre);
            dto.SetProfesor(profesor);
            if(bl.Modificar(dto))
            {
                cout<<"Se ha modificado la materia correctamente."<<endl;
            }
            else
            {
                cout<<"Error: No se ha modificado la materia."<<endl;
            }
        }
        else
        {
            cout<<"Error: No se ha encontrado el ID ingresado."<<endl;
        }
    }
    else
    {
        cout<<"Error: Falla al leer listado de materias."<<endl;
    }
}

void clsMateriaView::Mostrar(clsMateriaDTO dto)
{
    char nombre[50];
    dto.GetNombre(nombre);
    char profesor[50];
    dto.GetProfesor(profesor);
    cout<<"      ID: "<<dto.GetID()<<endl;
    cout<<"  Nombre: "<<nombre<<endl;
    cout<<"Profesor: "<<profesor<<endl;
    cout<<"__________________________________________________"<<endl<<endl;
}

void clsMateriaView::Listar()
{
    Extra ext;
    clsMateriaDTO *dto;
    clsMateriaBL bl;
    dto = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*bl.Count());
    ext.LimpiarConsola();
    if(bl.Listar(dto))
    {
        cout<<"     *****     LISTADO DE MATERIAS     *****"<<endl;
        cout<<"__________________________________________________"<<endl<<endl;
        for(int x=0;x < bl.Count(); ++x)
        {
            Mostrar(dto[x]);
        }
    }
    else
    {
        cout<<"Error: No se ha podido listar las materias."<<endl;
    }
    free(dto);
}

