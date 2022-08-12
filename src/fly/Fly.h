#pragma once

#include "FlyTypes.h"

#include <QList>
#include <QTime>
#include <QObject>
#include <QThread>

namespace flyses {

	class Fly: public QObject
	{

	public:
		/// <summary>
		/// Проверяем состояние мухи (create + lifeSpan > currentTime)
		/// </summary>
		/// <returns>Жива/мертва</returns>
		StateFly checkState();

	public:
		Point2i getCurrentPoint() const;
		Point2i moveTo();

		FlyStatistic getStatisticFly();

	protected:
		/// <summary>
		/// Векторы перемещения, определяет вектор пути мухи.
		/// Первый элемент списка - начальное положение мухи
		/// </summary>
		QList<Point2i> _listMoves;

		/// <summary>
		/// Текущее положение мухи
		/// </summary>
		Point2i _currentPoint;

		/// <summary>
		/// Врожденная тупость мух, определяется время жизни и скорость выбора перемещения
		/// </summary>
		const size_t _torpor;

		/// <summary>
		/// Время создания
		/// </summary>
		QTime _createTime;

		/// <summary>
		/// Промежуток жизни = _torpor x size
		/// </summary>
		QTime _lifeTimeSpan;
	};

}
