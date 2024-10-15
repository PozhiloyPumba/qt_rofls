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
	void addPolygon(const fig::Polygon &p);
	void deletePolygon(const size_t id);

public slots:
	void editPolygon(const fig::Polygon &p);

public:
    Menu(QWidget *parent = 0);
    virtual ~Menu();

	void paintEvent(QPaintEvent* event) override;
private:
	QScopedPointer<QSpinBox> nSpinBox;
	QScopedPointer<QLabel> nSpinBoxName;
	QScopedPointer<QSpinBox> layerSpinBox;
	QScopedPointer<QLabel> layerSpinBoxName;
	QScopedPointer<QGridLayout> layout;
	QScopedPointer<QTableWidget> input;
	QScopedPointer<QPushButton> drawPolygon;

	fig::Polygon createPolygon() const;
	std::optional<size_t> deleting;
};

#endif
