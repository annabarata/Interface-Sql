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
void aulaigoor::conectar()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName(ui->edt_esquema->text().trimmed());

        if (!db.open())
        {
            QMessageBox::critical(this, "Falha na Conexão",
                                  "Falha na conexão com o Banco [" + ui->edt_esquema->text() + "]\n" + db.lastError().text(),
                                  QMessageBox::Cancel);
            return;
        }

        QSqlQuery qry;
        qry.prepare("SELECT datetime('now')");
        if (!qry.exec()){
            QString erro = qry.lastError().text();
            QMessageBox::critical(this, "Falha na Conexão",
                                  "Falha ao preparar consulta do banco" + erro + "\n",
                                  QMessageBox::Cancel);
        }
 else if (qry.next())
            QMessageBox::information(this, "Banco Tutorial",
                                     "Conexão realizada com sucesso com o Banco ["
                                     + ui->edt_esquema->text() + "]\n[" + qry.value(0).toDateTime().toString() + "]" ,
                                     QMessageBox::Ok);

        habilitarQuery(true);
        ui->txt_sql->setFocus();
}

void aulaigoor::desconectar()
{
    QSqlDatabase db = QSqlDatabase::database();
    db.close();
    this->habilitarQuery(false);
    ui->edt_esquema->setFocus();
}
