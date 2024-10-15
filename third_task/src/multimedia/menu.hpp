#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <QWidget>
#include <QScopedPointer>
#include <QPainter>
#include <QSpinBox>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QTableWidget>
#include "polygon/polygon.hpp"

#define N_MAX_COUNT 100

class Menu : public QWidget {
    Q_OBJECT

signals:
	void addPoly(fig::Polygon &p);

public:
    Menu(QWidget *parent = 0);
    virtual ~Menu();

	void paintEvent(QPaintEvent* event) override;
private:
	QScopedPointer<QSpinBox> nSpinBox;
	QScopedPointer<QGridLayout> layout;
	QScopedPointer<QLabel> nSpinBoxName;
	QScopedPointer<QTableWidget> input;
	QScopedPointer<QPushButton> drawPolygon;

	fig::Polygon createPolygon() const;
};

#endif
