#ifndef __POLYGON_HPP__
#define __POLYGON_HPP__

#include <memory>
#include <vector>
#include <QPoint>


namespace fig {

class Polygon {
private:
	struct Edge {
		std::weak_ptr<QPoint> begin_;
		std::weak_ptr<QPoint> end_;
		int value_;
	};
	struct Vertex {
		std::weak_ptr<Edge> begin_;
		std::weak_ptr<Edge> end_;
		int value_;
	};

	std::vector<std::shared_ptr<Edge>> edges_;
	std::vector<std::shared_ptr<QPoint>> vertices_;

public:
	Polygon(){}

};

}

#endif