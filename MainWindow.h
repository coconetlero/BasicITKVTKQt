/* 
 * File:   MainWindow.h
 * Author: zian fanti
 *
 * Created on 22 de octubre de 2013, 12:20
 */

#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <QMainWindow>
    
class MainWindow : public QMainWindow 
{
    Q_OBJECT
    
public:
    MainWindow();
    MainWindow(const MainWindow& orig);
    virtual ~MainWindow();
private:

};

#endif	/* MAINWINDOW_H */

