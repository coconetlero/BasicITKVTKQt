/* 
 * File:   MainWindow.cpp
 * Author: zian fanti
 * 
 * Created on 22 de octubre de 2013, 12:20
 */

#include "MainWindow.h"

#include <iostream>

#include <QtGui>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);

    createActions();
    createMenus();
    createStatusBar();
}

MainWindow::~MainWindow()
{

}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());

    if (!fileName.isEmpty())
    {
        std::cout << fileName.toAscii().data() << std::endl;
    }
}

void MainWindow::createMenus()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);   

    menuBar()->addMenu(fileMenu);
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));    
}



void MainWindow::createStatusBar()
{
    statusLabel = new QLabel("Basic Image Viewer");
    statusLabel->setAlignment(Qt::AlignHCenter);
    statusLabel->setMaximumSize(statusLabel->sizeHint());

    statusBar()->addWidget(statusLabel);
}