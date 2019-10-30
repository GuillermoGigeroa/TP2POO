#include "clsMateriaView.h"
#include "../EXTRA/Extra.h"

void clsMateriaView::Menu()
{
    Extra ext;
    char op;//TODO Faltan validaciones
    bool continuar = true;
    while(continuar)
    {
        ext.limpiarConsola();
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
        cin>>op;
        cin.ignore();
        switch(op)
        {
        case 'n':
        case 'N':
            {
                Insertar();
            }break;
        case 'e':
        case 'E':
            {
                Eliminar();
            }break;
        case 'm':
        case 'M':
            {
                Modificar();
            }break;
        case 'l':
        case 'L':
            {
                Listar();
            }break;
        case 's':
        case 'S':
            {
                continuar = false;
            }break;
        default:
            {
                cout<<"Opcion incorrecta."<<endl;
                ext.pausa();
            }break;
        }
    }
}

void clsMateriaView::Insertar()
{
    Extra ext;
    ext.limpiarConsola();
    char nombre[50];
    char profesor[50];
    clsMateriaDTO dto;
    clsMateriaBL bl;
    cout<<"     *****     NUEVA MATERIA     *****"<<endl;
    cout<<"Ingrese el nombre de la materia: ";
    cin.getline(nombre,50);//TODO Faltan validaciones
    cout<<"Ingrese el nombre del profesor: ";
    cin.getline(profesor,50);//TODO Faltan validaciones
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
    ext.pausa();
}

void clsMateriaView::Eliminar()
{
    Extra ext;
    ext.limpiarConsola();
    int ID;
    cout<<"     *****     ELIMINAR MATERIA     *****"<<endl;
    cout<<"Ingrese el ID de la materia a eliminar: ";
    cin>>ID;//TODO Faltan validaciones
    cin.ignore();
    clsMateriaBL bl;
    if(bl.Eliminar(ID))
    {
        cout<<"Se ha eliminado la materia correctamente."<<endl;
    }
    else
    {
        cout<<"Error: No se ha eliminado la materia correctamente."<<endl;
    }
    ext.pausa();
}

void clsMateriaView::Modificar()
{
    Extra ext;
    clsMateriaBL bl;
    clsMateriaDTO dto;
    clsMateriaDTO *listaDto;

    ext.limpiarConsola();
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
    ext.pausa();
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
    ext.limpiarConsola();
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
    ext.pausa();
}

