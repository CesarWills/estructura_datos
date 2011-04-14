#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    this->TiempoServicio =0;
    this->NumeroCliente = 0;
    this->SimulacionenProceso = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar_simulacion()));

}

void MainWindow::actualizar_simulacion()
{
   // Simular que llegan entre 1 a 5 clientes
    int clientes = qrand() % 5 +1;
    for (int i=0; i<clientes;i++)
    {
        QString temp;
        temp.setNum(this->NumeroCliente);
        ui->txtResultado->appendPlainText("llego Cliente :" + temp);
        C.Mete_en_Cola(this->NumeroCliente);
        this->NumeroCliente ++ ;
    }
    // Cada 9 segundos en promedio se sirve un cliente
    this->TiempoServicio = this->TiempoServicio + 3; //sumar 3 segundos
    if (this->TiempoServicio==9)
    {   //int cual = C.Frente_de_Cola();
        int cuantos = qrand() % 3+1;
        for (int i=0;i<cuantos;i++)
        {
            this->C.Saca_de_Cola();
        }
        QString temp;
        temp.setNum(cuantos);
        ui->txtResultado->appendPlainText("Se atendieron:" + temp );
        this->TiempoServicio =0; //resetear el tiempo de servicio
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbSumar_clicked()
{
    //Aca deberia venir una validacion que los inputs sean solo numeros
    // PRE-Condicion ... los lineedits deben tener solo digitos y no otros
    // caracteres
    // if (this.validar(ui->leNum1->text()) && this.validar(ui->leNum2->text()))

    n1.setValor(ui->leNum1->text().toStdString());
    n2.setValor(ui->leNum2->text().toStdString());
    nResult.sumar(n1,n2);
    ui->txtResultado->appendPlainText(
      ui->leNum1->text() + "+" +
      ui->leNum2->text() + " = "  + nResult.toString().c_str());
}

void MainWindow::on_pbSalir_clicked()
{
    this->close();
}

void MainWindow::on_pbSet_clicked()
{
    n1.setValor(ui->leNum1->text().toStdString());

}



void MainWindow::on_pbSet_2_clicked()
{
    int valor;
    int pos ;
    valor = ui->leValor->text().toInt();
    pos = ui->lePos->text().toInt();
    n1.setDigito(valor,pos);
    QString temp(n1.toString().c_str());
    ui->leNum1->setText(temp);

}






void MainWindow::on_pbValidar_clicked()
{
    P.limpiar();
    QString cadena = ui->leExpresion->text();
    for (int i=0; i<cadena.length();i++)
    {
       char caracter = cadena.at(i).toAscii();
       if (caracter=='(')
           P.Mete_En_Pila(caracter);
       else
           if(caracter==')')
               if (!P.Vacia())
                   P.Saca_De_Pila();
               else
                   QMessageBox::about(this,"Error","Mas de");
    }
    if(!P.Vacia())
        QMessageBox::about(this,"Error","Mas IZq");



}

void MainWindow::on_pbIniciar_clicked()
{
    if (!this->SimulacionenProceso)
    {
        timer->start(3000); // Cada 3 segundos
        C.limpiar();
        this->SimulacionenProceso = true;
        this->TiempoServicio =0;
        this->NumeroCliente =0;
    }
}

void MainWindow::on_pbDetener_clicked()
{
    if(this->SimulacionenProceso)
    {
      timer->stop();
      this->SimulacionenProceso = false;

    }
}

void MainWindow::on_pbRestar_clicked()
{

}
