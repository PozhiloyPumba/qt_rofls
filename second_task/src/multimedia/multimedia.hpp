#ifndef __MULTIMEDIA_HPP__
#define __MULTIMEDIA_HPP__

#include <QWidget>
#include <QScopedPointer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Multimedia;
}
QT_END_NAMESPACE

class Multimedia : public QWidget {
    Q_OBJECT

public:
    Multimedia(QWidget *parent = 0);
    virtual ~Multimedia();

protected:
    void mouseMoveEvent(QMouseEvent *event);
private:
	QScopedPointer<Ui::Multimedia> ui;
};

#endif // WIDGET_H
