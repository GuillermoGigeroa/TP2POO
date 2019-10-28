#include "clsMainView.h"
#include "../EXTRA/Extra.h"

void clsMainView::Menu()
{
	Extra ext;
    char op;
    while(true)
    {
        ext.limpiarConsola();
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
                return;
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
