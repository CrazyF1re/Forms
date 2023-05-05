#ifndef WIN_H
#define WIN_H

#include <QtCore5Compat/QTextCodec>
#include <QFrame>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QValidator>
#include <QWidget>
#include <QPushButton>

class Counter:public QLineEdit
{
    Q_OBJECT
public:
    Counter( const QString & contents,QWidget *parent=0):QLineEdit(contents,parent){}
signals:
    void tick_signal();
public slots:
    void add_one();
};


class Win : public QWidget
{
    Q_OBJECT
public:
    Win(QWidget *parent = 0);
protected:
    QFrame *frame1,*frame2;
    QTextCodec *codec;
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;

signals:

};

#endif // WIN_H
