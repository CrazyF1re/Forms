#include "win.h"
#include <iostream>

Win::Win()
{
    try
    {
    codec = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codec->toUnicode("Счетчик"));

    label1 = new QLabel(codec->toUnicode("Cчет по 1"),this);
    label2 = new QLabel(codec->toUnicode("Cчет по 5"),this);
    edit1 = new Counter("0",this);
    edit2 = new Counter("0",this);
    calcbutton=new QPushButton("+1",this);
    exitbutton=new QPushButton(codec->toUnicode("Выход"),this);

    frame1 = new QFrame(this);
    frame2 = new QFrame(this);
    layout1 = new QVBoxLayout(frame1);
    layout2 = new QVBoxLayout(frame2);
    hlayout = new QHBoxLayout(this);
    }
    catch(std::bad_alloc const&)
    {
        std::cout<<"Memory has not been allocated";
    }


    layout1->addWidget(label1);
    layout1->addWidget(edit1);
    layout1->addWidget(calcbutton);
    layout1->addStretch();

    layout2->addWidget(label2);
    layout2->addWidget(edit2);
    layout2->addWidget(exitbutton);
    layout2->addStretch();


    hlayout->addWidget(frame1);
    hlayout->addWidget(frame2);
    hlayout->addLayout(layout1);
    hlayout->addLayout(layout2);


//        QHBoxLayout *layout1 = new QHBoxLayout();
//    layout1->addWidget(label1);
//    layout1->addWidget(label2);
//    QHBoxLayout *layout2 = new QHBoxLayout();
//    layout2->addWidget(edit1);
//    layout2->addWidget(edit2);
//    QHBoxLayout *layout3 = new QHBoxLayout();
//    layout3->addWidget(calcbutton);
//    layout3->addWidget(exitbutton);
//    QVBoxLayout *layout4 = new QVBoxLayout(this);
//    layout4->addLayout(layout1);
//    layout4->addLayout(layout2);
//    layout4->addLayout(layout3);
    connect(calcbutton,SIGNAL(clicked(bool)),edit1,SLOT(add_one()));
    connect(edit1,SIGNAL(tick_signal()),edit2,SLOT(add_one()));
    connect(exitbutton,SIGNAL(clicked(bool)),this,SLOT(close()));

}

void Counter::add_one()
{
    QString str=text();
    int r=str.toInt();
    r++;
    if (r!=0 && r%5 ==0) emit tick_signal();
    str.setNum(r);
    setText(str);

}
