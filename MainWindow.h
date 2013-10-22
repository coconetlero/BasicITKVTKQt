/* 
 * File:   MainWindow.h
 * Author: zian fanti
 *
 * Created on 22 de octubre de 2013, 12:20
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include "ImageWidget.h"

#include <QMainWindow>

class QAction;
class QMenu;
class QMenuBar;
class QLabel;

class MainWindow : public QMainWindow
{

    Q_OBJECT


public:

    MainWindow(QWidget* parent = 0);

    virtual ~MainWindow();


private slots:
    /**
     * Load and display an image from file
     */
    void open();
    
    /**
     * Applies a median filter to an image 
     */
    void medianfilter();

private:

    void createActions();
    void createMenus();
    void createStatusBar();

    ImageWidget *imageWidget;

    QMenu *fileMenu;
    QMenu *filterMenu;

    QAction *openAct;
    QAction *medianFilterAct;
    
    QLabel *statusLabel;

};

#endif	/* MAINWINDOW_H */

