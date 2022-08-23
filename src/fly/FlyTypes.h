#pragma once

#include <QPoint>
#include <QTime>
#include <QVector>

namespace flyses {

class FlyMoveTo
{
public:
	static const QPoint NOT_MOVE;
	static const QPoint UP;
	static const QPoint UP_RIGHT;
	static const QPoint RIGHT;
	static const QPoint DOWN_RIGHT;
	static const QPoint DOWN;
	static const QPoint DOWN_LEFT;
	static const QPoint LEFT;
	static const QPoint UP_LEFT;

	static const QVector<QPoint> MOVE_TO;
};

enum class FlyStatus {
	DEAD_FLY,
	LIVE_FLY
	/*, MOVE_FLY*/
};

struct FlyInfo
{
	int speed;		// скорость
	int mileage;	// пробег
	long lifetime;	// возраст
	FlyStatus state; // состояние мухи
};
} // namespace flyses
