#pragma once

#include <QGraphicsScene>
#include <QSharedPointer>
#include <QVector>

#include "FlyCellBoard.h"
#include "flywalker.h"

namespace flyses {

typedef QVector<FlyCellBoardPtr> FlyBoardCells;
typedef QVector<FlyBoardCells> FlyBoardRows;

///
/// \brief The FlyBoard class
/// Должна уметь:
/// 1) Выбирать размер сцены в зависимости от размера доски и мухоемкости
/// 2) Выбирать размер ячейки в зависимости от мухоемкости ( 1 муха занимает клетку 10х10)
/// 2.1) Размер клетки = n * на размер мухи, где n - размер матрицы размещения в ячейке и ближайший квадрат значения к мухоемкость (п2.3)
/// 2.2) Мухи занимают положение согластно  их номеру в ячейке
/// 2.3) При определении мухоемкости определяем матрицу положений мух внутри ячейки: мухоемкость < n^2
/// 3) Рисовать сетку для мух
///
class FlyBoardScene: public QGraphicsScene
{
public:
	FlyBoardScene(size_t sizeBoard, size_t cellCapacity, size_t countFly, QObject *parent = 0);

	void addFly(const FlyPtr &fly);

	FlyCellBoardPtr getCell(QPoint point);

public slots:
	void updateWalkerPos(const FlyWalkerPtr &walker);

protected:
	QGraphicsItemGroup* createBoard();

protected:
	FlyBoardRows _boardImage;
	QVector<FlyWalkerPtr> _walkers;

	size_t _cellSize;
	const size_t _boardSize;
	const size_t _cellCapacity;
};

} // namespace flyses
