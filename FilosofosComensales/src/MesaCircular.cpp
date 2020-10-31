#include "MesaCircular.h"
#include <cstddef>

MesaCircular::MesaCircular()
{
    primero = nullptr;
    cantidad = 0;
}

void MesaCircular::AgregarFilosofo(Filosofo f)
{
    Asiento *nuevo;
    nuevo = new Asiento();
    nuevo->ocupante = f;

    if(primero)
    {
        Asiento *actual;
        actual = primero;

        while(actual->izq != primero)
        {
            actual = actual->izq;
        }

        actual->izq = nuevo;
        nuevo->der = actual;
        nuevo->izq = primero;
        primero->der = nuevo;
    }
    else
    {
        primero = nuevo;
        nuevo->izq = primero;
        nuevo->der = primero;
    }
    cantidad++;
}

Filosofo &MesaCircular::TomarFilosofo(unsigned short id)
{
    Asiento *actual;
    actual = primero;

    while(actual->ocupante.getID() != id)
    {
        actual = actual->izq;
    }

    return actual->ocupante;
}

bool MesaCircular::TenedorDisponible(unsigned short id, int direccion)
{
    Asiento *actual;
    actual = primero;

    while(actual->ocupante.getID() != id)
    {
        actual = actual->izq;
    }

    if(direccion == DERECHA)
    {
        if(actual->der->ocupante.TieneTenedorIzquierdo())
        {
            return false;
        }
    }
    if(direccion == IZQUIERDA)
    {
        if(actual->izq->ocupante.TieneTenedorDerecho())
        {
            return false;
        }
    }
    return true;
}

Filosofo MesaCircular::ALaIzquierda(unsigned short id)
{
    Asiento *actual;
    actual = primero;

    while(actual->ocupante.getID() != id)
    {
        actual = actual->izq;
    }

    return actual->izq->ocupante;
}

Filosofo MesaCircular::ALaDerecha(unsigned short id)
{
    Asiento *actual;
    actual = primero;

    while(actual->ocupante.getID() != id)
    {
        actual = actual->izq;
    }

    return actual->der->ocupante;
}
