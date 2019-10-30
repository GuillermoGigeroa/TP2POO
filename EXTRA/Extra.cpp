#include "Extra.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void Extra::LimpiarConsola()
{
	system("cls || clear");
}

void Extra::Pausa()
{
	cin.get();
}

bool Extra::VerificarSiEsNumero(char *esto)
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
