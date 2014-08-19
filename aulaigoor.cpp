#include "aulaigoor.h"
#include "ui_aulaigoor.h"
#include <QMessageBox>
#include <QtGui>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QSqlQueryModel>

aulaigoor::aulaigoor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aulaigoor)
{
    ui->setupUi(this);
    this->setWindowTitle("Tuto SQLITE");
    this->habilitarQuery(false);
    this->valoresIniciais();

    connect(ui->btn_conectar,SIGNAL (clicked()),this, SLOT(validarCampos()));
    connect(ui->btn_desconectar,SIGNAL (clicked()),this, SLOT(desconectar()));
    connect(ui->btn_executar,SIGNAL (clicked()),this, SLOT(executarSQL()));

    ui->edt_esquema->setFocus();
    txt_query = new QSqlQueryModel;

}
