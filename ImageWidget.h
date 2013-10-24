/* 
 * File:   ImageWidget.h
 * Author: zian
 *
 * Created on 22 de octubre de 2013, 13:32
 */

#ifndef IMAGEWIDGET_H
#define	IMAGEWIDGET_H

#include <QtGui>
#include <QWidget>
#include <QVTKWidget.h>

#include <vtkSmartPointer.h>

#include <vtkImageData.h>
#include <vtkRenderer.h>
#include <vtkImageActor.h>
#include <vtkRenderWindow.h>
#include <vtkCamera.h>



//#include <QString>

class ImageWidget : public QWidget
{
    Q_OBJECT

public:
    /** 
     * Constructor for this ImageWidget 
     */
    ImageWidget(QWidget *parent = 0);

    /** 
     * Destructor for this ImageWidget 
     */
    virtual ~ImageWidget();

    /**
     * load an display an image from file
     */
    void open(QString filename);
    
    /**
     * Applays a median filter to an image
     */
    void medianFilter(int windowSize);

private:

    /** A special widget to display inside Qtwidget a vtk object */
    QVTKWidget *qvtkWidget;

    /**
     * to display the loaded image in the QVTKwidget
     * @param image vtkImageData
     */
    void displayImage(vtkImageData *image);

    /** The VTK image */
    vtkSmartPointer <vtkImageData> vtkImage;

    vtkSmartPointer<vtkImageActor> actor;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkRenderWindow> renderWindow;
    vtkSmartPointer<vtkCamera> camera;


};

#endif	/* IMAGEWIDGET_H */

