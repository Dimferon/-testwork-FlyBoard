#include "flywalker.h"

#include <random>
#include <QGraphicsItem>
#include <QVector2D>

namespace flyses {

FlyWalker::FlyWalker(size_t boardSize,
					 const std::function<bool(const QPoint, QGraphicsItem *)> &callCalculatePosition,
					 QObject *parent)
	: _callImageMoveTo(callCalculatePosition)
{
	auto generateTorpol = 10;
	auto startPoint = QPoint{0, 0};
	_fly = FlyPtr(new Fly(generateTorpol, boardSize, startPoint));
	//TODO добавить поиск начальной позиции
}

FlyWalker::FlyWalker(const FlyPtr &fly,
					 const std::function<bool(const QPoint, QGraphicsItem *)> &callCalculatePosition,
					 QObject *parent)
	: _fly(fly), _callImageMoveTo(callCalculatePosition)
{
	//TODO добавить поиск начальной позиции
}

void FlyWalker::startMove()
{
	if (!_walkerThead && _fly) {
		_walkerThead = QSharedPointer<QThread>(new QThread);
		moveToThread(_walkerThead.get());

		_timerAlive.moveToThread(_walkerThead.get());
		_timerAlive.setInterval(300 * _fly->torpor());
		connect(&_timerAlive, &QTimer::timeout, this, &FlyWalker::aliveFly);

		connect(_walkerThead.get(), SIGNAL(started()), &_timerAlive, SLOT(start()));
		connect(_walkerThead.get(), SIGNAL(finished()), this, SLOT(deadFly()));
		setImage(":/res/fly.jpg");
	} else {
		_timerAlive.start();
	}
}

const FlyInfo FlyWalker::getInfoFly()
{
	return _fly->getFlyInfo();
}

const QPoint FlyWalker::currentPos()
{
	return _fly->getCurrentPoint();
}

QGraphicsPixmapItem *FlyWalker::imageItem()
{
	return _grapItem;
}

void flyses::FlyWalker::choosingPoint()
{
	const auto vectorMove = _fly->choosingPath();
	const auto nextPoint = _fly->getCurrentPoint() + vectorMove;

	if (_callImageMoveTo(nextPoint, _grapItem)) {
		_fly->updatePoint(nextPoint);
	}
}

void FlyWalker::aliveFly()
{
	//TODO: Здесь в отдельном потоке обрабатывается жизнь мухи, проверяется жива ли она
	// вызываем поиск пути по которому дальше полетит муха и проверяем можно ли туда полететь
	if (!_walkerThead) {
		return;
	}

	switch (_fly->getStatus()) {
	case FlyStatus::DEAD_FLY: {
		if (!_walkerThead->isFinished()) {
			_timerAlive.stop();
			_walkerThead->exit();
		}
	} break;
	case FlyStatus::LIVE_FLY: {
		choosingPoint();
	} break;
	}
}

void FlyWalker::pauseMove()
{
	_timerAlive.stop();
}

void FlyWalker::deadFly()
{
	//TODO: меняем картинку у объекта на мертвую муху
	setImage(":/res/flyDead.jpg");

}

} // namespace flyses
