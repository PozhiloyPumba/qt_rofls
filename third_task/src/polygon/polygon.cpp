#include "polygon.hpp"


namespace fig {

void Polygon::setPoints(const std::vector<std::pair<QPointF, QColor>> &points) {
	vertices_.clear();
	edges_.clear();
	std::for_each(points.begin(), points.end(), 
		[this](const auto &p){
			vertices_.push_back(std::make_shared<Vertex>(p.first));
			edges_.push_back(std::make_shared<Edge>(p.second));
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
	std::vector<std::pair<QPoint, QColor>> p;
	std::for_each(vertices_.begin(), vertices_.end(), 
		[&p, w = width, h = height](const auto &v){
			p.push_back({QPoint(int(v->p_.x() * w), int(v->p_.y() * h)), v->end_.lock()->color_});
		}
	);
	size_t sz = p.size();
	QPen pen;
	pen.setWidth(3);
	for(size_t i = 0; i < sz; ++i) {
		pen.setColor(p[i].second);
		painter.setPen(pen);
		painter.drawLine(p[i].first, p[(i + 1) % sz].first);
	}
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