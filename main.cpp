#include <iostream>
#include <string.h>
#include "View/clsMainView.h"
#include "HELPER/clsHelp.h"
using namespace std;
int main()
{
    clsMainView view;
    view.Presentacion();
    view.Menu();
    view.Despedida();
	return 0;
}
