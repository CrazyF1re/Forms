#include "wiundow.h"
#include <iostream>

Window::Window()
{
    codec = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codec->toUnicode("Обработка событий"));
    QVBoxLayout *layout;
    try
    {
    area = new Area( this );
    btn = new QPushButton(codec->toUnicode("Завершить"),this );
    layout = new QVBoxLayout(this);
    }
    catch(std::bad_alloc const&)
    {
        std::cout<<"Memory has not been allocated";
    }
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
}
