#include "shapewidget.h"
#include <QPainter>
#include <QPixmap>
#include <QBitmap>

ShapeWidget::ShapeWidget(QWidget *parent)
    : QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);//这个是widget的标题栏和边框去掉
    setAttribute(Qt::WA_TranslucentBackground);//这个是widget的背景弄透明

    pix = new QPixmap();
    pix->load(":/images/2.png");

    count = 0;
    timer = new QTimer(this);
    timer->start(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(changePicture()));
}

ShapeWidget::~ShapeWidget()
{

}

void ShapeWidget::changePicture()
{
    int X, Y;

    count++;
    if(count >= 30)
    {
        count = 0;
    }
    X = 116 * (count % 5);
    Y = 116 * (count / 5);
    *PixmapTemp = pix->copy(X, Y, 116, 116);

    resize(PixmapTemp->size());
    setMask(QBitmap(PixmapTemp->mask()));
    update();
}


void ShapeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, *PixmapTemp);
}

