#ifndef SVGITEM_H
#define SVGITEM_H

#include <QGraphicsSvgItem>

class SvgItem: public QGraphicsSvgItem
{
public:
    SvgItem(QString id, QSvgRenderer   *renderer);

    // QGraphicsItem interface

protected:
    void  mousePressEvent(QGraphicsSceneMouseEvent *event);

    void  mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QString       mID;
    QSvgRenderer *mRenderer = nullptr;
};

#endif // SVGITEM_H
