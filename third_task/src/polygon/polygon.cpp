#include "polygon.hpp"


namespace fig {

void Polygon::setPoints(std::vector<QPointF> &points) {
	vertices_.clear();
	edges_.clear();
	std::for_each(points.begin(), points.end(), 
		[this](const auto &p){
			vertices_.push_back(std::make_shared<Vertex>(p));
			edges_.push_back(std::make_shared<Edge>());
		}
	);
	// link
	int sz = points.size();
	for(int i = 0; i < sz; ++i) {
		vertices_[i]->begin_ = edges_[(i - 1 + sz) % sz];
		edges_[i]->end_ = vertices_[(i + 1) % sz];
		edges_[i]->begin_ = vertices_[i];
		vertices_[i]->end_ = edges_[i];
	}
}

void Polygon::draw(QPainter &painter, int width, int height) const {
	std::vector<QPoint> p;
	std::for_each(vertices_.begin(), vertices_.end(), 
		[&p, w = width, h = height](const auto &v){
			p.push_back(QPoint(int(v->p_.x() * w), int(v->p_.y() * h)));
		}
	);
	painter.drawPolygon(p.data(), p.size());
}

bool Polygon::contains(const QPoint &cursorCoord, int width, int height) const {
	QList<QPoint> p;
	std::for_each(vertices_.begin(), vertices_.end(), 
		[&p, w = width, h = height](const auto &v){
			p.push_back(QPoint(int(v->p_.x() * w), int(v->p_.y() * h)));
		}
	);
	QPolygon poly(p);
	return poly.containsPoint(cursorCoord, Qt::OddEvenFill);
}
}