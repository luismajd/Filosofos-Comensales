#include <iostream>
#include <windows.h>
#include <time.h>
#include "Filosofo.h"
#include "MesaCircular.h"

using namespace std;

bool fin(MesaCircular mesa)
{
    for(unsigned short i=1; i<=mesa.cantidad; i++)
    {
        if(mesa.TomarFilosofo(i).getBocados() < 6)
            return false;
    }

    return true;
}

int main()
{
    MesaCircular mesa;

    for(unsigned short i=1; i<=5; i++)
    {
        Filosofo comensal(i);
        cout<<"Ha llegado el filosofo "<<comensal.getID()<<" a la mesa"<<endl;
        mesa.AgregarFilosofo(comensal);
    }

    cout<<"\nLos "<<mesa.cantidad<<" filosofos se encuentran en la mesa"<<endl<<endl;

    srand(time(NULL));

    while(!fin(mesa))
    {
        for(unsigned short i=1; i<=mesa.cantidad; i++)
        {
            Filosofo &filosofo = mesa.TomarFilosofo(i);

            if(!filosofo.EstaComiendo())
            {
                filosofo.Pensar(mesa);
            }
            else
            {
                if(filosofo.tiempoTotal == filosofo.tiempoActual)
                {
                    filosofo.TerminarDeComer();
                    filosofo.DejarTenedores();
                    filosofo.ContarBocados();
                }
                filosofo.tiempoActual++;
            }
        }

        cout<<endl;
        //system("Pause");
        //cout<<endl;
        //Sleep(100);
    }

    cout<<"Recuento final:"<<endl<<endl;

    for(unsigned short i=1; i<=mesa.cantidad; i++)
    {
        mesa.TomarFilosofo(i).ContarBocados();
    }

    return 0;
}
