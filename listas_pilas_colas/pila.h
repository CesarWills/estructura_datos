#ifndef PILA_H
#define PILA_H
#include "lista_enteros.h"

class Pila
{
private:
    lista_enteros elementos;
public:
    Pila();
    void Mete_En_Pila(int valor);
    void Saca_De_Pila();
    int Tope_De_Pila();
    bool Vacia();
    int Cuantos();
    void limpiar() { this->elementos.liberar(); }
};

#endif // PILA_H
