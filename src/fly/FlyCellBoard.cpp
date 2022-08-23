#include "FlyCellBoard.h"

FlyCellBoard::FlyCellBoard()
{

}

void flyses::FlyCellBoard::moveFlyWalker(const FlyWalkerPtr &walker)
{

}

bool flyses::FlyCellBoard::checkCapacity()
{
	return childItems().size() < capacity;
}
