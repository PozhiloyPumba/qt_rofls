#ifndef __MOUSE_TRACKER_HPP__
#define __MOUSE_TRACKER_HPP__

#include <QWidget>
#include <QScopedPointer>
#include <QPaintEvent>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui {
class MouseTracker;
}
QT_END_NAMESPACE

class MouseTracker : public QWidget {
    Q_OBJECT

public:
    MouseTracker(QWidget *parent = 0);
    virtual ~MouseTracker();
	void paintEvent(QPaintEvent* event) override;

protected:
    void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
private:
	QScopedPointer<Ui::MouseTracker> ui;
	QPoint curPosCursor;
	QPoint memoryPosCursor;
};

#endif // WIDGET_H
