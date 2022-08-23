#include "FlyBoard.h"

#include <math.h>

#include <QGraphicsLineItem>
#include <QPoint>
#include <QPointF>
#include <QRectF>

namespace flyses {

FlyBoardScene::FlyBoardScene(size_t sizeBoard, size_t cellCapacity, size_t countFly, QObject *parent):
	  _boardSize(sizeBoard), _cellCapacity(cellCapacity)
{
	auto n = int(sqrt(sizeBoard)) + 1;
	float widthScene = n * sizeBoard * 10.0;
	this->setSceneRect(QRectF(0, 0, widthScene, widthScene));
}

void FlyBoardScene::addFly(const FlyPtr &fly)
{
	//TODO: доделать работу лямбдафункций
	FlyWalkerPtr walker = FlyWalkerPtr(
		new FlyWalker(fly, [this](const QPoint nextPos, const FlyWalkerPtr &walker) {
			bool isMove = false;
			auto cell = getCell(nextPos);
			if(cell)
			{
				isMove = cell->checkCapacity();
				cell->
				if(isMove){
					cell->addToGroup(image);
				}
			}
			return isMove;
		}));
	_walkers.push_back(std::move(walker));
}

FlyCellBoardPtr FlyBoardScene::getCell(QPoint point)
{
	if(point.y()< _boardImage.size() && point.x() < _boardImage[point.y()].size())
	{
		return _boardImage[point.y()][point.x()];
	}
	return  nullptr;
}

void FlyBoardScene::updateWalkerPos(const FlyWalkerPtr &walker)
{
	auto pos = walker->currentPos();
	_boardImage[pos.y()][pos.x()]->moveFlyWalker(walker);
}

} // namespace flyses
