#include "win.h"

Win::Win(QWidget *parent)
    : QWidget(parent)
{
    codec = QTextCodec::codecForName("UTF-8");
    setWindowTitle(codec->toUnicode("Возведение в квадрат"));//Header of form
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);//creating and add some attributes to fram(рамка)
    inputLabel = new QLabel(codec->toUnicode("Введите число:"),//add lable before the editline to widget
    this);
    inputEdit = new QLineEdit("",this);//add edit line to widget
    StrValidator *v=new StrValidator(inputEdit);//add object validator wich will check string wroted by user
    inputEdit->setValidator(v);//set validator into editline
    outputLabel = new QLabel(codec->toUnicode("Результат:"),//add lable for output header
    this);
    outputEdit = new QLineEdit("",this);// add edit line to output result of calculation
    nextButton = new QPushButton(codec->toUnicode("Следующее"),//add button for next culculation
    this);
    exitButton = new QPushButton(codec->toUnicode("Выход"),//add close button
    this);
    calculate = new QPushButton(codec->toUnicode("Вычислить"),this);
    // компоновка приложения выполняется согласно рисунку 2.
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);//create first Box wich will contain next Widgets...
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();//add stretch to unite few widgets like column
    QVBoxLayout *vLayout2 = new QVBoxLayout();//create second Box with will contain next and close buttons
    vLayout2->addWidget(calculate);
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();//add stretch to unite few widgets like column
    QHBoxLayout *hLayout = new QHBoxLayout(this);//add one more Box
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin();
    connect(exitButton,SIGNAL(clicked(bool)),this,SLOT(close()));//connect exit button with slot close()
    connect(nextButton,SIGNAL(clicked(bool)),this,SLOT(begin()));//connect next button with begin() funcion
    connect(inputEdit,SIGNAL(returnPressed()),this,SLOT(calc()));//connect enter key with calc() function
    connect(calculate,SIGNAL(clicked(bool)),this,SLOT(calc()));
}

void Win::begin()
{
    inputEdit->clear();// clear the input box
    nextButton->setEnabled(false);// set button enabled because nothing gets
    nextButton->setDefault(false);// ???
    inputEdit->setEnabled(true);// set input button("enter key") enable
    outputLabel->setVisible(false);//dont show label with result couse we dont have input data
    outputEdit->setVisible(false);//dont shot outputEdit, same reason
    outputEdit->setEnabled(false);//????
    inputEdit->setFocus();//???
}

void Win::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();
    a=str.toDouble(&Ok);// function which trying convert str to double and if it failed, then change OK to false
    if (Ok)//if conversion is success then squareing entered number
    {
    r=a*a;
    str.setNum(r);// put new value into str
    outputEdit->setText(str);//set new value into outputEdit
    inputEdit->setEnabled(false);//forbid change inputEdit
    outputLabel->setVisible(true);//show outputLabel
    outputEdit->setVisible(true);//show outputEdit with result
    nextButton->setDefault(true);
    nextButton->setEnabled(true);
    nextButton->setFocus();
    }
    else
    if (!str.isEmpty())
    {
    QMessageBox msgBox(QMessageBox::Information,// shows msg about wrong wrote number
    codec->toUnicode("Возведение в квадрат."),
    codec->toUnicode("Введено неверное значение."),
    QMessageBox::Ok);
    msgBox.exec();
    inputEdit->setText("");//clear inputEdit
    }
    }
