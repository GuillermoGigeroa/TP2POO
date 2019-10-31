#include "clsHelp.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void clsHelp::LimpiarConsola()
{
	system("cls || clear");
}

void clsHelp::Pausa()
{
	cin.get();
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
