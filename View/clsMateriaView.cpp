#include "clsMateriaView.h"

void clsMateriaView::Menu()
{
    char op;
    bool salir = false;
    while(!salir)
    {
        system("cls");
        cout<<" _____________________________________________ "<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"|     N - Nueva materia                       |"<<endl;
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
        case 's':
        case 'S':
            {
                salir = true;
            }break;
        default:
            {
                cout<<"Opcion incorrecta..."<<endl;
                cin.get();
                cin.ignore();
            }break;
        }
    }
}

void clsMateriaView::Insertar()
{
    system("cls");
    char nombre[50];
    char profesor[50];
    clsMateriaDTO dto;
    clsMateriaDAO dao;
    cout<<"-----NUEVA MATERIA-----"<<endl;
    cout<<"Ingrese el nombre de la materia: ";
    cin.getline(nombre,50);
    cout<<"Ingrese el nombre del profesor: ";
    cin.getline(profesor,50);
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    dao.Insertar(dto);
}

void clsMateriaView::Listar()
{
    system("cls");
    cout<<"-----LISTADO DE MATERIAS-----"<<endl;
}

