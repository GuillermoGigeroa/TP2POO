#include "clsHelp.h"
#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void clsHelp::LimpiarConsola()
{
	system("cls || clear");
}

void clsHelp::_EscribirSlow(char *esteTexto){
    int x = 0;
    while (esteTexto[x] != '\0')
    {
        cout<<esteTexto[x];
        x++;
    }
    Sleep(50);
    cout<<endl;
}

void clsHelp::EscribirSlow(char *esteTexto){
    int x = 0;
    while (esteTexto[x] != '\0')
    {
        if (esteTexto[x] != ' ')
        {
            Sleep(5);
        }
        cout<<esteTexto[x];
        x++;
    }
    cout<<endl;
}

void clsHelp::EscribirSlowParaIngresos(char *esteTexto){
    int x = 0;
    while (esteTexto[x] != '\0')
    {
        if (esteTexto[x] != ' ')
        {
            Sleep(5);
        }
        cout<<esteTexto[x];
        x++;
    }
}

void clsHelp::MostrarLogo(){
    _EscribirSlow("                 @@@@@@@@@@@@@@   @@@@@@@@@@@@@@              ");
    _EscribirSlow("             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          ");
    _EscribirSlow("          @@@@@@@@        @@@@@@@@@@@@@        @@@@@@@@       ");
    _EscribirSlow("        @@@@@@         @@@@@@@     @@@@@@@         @@@@@@     ");
    _EscribirSlow("      @@@@@@            @@@           @@@            @@@@@@   ");
    _EscribirSlow("     @@@@@                                             @@@@@  ");
    _EscribirSlow("    @@@@@           __________________________          @@@@@ ");
    _EscribirSlow("   @@@@@           |                          |          @@@@@");
    _EscribirSlow("   @@@@            | G.I.G.E.R.O.A.B.L.A.C.K. |           @@@@");
    _EscribirSlow("   @@@@            |__________________________|           @@@@");
    _EscribirSlow("   @@@@                                                   @@@@");
    _EscribirSlow("   @@@@             @@@@@@@@@       @@@@@@@@@             @@@@");
    _EscribirSlow("   @@@@             @@@@@@@@@       @@@@@@@@@             @@@@");
    _EscribirSlow("   @@@@@             @@@@               @@@@             @@@@@");
    _EscribirSlow("    @@@@@            @@@@               @@@@            @@@@@ ");
    _EscribirSlow("     @@@@@            @@@@             @@@@            @@@@@  ");
    _EscribirSlow("      @@@@@@           @@@@@         @@@@@           @@@@@@   ");
    _EscribirSlow("        @@@@@@          @@@@@@     @@@@@@          @@@@@@     ");
    _EscribirSlow("          @@@@@@@@        @@@@@@@@@@@@@        @@@@@@@@       ");
    _EscribirSlow("             @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@          ");
}

void clsHelp::Pausa()
{
	cin.get();
}

void clsHelp::Espacio()
{
	cout<<endl;
}

bool clsHelp::VerificarSiEsNumero(char *esto)
{
    int x = 0;
    while(esto[x] != '\0')
    {
        if (!(esto[x] <= '9' && esto[x] >= '0'))
        {
            return false;
        }
        x++;
    }
    return true;
}

bool clsHelp::VerificarSiEsTexto(char *esto)
{
    int x = 0;
    while(esto[x] != '\0')
    {
        if (!((esto[x] >= 'a' && esto[x] <= 'z')||(esto[x] >= 'A' && esto[x] <= 'Z')||esto[x] == ' '))
        {
            return false;
        }
        x++;
    }
    return true;
}

void clsHelp::Mayusculas(char *texto)
{
    char *aux;
    int x = 0, conteo = 0;
    while(texto[x] != '\0')
    {
        x++;
        conteo++;
    }
    conteo++;
    aux = (char*)malloc(sizeof(char)*conteo);
    x = 0;
    while(texto[x] != '\0')
    {
        aux[x] = texto[x];
        if(texto[x] >= 'a' && texto[x] <= 'z')
        {
            aux[x] = texto[x]-32;
        }
        x++;
    }
    aux[x] = '\0';
    strcpy(texto,aux);
    free(aux);
}
