#include "Filosofo.h"
#include "MesaCircular.h"
#include "txtcolor.h"

Filosofo::Filosofo()
{
    //
}

Filosofo::Filosofo(unsigned short id)
{
    this->id = id;
    bocados = 0;
    estado = "pensando";
    tenedorDerecho = false;
    tenedorIzquierdo = false;
    tiempoTotal = 0;
    tiempoActual = 0;
    color = rand()%(15) + 1;
}

unsigned short Filosofo::getID()
{
    return id;
}

unsigned short Filosofo::getBocados()
{
    return bocados;
}

string Filosofo::getEstado()
{
    return estado;
}

void Filosofo::CambiarEstado(string estado)
{
    this->estado = estado;
}

void Filosofo::Pensar(MesaCircular &mesa)
{
    int decision = rand()%(3);

    Hablar();
    if(decision == 0)
    {
        if(tenedorDerecho || tenedorIzquierdo)
            DejarTenedores();
    }
    else
    {
        if(mesa.TenedorDisponible(id, decision))
        {
            TomarTenedor(decision);
        }
        else
        {
            Hablar(decision);
        }
    }
}

void Filosofo::DejarTenedores()
{
    tenedorDerecho = false;
    tenedorIzquierdo = false;
    CambiarEstado("dejando los tenedores en la mesa");
    Hablar();
    CambiarEstado("pensando");
}

void Filosofo::TomarTenedor(int decision)
{
    if(decision == DERECHA)
    {
        tenedorDerecho = true;
        CambiarEstado("tomando el tenedor derecho");
        Hablar();
        if(tenedorIzquierdo)
        {
            Comer();
            Hablar();
        }
    }
    if(decision == IZQUIERDA)
    {
        tenedorIzquierdo = true;
        CambiarEstado("tomando el tenedor izquierdo");
        Hablar();
        if(tenedorDerecho)
        {
            Comer();
            Hablar();
        }
    }
}

void Filosofo::Comer()
{
    CambiarEstado("comiendo");
    tiempoTotal = rand()%(8) + 3; //3 - 10
}

void Filosofo::TerminarDeComer()
{
    CambiarEstado("terminando de comer");
    Hablar();
    tiempoTotal = 0;
    tiempoActual = 0;
    bocados++;
}

void Filosofo::ContarBocados()
{
    TextColor(color);
    string veces = (bocados == 1)? "vez" : "veces";
    cout<<"Filosofo "<<id<<": He comido "<<bocados<<" "<<veces<<endl;
}

bool Filosofo::EstaComiendo()
{
    return estado == "comiendo";
}

void Filosofo::Hablar()
{
    TextColor(color);
    cout<<"Filosofo "<<id<<": Estoy "<<estado<<endl;
}

void Filosofo::Hablar(int decision)
{
    TextColor(color);
    string direccion = (decision == DERECHA)? "derecha" : "izquierda";
    cout<<"Filosofo "<<id<<": El tenedor a mi "<<direccion<<" esta ocupado"<<endl;
}

bool Filosofo::TieneTenedorDerecho()
{
    return tenedorDerecho;
}

bool Filosofo::TieneTenedorIzquierdo()
{
    return tenedorIzquierdo;
}
