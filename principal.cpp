#include "principal.h"
#include "ui_principal.h"

#include <QtDebug>
#include <QFile>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    //Crear lienzo

    lienzo = QPixmap(500,500);

    this->dibujar();

    //Mostra lienzo
    ui->cuadro->setPixmap(lienzo);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{

    //Rellenar lienzo con color blanco

    lienzo.fill(Qt::white);

    //Crear painter

    QPainter painter(&lienzo);

    //Definir variables

    int x=50;
    int y=50;
    int ancho =  100;;
    int alto_1 = ui->inNota1->value();
    int alto_2 = ui->inNota2->value();
    int alto_3 = ui->inNota3->value();

    //Crear pincel

    QPen pincel;
    pincel.setWidth(5); //Ancho del pincel
    pincel.setColor(Qt::red);   //Seleccionar color
    pincel.setJoinStyle(Qt::MiterJoin);

    //Establecer el pincel a pinyat
    painter.setPen(pincel);

    //Dibujar la primera barra
    painter.drawRect(x,y+(400-alto_1),ancho, alto_1);

    //Creamos un nuevo color
    QColor colorBorde2 (78,3,48);
    QColor colorRelleno2(190,120,162);

    //Establecer el color al pincel
    pincel.setColor(colorBorde2);

    //Volver a establecer al objeto painter
    painter.setPen(pincel);

    //Establecer el color de la brocha
    painter.setBrush(colorRelleno2);

    //Establecemos el color de relleno barra 2
    painter.drawRect(x+150,y+(400-alto_2),ancho, alto_2);


    //Crear los colores de la 3ra barra
    QColor colorRelleno3 (253,253,115);
    QColor colorBorde3(174,174,51);

    //Setteamos el color del pincel
    pincel.setColor(colorBorde3);

    //Setteamos el pincel
    painter.setPen(pincel);

    //Rellenar el color
    painter.setBrush(colorRelleno3);
    //Rellenar con el color dado junto con las operaciones necesarias
    painter.drawRect(x+300,y+(400-alto_3), ancho, alto_3);

    ui->cuadro->setPixmap(lienzo);
}


void Principal::on_cmdGraficar_released()
{
    dibujar();


}

void Principal::on_inNota1_valueChanged(int)
{
    dibujar();
}


void Principal::on_actionSalir_triggered()
{
    this->close();
}

void Principal::on_actionGuardar_triggered()
{

        QString nombreArchivo = QFileDialog::getSaveFileName(
                    this,"Guardar imagen",QString(),"Imagenes (*.png)");
        if (!nombreArchivo.isEmpty()){
            if (lienzo.save(nombreArchivo))
                QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
            else
                QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
        }

}
