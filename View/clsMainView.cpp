#include "clsMainView.h"
#include "../EXTRA/Extra.h"

void clsMainView::Menu()
{
	Extra ext;
    char opc[50];
    bool continuar = true;
    while(continuar)
    {
        ext.LimpiarConsola();
        cout<<" _____________________________________________ "<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"|     M - Materias                            |"<<endl;
        cout<<"|                                             |"<<endl;
        cout<<"|     S - Salir                               |"<<endl;
        cout<<"|_____________________________________________|"<<endl;
        cout<<"Ingrese una opcion:";
        cin.getline(opc,50);
        if(opc[0] != '\0' && opc[1] == '\0')
        {
            switch(opc[0])
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
                    cout<<endl<<"Opcion incorrecta..."<<endl;
                    cin.get();
                    cin.ignore();
                }break;
            }
        }
    }
}
