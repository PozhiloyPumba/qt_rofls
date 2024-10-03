#include <QMouseEvent>
#include <QCursor>

#include "multimedia.hpp"
#include "ui_multimedia.h"


Multimedia::Multimedia(QWidget *parent) :
    QWidget(parent), ui(new Ui::Multimedia)
{
	ui->setupUi(this);
    setMouseTracking(true);
}

Multimedia::~Multimedia()
{
}

void Multimedia::mouseMoveEvent(QMouseEvent *event)
{
    if(event->pos().x() > geometry().width() / 2)
    {
        setCursor(QCursor(Qt::OpenHandCursor));
    }
    else
    {
        setCursor(QCursor(Qt::WaitCursor));
    }

    QWidget::mouseMoveEvent(event);
}