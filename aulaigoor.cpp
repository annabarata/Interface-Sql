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

aulaigoor::~aulaigoor()
{
    delete txt_query;
    delete ui;
}

void aulaigoor::valoresIniciais()
{
 ui->edt_esquema->setText("banco.db");
}
void aulaigoor::validarCampos()
{
if(ui->edt_esquema->text().trimmed().isEmpty())
{
    QMessageBox::critical(this, "Deu Bosta", "Digite o Nome Do Banco De Dados");
    ui->edt_esquema->setFocus();
    return;

}
conectar();
}
