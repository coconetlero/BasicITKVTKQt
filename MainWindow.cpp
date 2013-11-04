/*
 * File:   MainWindow.cpp
 * Author: zian fanti
 *
 * Created on 22 de octubre de 2013, 12:20
 */

#include "MainWindow.h"
#include "MedianFilterDialog.h"
#include "GADFilterDialog.h"

#include <iostream>

#include <QtGui>
#include <QErrorMessage>


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
    // create and show the median filter dialog
    MedianFilterDialog filterDialog(this);
    
    if (this->imageWidget)
    {
        // if the user don't cancel the action
        if (filterDialog.exec())
        {
            // get selected value from dialog
            int size = filterDialog.spinBox->value();
            this->imageWidget->medianFilter(size);
        }
    }
    else
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("No opened image");
        errorMessage.exec();
        return;
    }
    
}

void MainWindow::gradientAnisotropicFilter()
{
    // create and show the median filter dialog
    GADFilterDialog filterDialog(this);
    
    if (this->imageWidget)
    {
        // if the user don't cancel the action
        if (filterDialog.exec())
        {
            // get selected values from dialog
        }
    }
    else
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("No opened image");
        errorMessage.exec();
        return;
    }
    
}

void MainWindow::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    
    medianFilterAct = new QAction(tr("&Median Filter"), this);
    connect(medianFilterAct, SIGNAL(triggered()), this, SLOT(medianFilter()));
    
    GAFilterAct = new QAction(tr("&Gradient Anisotropic Filter"), this);
    connect(GAFilterAct, SIGNAL(triggered()), this, SLOT(gradientAnisotropicFilter()));

}

void MainWindow::createMenus()
{
    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    
    filterMenu = new QMenu(tr("&Filter"), this);
    filterMenu->addAction(medianFilterAct);
    filterMenu->addAction(GAFilterAct);
    
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