#include "clsMateriaView.h"
#include "../HELPER/clsHelp.h"

void clsMateriaView::Menu()
{
    clsHelp ext;
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
                    cout<<endl<<"Opcion incorrecta."<<endl;
                    ext.Pausa();
                }break;
            }
        }
    }
}

void clsMateriaView::Insertar()
{
    clsHelp ext;
    ext.LimpiarConsola();
    char nombre[50];
    char profesor[50];
    clsMateriaDTO dto;
    clsMateriaBL bl;
    cout<<"     *****     NUEVA MATERIA     *****"<<endl;
    cout<<endl<<"Ingrese el nombre de la materia: ";
    cin.getline(nombre,50);
    cout<<"Ingrese el nombre del profesor: ";
    cin.getline(profesor,50);
    dto.SetNombre(nombre);
    dto.SetProfesor(profesor);
    if(bl.Insertar(dto))
    {
        cout<<endl<<"Se ha creado la nueva materia correctamente."<<endl;
    }
    else
    {
        cout<<endl<<"Error: No se ha creado la nueva materia correctamente."<<endl;
    }
}

void clsMateriaView::Eliminar()
{
    clsHelp ext;
    char ID_char[50];
    ID_char[0] = 'a';
    while(!ext.VerificarSiEsNumero(ID_char))
    {
        ext.LimpiarConsola();
        Listar();
        cout<<endl<<"     *****     ELIMINAR MATERIA     *****"<<endl;
        cout<<endl<<"Ingrese el ID de la materia a eliminar: ";
        cin.getline(ID_char,50);
        if(ext.VerificarSiEsNumero(ID_char)){
            int ID = atoi(ID_char);
            clsMateriaBL bl;
            if(bl.Eliminar(ID))
            {
                cout<<endl<<"Se ha eliminado la materia correctamente."<<endl;
            }
            else
            {
                cout<<endl<<"Error: No se ha eliminado la materia correctamente."<<endl;
            }
        }
    }

}

void clsMateriaView::Modificar()
{
    clsHelp ext;
    clsMateriaBL bl;
    clsMateriaDTO dto;
    clsMateriaDTO *listaDto;

    ext.LimpiarConsola();
    Listar();
    cout<<"     *****     MODIFICAR MATERIA     *****"<<endl;
    cout<<endl<<"Ingrese el ID de la materia a modificar: ";
    char ID_char[50];
    ID_char[0] = 'a';
    while(!ext.VerificarSiEsNumero(ID_char))
    {
        cin.getline(ID_char,50);
        if(ext.VerificarSiEsNumero(ID_char))
        {
            int ID;
            ID = atoi(ID_char);

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
                    cout<<endl<<"              ID: "<<dto.GetID()<<endl;
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
                        cout<<endl<<"Se ha modificado la materia correctamente."<<endl;
                    }
                    else
                    {
                        cout<<endl<<"Error: No se ha modificado la materia."<<endl;
                    }
                }
                else
                {
                    cout<<endl<<"Error: No se ha encontrado el ID ingresado."<<endl;
                }
            }
            else
            {
                cout<<endl<<"Error: Falla al leer listado de materias."<<endl;
            }
        }
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
    clsHelp ext;
    clsMateriaDTO *dto;
    clsMateriaBL bl;
    dto = (clsMateriaDTO*)malloc(sizeof(clsMateriaDTO)*bl.Count());
    ext.LimpiarConsola();
    if(bl.Listar(dto))
    {
        cout<<"     *****     LISTADO DE MATERIAS     *****"<<endl;
        cout<<" ____ ________________________________ __________ "<<endl<<endl;
        cout<<"|    |                                |                                |"<<endl;
        cout<<"| ID | NOMBRE DE MATERIA              | NOMBRE DE PROFESOR         |"<<endl;
        cout<<"|____|________________________________|__________|"<<endl<<endl;
        for(int x=0;x < bl.Count(); ++x)
        {
            Mostrar(dto[x]);
        }
    }
    else
    {
        cout<<endl<<"Error: No se ha podido listar las materias."<<endl;
    }
    free(dto);
}

