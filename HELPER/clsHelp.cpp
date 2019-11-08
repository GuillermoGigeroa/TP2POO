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

void clsHelp::_EscribirSlow(const char *esteTexto){
    int x = 0;
    while (esteTexto[x] != '\0')
    {
        cout<<esteTexto[x];
        x++;
    }
    Sleep(50);
    cout<<endl;
}

void clsHelp::EscribirSlow(const char *esteTexto){
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

void clsHelp::EscribirSlowParaIngresos(const char *esteTexto){
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

void clsHelp::Capitalizar(char *texto)
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
    bool primeraLetra = true;
    while(texto[x] != '\0')
    {
        aux[x] = texto[x];
        if (texto[x-1] == ' ' || (texto[x-1] == 'I' && texto[x] == 'I'))
            primeraLetra = true;
        if (primeraLetra)
        {
            primeraLetra = false;
            if(texto[x] >= 'a' && texto[x] <= 'z')
            {
                aux[x] = texto[x]-32;
            }
        }
        else
        {
            if(texto[x] >= 'A' && texto[x] <= 'Z')
            {
                aux[x] = texto[x]+32;
            }
        }
        x++;
    }
    aux[x] = '\0';
    strcpy(texto,aux);
    free(aux);
}

int clsHelp::strSub(char *cad, char *subCad)
{
    int i = 0, i2, iaux;
    while (cad[i] != '\0')
    {
        i2=0;
        iaux = i;
        while(subCad[i2] == cad[iaux] && subCad[i2] != '\0')
        {
            i2++;
            iaux++;
        }
        if (subCad[i2]=='\0')
        {
            return i;
        }
        i++;
    }
    return -1;
}

void clsHelp::ConfigurarConsola()
{
    system("color 0a");
    system("mode con cols=130 lines=40");
    LimpiarConsola();
}

bool clsHelp::ValidarAnio(char *esteNumero)
{
    if(!VerificarSiEsNumero(esteNumero)) return false;
    int numero = atoi(esteNumero);
    if(numero < 1900) return false;
    if(numero > 2019) return false;
    return true;
}

bool clsHelp::ValidarMes(char *esteNumero)
{
    if(!VerificarSiEsNumero(esteNumero))return false;
    int numero = atoi(esteNumero);
    if(numero < 1) return false;
    if(numero > 12) return false;
    return true;
}

bool clsHelp::ValidarDia(char *esteNumero)
{
    if(!VerificarSiEsNumero(esteNumero))return false;
    int numero = atoi(esteNumero);
    if(numero < 1) return false;
    if(numero > 31) return false;
    return true;
}

void clsHelp::EscribirFecha(int dia, int mes, int anio)
{
    if(dia<10)
    {
        cout<<'0'<<dia;
    }
    else
    {
        cout<<dia;
    }
    cout<<'\\';
    if(mes<10)
    {
        cout<<'0'<<mes;
    }
    else
    {
        cout<<mes;
    }
    cout<<'\\';
    cout<<anio;
}
