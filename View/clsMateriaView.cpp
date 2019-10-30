#include "clsMateriaView.h"
#include "../EXTRA/Extra.h"

void clsMateriaView::Menu()
{
    Extra ext;
    char op;
    bool continuar = true;
    while(continuar)
    {
        ext.limpiarConsola();
        cout<<" _____________________________________________ "<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"|     N - Nueva materia                       |"<<endl;
        cout<<"|     E - Eliminar materia                    |"<<endl;
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
                cout<<"Opcion incorrecta..."<<endl;
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
    cin.getline(nombre,50);
    cout<<"Ingrese el nombre del profesor: ";
    cin.getline(profesor,50);
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    bl.Insertar(dto);
}

void clsMateriaView::Eliminar()
{
    Extra ext;
    ext.limpiarConsola();
    clsMateriaBL bl;
    int ID;
    cout<<"     *****     ELIMINAR MATERIA     *****"<<endl;
    cout<<"Ingrese el ID de la materia a eliminar: ";
    cin>>ID;
    cin.ignore();
    bl.Eliminar(ID);
    cout<<"Eliminado correctamente"<<endl;
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
    clsMateriaDTO *dto;
    clsMateriaBL bl;
    Extra ext;
    ext.limpiarConsola();
    cout<<"     *****     LISTADO DE MATERIAS     *****"<<endl;
    dto = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*bl.Count());
    bl.Listar(dto);
    cout<<"__________________________________________________"<<endl<<endl;
    for(int x=0;x < bl.Count(); ++x)
    {
        if(!dto[x].GetEliminado())
        {
            Mostrar(dto[x]);
        }
    }
    free(dto);
    ext.pausa();
}

