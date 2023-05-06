#ifndef WIUNDOW_H
#define WIUNDOW_H

#include <QWidget>
#include "area.h"
#include <QtCore5Compat/QTextCodec>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLayout>

class Window : public QWidget
{
    Q_OBJECT
protected:
 QTextCodec *codec;
 Area * area; // область отображения рисунка
 QPushButton * btn;
public:
 Window();
};


#endif // WIUNDOW_H
