#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mSvgviewer = new SvgViewer(this);
    setCentralWidget(mSvgviewer);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void  MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void  MainWindow::on_actionOpen_triggered()
{
    QFile       fp("/home/mola/Documents/cad/Isfahan-comp-map4.svg");
    QByteArray  img2;

    if (fp.open(QIODevice::ReadOnly))
    {
        img2 = fp.readAll();
    }

    QByteArray  img = " <svg viewBox='0 0 108 95' xmlns='http://www.w3.org/2000/svg'>"
                      "    <g transform='scale(0.1)'>"
                      "        <a href=\" \"><path id=\"p2\" d='M249,699v43h211v-43h-64l-2,3l-2,4l-4,3c0,0-1,2-2,2h-4c-2,0-3,0-4,1c-1,1-3,1-3,"
                      "            2l-3,4c0,1-1,2-2,2h-4c0,0-2,1-3,0l-3-1c-1,0-3-1-3-2c-1-1,0-2-1-3l-1-3c-1-1-2-1-3-1c-1,0-4,"
                      "            0-4-1c0-2,0-3-1-4v-3v-3z'/></a>"
                      "        <path id=\"p3\" d='M385,593c0,9-6,15-13,15c-7,0-13-6-13-15c0-8,12-39,14-39c1,0,12,31,12,39'/>"
                      "    </g>"
                      "</svg>";

    mSvgviewer->setSvg(img2);
}
