#ifndef ASIENTO_H
#define ASIENTO_H
#include "Filosofo.h"

class Asiento
{
    private:
        Asiento *der;
        Asiento *izq;
        Filosofo ocupante;

    public:
        Asiento();
        friend class MesaCircular;
};

#endif // ASIENTO_H
