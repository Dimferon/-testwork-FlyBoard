#include "FlyTypes.h"

namespace flyses {

const QPoint FlyMoveTo::NOT_MOVE{0,0};

const QPoint FlyMoveTo::UP{0, 1};
const QPoint FlyMoveTo::UP_RIGHT{1, 1};

const QPoint FlyMoveTo::RIGHT{1, 0};

const QPoint FlyMoveTo::DOWN_RIGHT{1, -1};
const QPoint FlyMoveTo::DOWN{0, -1};
const QPoint FlyMoveTo::DOWN_LEFT{-1, -1};

const QPoint FlyMoveTo::LEFT{-1, 0};
const QPoint FlyMoveTo::UP_LEFT{-1, 1};

const QVector<QPoint>
	FlyMoveTo::MOVE_TO{UP, UP_RIGHT, RIGHT, DOWN_RIGHT, DOWN, DOWN_LEFT, LEFT, UP_LEFT};

} // namespace flyses
