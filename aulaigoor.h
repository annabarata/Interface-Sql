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


public:
    explicit aulaigoor(QWidget *parent = 0);
    ~aulaigoor();

private:
    Ui::aulaigoor *ui;
    QSqlQueryModel *txt_query;
    void habilitarQuery (bool ativo);
    void valoresIniciais();
    void conectar();



};

#endif // AULAIGOOR_H
