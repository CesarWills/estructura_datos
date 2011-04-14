#include "pila.h"

Pila::Pila()
{}
bool Pila::Vacia()
{
    if (this->elementos.getlength()==0)
        return true;
    else
        return false;
}
int Pila::Cuantos()
{
    return this->elementos.getlength();
}

void Pila::Mete_En_Pila(int valor)
{
   if(this->Vacia())
       this->elementos.agregar(valor);
   else
       this->elementos.insertar(valor,0);
}

void Pila::Saca_De_Pila()
{
    if(!this->Vacia())
        this->elementos.borrar_al_inicio();
}
int Pila::Tope_De_Pila()
{   if(!this->Vacia())
        return this->elementos.getvalor(0);
}




