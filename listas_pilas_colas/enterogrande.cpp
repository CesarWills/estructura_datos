#include "enterogrande.h"

EnteroGrande::EnteroGrande()
{
    this->setValor("0");
}

EnteroGrande::EnteroGrande(string valor)
{
    this->setValor(valor);
}

void EnteroGrande::setValor(string valor)
{
  this->digitos.liberar();
  for(int i=valor.length()-1;i>=0; i--)
  {
     int digito = valor.at(i) - '0';
     this->digitos.agregar(digito);
  }
}

string EnteroGrande::toString() const
{
  string temporal="";

  for (int i=this->digitos.getlength()-1; i>=0; i--)
  {
      int digito = digitos.getvalor(i);
      char c = '0' + digito;
      temporal = temporal + c;
  }
  return temporal;

}
int EnteroGrande::size() const
{
    return this->digitos.getlength();
}

int EnteroGrande::getDigito(int cual) const
{
    return this->digitos.getvalor(cual-1);
}
void EnteroGrande::setDigito(int valor, int cual)
{
    this->digitos.setvalor(cual-1,valor);

}
void EnteroGrande::agregarDigito(int valor)
{
   this->digitos.agregar(valor);

}


void EnteroGrande::sumar(const EnteroGrande &N1, const EnteroGrande &N2)
{
    int acarreo = 0;
    int suma = 0;
    int valor1=0;
    int valor2=0;
    // poner a cero quien hace la llamada
    string temporal="";
    int maxvalor = max(N1.size(),N2.size());

    temporal.append(maxvalor,'0');
    this->setValor(temporal);
    for(int i=1;i<=maxvalor;i++)
        {
            if (i>N1.size()) valor1=0; else valor1=N1.getDigito(i);
            if (i>N2.size()) valor2=0; else valor2=N2.getDigito(i);
            suma = valor1+valor2 + acarreo;
            if (suma<=9)
            {
                 this->setDigito(suma,i);
                 acarreo=0;
            }
            else
            {
                 this->setDigito(suma-10,i);
                 acarreo=1;
            }
        }
        //Si hubo acarreo al final, agregar el digito
        if (acarreo==1) this->agregarDigito(acarreo);

}


