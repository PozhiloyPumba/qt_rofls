#include "renderArea.hpp"
#include <QPainterPath>
#include <QMouseEvent>
#include <QMenu>
#include <algorithm>
#include "menu.hpp"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent)
{
	setBackgroundRole(QPalette::Base);
  	setAutoFillBackground(true);
	connect(parent, SIGNAL(addPolygon(const fig::Polygon &)), this, SLOT(addPolygon(const fig::Polygon &)));
	connect(parent, SIGNAL(deletePolygon(const size_t)), this, SLOT(deletePolygon(const size_t)));
	connect(this, SIGNAL(editPolygon(const fig::Polygon &)), parent, SLOT(editPolygon(const fig::Polygon &)));
}

RenderArea::~RenderArea()
{
}

void RenderArea::showContextMenu(const QPoint &pos, const PolygonIterator &p) {
	QMenu contextMenu(tr("Context menu"), this);

	QAction action1("Edit polygon", this);
	QAction action2("Delete polygon", this);
	connect(&action1, &QAction::triggered, 
		[this, &p](){
			emit editPolygon(*p);
		}
	);
	connect(&action2, &QAction::triggered, 
		[this, &p]() {
			polygons_.erase(p);
			update();
		}
	);

	contextMenu.addAction(&action1);
	contextMenu.addAction(&action2);

	contextMenu.exec(mapToGlobal(pos));
}

void RenderArea::mousePressEvent(QMouseEvent* event) {
	if (event->button()==Qt::RightButton) {
		auto upIt = polygons_.end();
		for(auto curIt = polygons_.begin(), endIt = polygons_.end(); curIt != endIt; ++curIt) {
			if(curIt->contains(event->pos(), width(), height())) {
				if((upIt == polygons_.end()) || (upIt->getLayer() < curIt->getLayer())) {
					upIt = curIt;
				}
			}
		}
		if(upIt != polygons_.end())
			showContextMenu(event->pos(), upIt);
    }
}

void RenderArea::paintEvent(QPaintEvent* event) {
	qDebug() << "In paint event render " << polygons_.size();

    QPainter painter(this);
	std::for_each(polygons_.begin(), polygons_.end(), 
		[&painter, w = width(), h = height()](const auto &p) {
			p.draw(painter, w, h);
		}
	);
}

void RenderArea::addPolygon(const fig::Polygon &p) {
	qDebug() << "added Polygon";
	polygons_.push_back(p);
	update();
}

void RenderArea::deletePolygon(const size_t id) {
	qDebug() << "delete Polygon";
	std::erase_if(polygons_, [id](auto x) { return id == x.id_; });
	update();
}

