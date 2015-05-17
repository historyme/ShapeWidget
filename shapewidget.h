#ifndef SHAPEWIDGET_H
#define SHAPEWIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPixmap>

class ShapeWidget : public QWidget
{
    Q_OBJECT

public:
    ShapeWidget(QWidget *parent = 0);
    ~ShapeWidget();
protected:
    void paintEvent(QPaintEvent *event);

private:
    QPoint dragPosition;
    QTimer *timer;
    QPixmap *pix;
    QPixmap *PixmapTemp;
    int count;
private slots:
    void changePicture();
};

#endif // SHAPEWIDGET_H
