#include "lista_enteros.h"

lista_enteros::lista_enteros()
{
    inicio=final=actual=0;
    cuantos=0;
}


void lista_enteros::borrar_al_inicio()
{
    if(this->cuantos==1)
    {
        delete this->inicio;
        inicio = final = 0;
        cuantos = 0;

    }
    else
    {
        this->actual = this->inicio->sig;
        this->actual->ant = 0;
        delete this->inicio;
        inicio = actual;
        cuantos--;
    }

}

void lista_enteros::liberar(){
    if(cuantos!=0){
        actual=inicio;
        while(actual!=0){
            inicio=inicio->sig;
            delete actual;
            actual=inicio;
        }
    }
    final=0;
    inicio=0;
    cuantos=0;
}

lista_enteros::lista_enteros(const lista_enteros &l){
    inicio=final=0;
    cuantos=0;
    for(int i=0; i<l.getlength(); i++){
        agregar(l.getvalor(i));
    }

}

const lista_enteros& lista_enteros::operator=(const lista_enteros& l){
    if(&l!=this){
        liberar();
        for(int i=0; i<l.getlength(); i++){
            agregar(l.getvalor(i));
        }
    }
    return *this;
}

void lista_enteros::agregar(int valor){
    nodo_entero* tmp;
    tmp=new nodo_entero(valor);
    if(cuantos==0){
        inicio=final=tmp;
        cuantos++;
    }
    else{
        final->sig=tmp;
        tmp->ant=final;
        final=tmp;
        cuantos++;
    }
}

void lista_enteros::insertar(int valor, int pos){
    nodo_entero* tmp;
    tmp=new nodo_entero(valor);

    if(pos==0)
    {
        tmp->sig=inicio;
        inicio->ant = tmp;
        inicio = tmp;
        cuantos++;

    }
    else
    if(pos<cuantos){
        actual=inicio;
       for(int i=0; i<pos; i++){
            actual=actual->sig;
        }
        tmp->sig=actual;
        tmp->ant=actual->ant;
        actual->ant=tmp;
        tmp->ant->sig=tmp;
        cuantos++;

    }
}

int lista_enteros::getvalor(int pos)const{
    nodo_entero *temp=inicio;
    for(int i=0;i<pos; i++){
        temp=temp->sig;
    }
    return temp->numero;
}

void lista_enteros::setvalor(int pos, int valor){
    actual=inicio;
    for(int i=0;i<pos; i++){
        actual=actual->sig;
    }
    actual->numero=valor;
}

int lista_enteros::getlength()const{
    return cuantos;
}

lista_enteros::~lista_enteros(){
    liberar();
}

void lista_enteros::concatenar(const lista_enteros *L)
{
  for(int i=0; i<L->getlength(); i++)
      this->agregar(L->getvalor(i));

}

int lista_enteros::buscar(int valor)const
{
     nodo_entero *temp = inicio;
     for(int i=0; i<getlength(); i++)
     {
        if(temp->numero == valor)
            return i;
        temp = temp->sig;
     }
     return -1;
}
