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
    this->imageWidget = NULL;
}

void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());

    if (!fileName.isEmpty())
    {
        this->imageWidget = new ImageWidget();
        this->imageWidget->open(fileName);

        this->setCentralWidget(imageWidget);
        this->setWindowTitle(tr("Image Viewer"));
        this->resize(640, 480);

        this->statusLabel->setText("Open image");
    }
    else
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("No file specified for loading");
        errorMessage.exec();
        return;
    }
}

void MainWindow::medianFilter()
{

}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    medianFilterAct = new QAction(tr("&Median Filter"), this);
    connect(medianFilterAct, SIGNAL(triggered()), this, SLOT(medianFilter()));
}

void MainWindow::createMenus()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);

    filterMenu = new QMenu(tr("&Filter"), this);
    filterMenu->addAction(medianFilterAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(filterMenu);
}

void MainWindow::createStatusBar()
{
    statusLabel = new QLabel("Basic Image Viewer");
    statusLabel->setAlignment(Qt::AlignHCenter);
    statusLabel->setMaximumSize(statusLabel->sizeHint());

    statusBar()->addWidget(statusLabel);
}