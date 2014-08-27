#ifndef AULAIGOOR_H
#define AULAIGOOR_H

#include <QDialog>
#include <QSqlQueryModel>

namespace Ui {
class aulaigoor;
}

class aulaigoor : public QDialog
{
    Q_OBJECT

public slots:
    void validarCampos();
    void desconectar ();
    void executarSql ();
