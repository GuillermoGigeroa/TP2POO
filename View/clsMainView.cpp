#include "clsMainView.h"
#include "../EXTRA/Extra.h"

void clsMainView::Menu()
{
	Extra ext;
    char op;
    bool continuar = true;
    while(continuar)
    {
        ext.limpiarConsola();
        cout<<" _____________________________________________ "<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"|     M - Materias                            |"<<endl;
        cout<<"|                                             |"<<endl;
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
                continuar = false;
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
