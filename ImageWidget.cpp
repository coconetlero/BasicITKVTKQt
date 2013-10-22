/* 
 * File:   ImageWidget.cpp
 * Author: zian
 * 
 * Created on 22 de octubre de 2013, 13:32
 */

#include "ImageWidget.h"

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);

}

ImageWidget::~ImageWidget()
{
}

ImageWidget::open(QString filename) {
    
}

ImageWidget::displayImage(vtkImageData* image) {
    
}

