#pragma once
#include <QGraphicsItemGroup>
#include "flywalker.h"

namespace flyses {

class FlyCellBoard;
typedef QSharedPointer<FlyCellBoard> FlyCellBoardPtr;

class FlyCellBoard : public QGraphicsItemGroup
{
public:
	FlyCellBoard();
	bool checkCapacity();

protected:
	size_t capacity{0};
};

} // namespace flyses
