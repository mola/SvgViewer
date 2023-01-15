#ifndef SVGVIEWER_H
#define SVGVIEWER_H

#include <QGraphicsView>
#include <QSvgRenderer>

class SvgViewer: public QGraphicsView
{
public:
    SvgViewer(QWidget *parent = nullptr);

    void  setSvg(QByteArray image);

private:
    QGraphicsScene *mScene = nullptr;
    QSvgRenderer   *mRenderer;
};

#endif // SVGVIEWER_H
