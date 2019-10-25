#include "clsMainView.h"

void clsMainView::Menu()
{
    char op;
    bool salir = false;
    while(!salir)
    {
        system("cls");
        cout<<" _____________________________________________ "<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"|     M - Materias                            |"<<endl;
        cout<<"|     S - Salir                               |"<<endl;
        cout<<"|_____________________________________________|"<<endl;
        cout<<"Ingrese una opcion:";
        cin>>op;
        cin.ignore();
        switch(op)
        {
        case 'm':
        case 'M':
            {
                clsMateriaView matView;
                matView.Menu();
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
