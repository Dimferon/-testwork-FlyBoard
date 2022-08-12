#pragma once

#include <QSharedPointer>

#include "Fly.h"

namespace flyses {

class FlyBoard
{
public:
	void addFly(QSharedPointer<Fly> fly);

protected:
	const size_t _size;
	const size_t _capacity;
};

} // namespace flyses
