#ifndef COLA_H
#define COLA_H
#include "lista_enteros.h"
class Cola
{
private:
    lista_enteros elementos;

public:
    Cola();
    void Mete_en_Cola(int valor);
    void Saca_de_Cola();
    int Frente_de_Cola() const;
    bool Vacia() const;
    int Cuantos();
    void limpiar() { this->elementos.liberar();}
};

#endif // COLA_H
