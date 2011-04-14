#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include "enterogrande.h"
#include "pila.h"
#include "cola.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    EnteroGrande n1,n2,nResult;
    Pila P;
    Cola C;
    QTimer *timer;
    int TiempoServicio;
    int NumeroCliente;
    bool SimulacionenProceso;
    int NumeroAtentidos;


private slots:
    void on_pbRestar_clicked();
    void on_pbDetener_clicked();
    void on_pbIniciar_clicked();
    void on_pbValidar_clicked();
    void on_pbSet_2_clicked();
    void on_pbSet_clicked();
    void on_pbSalir_clicked();
    void on_pbSumar_clicked();
    void actualizar_simulacion();
};

#endif // MAINWINDOW_H
