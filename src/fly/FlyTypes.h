#pragma once

#include <QTime>
#include <QPair>

namespace flyses {

	typedef QPair<int, int> Point2i;

	enum class StateFly
	{
		DEAD_FLY,
		LIVE_FLY
	};

	struct FlyStatistic
	{
		int speed; // ��������
		int mileage; // ������
		long lifetime; // �������
		StateFly state; // ��������� ����
	};
}
