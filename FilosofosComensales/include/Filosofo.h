#ifndef FILOSOFO_H
#define FILOSOFO_H
#include <iostream>

#define DERECHA 1
#define IZQUIERDA 2

using namespace std;

class MesaCircular;

class Filosofo
{
    private:
        unsigned short id;
        unsigned short bocados;
        string estado;
        bool tenedorDerecho;
        bool tenedorIzquierdo;
        int color;

    public:
        int tiempoTotal;
        int tiempoActual;

        Filosofo();
        Filosofo(unsigned short);
        unsigned short getID();
        unsigned short getBocados();
        string getEstado();
        void CambiarEstado(string);
        void Pensar(MesaCircular &);
        void TomarTenedor(int);
        void DejarTenedores();
        void Comer();
        void TerminarDeComer();
        void ContarBocados();
        bool EstaComiendo();
        void Hablar();
        void Hablar(int);
        bool TieneTenedorDerecho();
        bool TieneTenedorIzquierdo();
};

#endif // FILOSOFO_H
