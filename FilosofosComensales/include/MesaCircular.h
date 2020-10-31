#ifndef MESACIRCULAR_H
#define MESACIRCULAR_H
#include "Asiento.h"

class MesaCircular
{
    private:
        Asiento *primero;

    public:
        unsigned short cantidad;
        MesaCircular();
        void AgregarFilosofo(Filosofo);
        Filosofo &TomarFilosofo(unsigned short);
        bool TenedorDisponible(unsigned short, int);
        Filosofo ALaIzquierda(unsigned short);
        Filosofo ALaDerecha(unsigned short);
};

#endif // MESACIRCULAR_H
