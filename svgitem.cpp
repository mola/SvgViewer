#include "svgitem.h"

#include <QSvgRenderer>
#include <iostream>

SvgItem::SvgItem(QString id, QSvgRenderer   *renderer):
    mID(id),
    mRenderer(renderer)
{
    setSharedRenderer(renderer);
    setElementId(id);

    auto  bounds = renderer->boundsOnElement(id);

    setPos(bounds.topLeft());

    setFlags(QGraphicsItem::ItemIsSelectable);
}

void  SvgItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "IO CLICK : " << mID.toStdString() << std::endl;
    QGraphicsSvgItem::mousePressEvent(event);
}

void  SvgItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    std::cout << "IO CLICK(R): " << mID.toStdString() << std::endl;
    QGraphicsSvgItem::mouseReleaseEvent(event);
}
