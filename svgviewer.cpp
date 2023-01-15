#include "svgviewer.h"
#include "svgitem.h"
#include <QXmlStreamAttributes>

SvgViewer::SvgViewer(QWidget *parent):
    QGraphicsView(parent)
{
    mScene    = new QGraphicsScene(this);
    mRenderer = new QSvgRenderer();

    mScene->setBackgroundBrush(QColor::fromString("#282e33"));
    setScene(mScene);
}

void  SvgViewer::setSvg(QByteArray image)
{
    resetTransform();
    mScene->clear();
    mRenderer->load(image);

    auto  _xml = new QXmlStreamReader(image);
// bool         inDefs           = false; // -- Мы в секции defs
// int          defsLvl          = 0; // -- Подсчитываем на каком уровне в defs, что бы знать прямых наследников
// QStringList  fPrimitiveTokens = { "g", "path", "line", "rect", "circle", "ellipse" }; // -- Что из примитивов заносим в FPrimitive, если они в секции defs
// QStringList  toDefsForse      = { "lineargradient", "radialgradient", "clippath", "style" }; // -- Что принудительно заносим в defs, да же если они вне этой
    QStringList  ids;

    // секции
    QVariantList  v;

    while (!_xml->atEnd())
    {
        if (_xml->hasError()) { return; }

        _xml->readNext();

        if (_xml->tokenType() == QXmlStreamReader::StartDocument) { continue; }

        if (_xml->tokenType() == QXmlStreamReader::StartElement)
        {
            QString  elName = _xml->name().toString().toLower();

////-- Что принудительно заносить в defs
// if ( (defsLvl==0) && (toDefsForse.indexOf(elName)>-1) ) {
// inDefs = false; //-- Мы будем не в реальной секции, что бы как только кончится итем сразу выйти
// defsLvl = 1;
// }

// if  ( defsLvl>0 ) {
// if ( defsLvl==1 ) { //-- Каждого прямого наследника из defs считаем как отдельный
// prevLevel = currentLevel;
// if ( fPrimitiveTokens.indexOf(elName)>-1 ) {
// FPrimitive * fPrim = new FPrimitive();
// currentLevel = fPrim->primitive;
// }
// }
// defsLvl++;
// }
// _xml->
            QXmlStreamAttributes  atts = _xml->attributes();
            auto                  sid  = _xml->attributes().value("id").toString();

            v.clear();

            if (sid.isEmpty())
            {
                for (auto a : atts)
                {
                    v.push_back(a.name().toString());
                    v.push_back(a.value().toString());
                }

                continue;
            }

            if (elName == "svg")  // -- svg сам по себе как группа, парсим
            {
            }
            else if (elName == "g")
            {
                ids.append(_xml->attributes().value("id").toString());
            }
            else if (elName == "path")
            {
                ids.append(_xml->attributes().value("id").toString());
            }
            else if (elName == "rect")
            {
                ids.append(_xml->attributes().value("id").toString());
            }
            else if (elName == "line")
            {
            }
            else if (elName == "image")
            {
            }
            else if (elName == "style")
            {
            }
            else if (elName == "defs")
            {
            }
            else if (elName == "title")
            {
            }
            else if (elName == "desc")
            {
            }
            else if (elName == "circle")
            {
                ids.append(_xml->attributes().value("id").toString());
            }
            else if (elName == "ellipse")
            {
                ids.append(_xml->attributes().value("id").toString());
            }
            else if (elName == "lineargradient")
            {
            }
            else if (elName == "radialgradient")
            {
            }
            else if (elName == "polyline")
            {
                ids.append(_xml->attributes().value("id").toString());
            }
            else if (elName == "polygon")
            {
                ids.append(_xml->attributes().value("id").toString());
            }
            else if (elName == "clippath")
            {
            }
            else
            {
                qWarning() << "Unsupported element" << _xml->name();
            }
        }
    }

    if (mRenderer->isValid())
    {
        for (auto id : ids)
        {
            auto  item = new SvgItem(id, mRenderer);

            mScene->addItem(item);
        }
    }
}
