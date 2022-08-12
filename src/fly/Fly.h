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
		/// ��������� ��������� ���� (create + lifeSpan > currentTime)
		/// </summary>
		/// <returns>����/������</returns>
		StateFly checkState();

	public:
		Point2i getCurrentPoint() const;
		Point2i moveTo();

		FlyStatistic getStatisticFly();

	protected:
		/// <summary>
		/// ������� �����������, ���������� ������ ���� ����.
		/// ������ ������� ������ - ��������� ��������� ����
		/// </summary>
		QList<Point2i> _listMoves;

		/// <summary>
		/// ������� ��������� ����
		/// </summary>
		Point2i _currentPoint;

		/// <summary>
		/// ���������� ������� ���, ������������ ����� ����� � �������� ������ �����������
		/// </summary>
		const size_t _torpor;

		/// <summary>
		/// ����� ��������
		/// </summary>
		QTime _createTime;

		/// <summary>
		/// ���������� ����� = _torpor x size
		/// </summary>
		QTime _lifeTimeSpan;
	};

}
