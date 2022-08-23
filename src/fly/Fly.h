#pragma once

#include "FlyTypes.h"

#include <functional>
#include <memory>

#include <QList>
#include <QObject>
#include <QThread>
#include <QTime>

namespace flyses {

class Fly
{
public:
	///
	/// \brief Fly
	/// \param torpor врожденная тупость мух
	/// \param sizeBoard размер доски для разсчета времени смерти
	/// \param startPoint стартовая позиция мухи
	///
	Fly(const size_t torpor, const size_t sizeBoard, const QPoint &startPoint);

public:
	///
	/// \brief Проверяем состояние мухи (create + lifeSpan > currentTime)
	/// \return Жива/мертва
	///
	FlyStatus getStatus();
	FlyStatus setStatus(FlyStatus status);

public:
	QPoint getCurrentPoint() const;
	///
	/// \brief updatePoint обновляем текущее положение
	/// \param point новое положение мухи
	///
	void updatePoint(const QPoint &point);

	///
	/// \brief Возвращает вектор перемещения из flyses::FlyMoves
	///
	QPoint choosingPath();

	FlyInfo getFlyInfo();

	static size_t getBOARD_SIZE();

	size_t torpor() const;

public slots:
	void lifeFly();

protected:
	FlyStatus _status{FlyStatus::LIVE_FLY};

	///
	/// \brief Векторы перемещения, определяет вектор пути мухи.
	/// Первый элемент списка - начальное положение мухи
	///
	QList<QPoint> _listMoves;

	///
	/// \brief Текущее положение мухи
	///
	QPoint _currentPoint;

	///
	/// \brief Врожденная тупость мух, определяется время жизни и скорость выбора перемещения
	///
	const size_t _torpor;

	const QTime _createTime;

	///
	/// \brief дата и время смерти
	///
	QTime _deadTime;
};

typedef QSharedPointer<Fly> FlyPtr;
typedef std::unique_ptr<Fly> FlyUnicPtr;

} // namespace flyses
