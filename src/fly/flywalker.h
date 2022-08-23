#pragma once
#include "Fly.h"

#include <memory>

#include <QGraphicsItem>
#include <QMutex>
#include <QObject>
#include <QString>
#include <QTimer>

namespace flyses {
class FlyWalker;
typedef QSharedPointer<FlyWalker> FlyWalkerPtr;

///
/// \brief The FlyWalker class запускает в потоке функцию выбора пути, обновляет положение картинки на доске
///
class FlyWalker : public QObject
{
	Q_OBJECT
public:
	///
	/// \brief FlyWalker
	/// \param boardSize
	/// \param callCheckCell
	/// \param callCalculatePosition
	/// \param parent
	///
	explicit FlyWalker(
		size_t boardSize,
		const std::function<bool(const QPoint, QGraphicsItem *)> &callCalculatePosition,
		QObject *parent = nullptr);

	///
	/// \brief FlyWalker
	/// \param boardSize
	/// \param callCheckCell
	/// \param callCalculatePosition
	/// \param parent
	///
	explicit FlyWalker(
		const FlyPtr &fly,
		const std::function<bool(const QPoint, QGraphicsItem *)> &callCalculatePosition,
		QObject *parent = nullptr);

public:
	void startMove();

	const FlyInfo getInfoFly();
	const QPoint currentPos();
	QGraphicsPixmapItem *imageItem();

public slots:
	void aliveFly();
	void pauseMove();

signals:
	void updatePos(const FlyWalkerPtr &walker);

protected slots:
	void deadFly();

protected:
	void setImage(QString imageName);
	void moveFlyToPoint();
	void rotateImage(QPoint vectorMove);
	void choosingPoint();

private:
	int _id;
	QSharedPointer<QThread> _walkerThead{nullptr};
	QTimer _timerAlive;

	FlyPtr _fly{nullptr};

	QGraphicsPixmapItem *_grapItem{nullptr};

	///
	/// \brief _callImageMoveTo переход в новую позицию картинки
	///
	std::function<bool(const QPoint, QGraphicsItem *)> _callImageMoveTo;
};

} // namespace flyses
