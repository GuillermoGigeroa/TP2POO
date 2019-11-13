#include <iostream>
#include <string.h>
#include "View/clsMainView.h"
#include "HELPER/clsHelp.h"
#include "HELPER/clsMenuAyuda.h"
using namespace std;
int main()
{
    clsHelp ext;
    ext.ConfigurarConsola();
    clsMainView view;
    view.Presentacion();
    view.Menu();
    view.Despedida();
	return 0;
}
