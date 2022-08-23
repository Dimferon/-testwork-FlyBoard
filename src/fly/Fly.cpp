#include "Fly.h"

namespace flyses {

Fly::Fly(const size_t torpor, const size_t sizeBoard, const QPoint &startPoint)
	: _torpor(torpor), _createTime(QTime::currentTime())
{
	_deadTime = QTime::currentTime().addSecs(torpor * sizeBoard);
}

FlyStatus Fly::getStatus()
{
	if (_status == FlyStatus::LIVE_FLY && _deadTime < QTime::currentTime()) {
		_status = FlyStatus::DEAD_FLY;
	}
	return _status;
}

QPoint Fly::getCurrentPoint() const
{
	return _currentPoint;
}

void Fly::updatePoint(const QPoint &point)
{
	_listMoves.push_back(point - _currentPoint);
	_currentPoint = point;
}

FlyInfo Fly::getFlyInfo()
{
	return {(int) _torpor, _listMoves.size(), _createTime.secsTo(QTime::currentTime()), _status};
}

size_t Fly::torpor() const
{
	return _torpor;
}

} // namespace flyses
