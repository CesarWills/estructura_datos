#include "cola.h"
//Este esn un comentario

Cola::Cola()
{
}
bool Cola::Vacia() const
{
    if (this->elementos.getlength()==0)
        return true;
    else
        return false;

}

void Cola::Mete_en_Cola(int valor)
{
    this->elementos.agregar(valor);
}
void Cola::Saca_de_Cola()
{
    if(!this->Vacia())
       this->elementos.borrar_al_inicio();
}
int Cola::Frente_de_Cola() const
{
    if(!this->Vacia())
            return this->elementos.getvalor(0);
}
