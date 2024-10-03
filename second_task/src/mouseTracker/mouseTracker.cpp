#include <QMouseEvent>
#include <QCursor>
#include <QDebug>
#include <QPainter>
#include <QPoint>
#include <QPainterPath>

#include "mouseTracker.hpp"
#include "ui_mouseTracker.h"


MouseTracker::MouseTracker(QWidget *parent) :
    QWidget(parent), ui(new Ui::MouseTracker)
{
	ui->setupUi(this);
    setMouseTracking(true);
	setFocusPolicy(Qt::StrongFocus);
	ui->realTimePosName->setAttribute(Qt::WA_TransparentForMouseEvents);
	ui->realTimePos->setAttribute(Qt::WA_TransparentForMouseEvents);
	ui->onClickPosName->setAttribute(Qt::WA_TransparentForMouseEvents);
	ui->onClickPos->setAttribute(Qt::WA_TransparentForMouseEvents);
}

MouseTracker::~MouseTracker()
{
}

void MouseTracker::mouseMoveEvent(QMouseEvent *event)
{
	qDebug() << "mouseMoveEvent";
	curPosCursor = event->pos();
	ui->realTimePos->setText(QString("X: %1, Y: %2").arg(event->pos().x()).arg(event->pos().y()));
	repaint();
}

void MouseTracker::mousePressEvent(QMouseEvent *event) {
	qDebug() << "mousePressEvent";
	if (event->button() == Qt::LeftButton){
		memoryPosCursor = event->pos();
		ui->onClickPos->setText(QString("X: %1, Y: %2").arg(event->pos().x()).arg(event->pos().y()));
		repaint();
	}
}

void MouseTracker::paintEvent(QPaintEvent* event)
{
	qDebug() << "In paint event " << width() << height();
	
    QPainter p(this);
	p.setPen(Qt::blue);
	p.drawLine(memoryPosCursor.x(), memoryPosCursor.y(), memoryPosCursor.x(), 0.02 * height());
	p.drawLine(memoryPosCursor.x(), memoryPosCursor.y(), 0.02 * width(), memoryPosCursor.y());

	p.setPen(Qt::red);
	p.drawLine(curPosCursor.x(), curPosCursor.y(), curPosCursor.x(), 0.02 * height());
	p.drawLine(curPosCursor.x(), curPosCursor.y(), 0.02 * width(), curPosCursor.y());

	p.setPen(Qt::black);
	p.drawLine(0,  0.02 * height(), 0.99 * width(), 0.02 * height());
	QPainterPath path;
	path.moveTo(width(), 0.02 * height());
	path.lineTo(0.98 * width(), 0.01 * height());
	path.lineTo(0.98 * width(), 0.03 * height());
	p.fillPath(path, QBrush(Qt::black));
	path.clear();

  	p.drawLine(0.02 * width(), 0, 0.02 * width(), 0.99 * height());
	path.moveTo(0.02 * width(), height());
	path.lineTo(0.01 * width(), 0.98 * height());
	path.lineTo(0.03 * width(), 0.98 * height());
	p.fillPath(path, QBrush(Qt::black));
}