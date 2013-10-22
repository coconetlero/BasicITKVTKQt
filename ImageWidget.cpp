/* 
 * File:   ImageWidget.cpp
 * Author: zian
 * 
 * Created on 22 de octubre de 2013, 13:32
 */

#include "ImageWidget.h"

#include <vtkImageReader2.h>
#include <vtkImageReader2Factory.h>
#include <vtkInteractorStyleImage.h>

ImageWidget::ImageWidget(QWidget *parent) : QWidget(parent)
{
    // inicialice the VTK Widget
    this->qvtkWidget = new QVTKWidget(this);

    // add VTK Widget to the main layout of this widget
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addWidget(qvtkWidget);
    this->setLayout(layout);

    
    
    // Create a renderer and render window 
    this->renderer = vtkSmartPointer<vtkRenderer>::New();
    this->renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    this->renderWindow->AddRenderer(renderer);
    
    // Create a camera 
    this->camera = vtkSmartPointer<vtkCamera>::New();
    
    // Create image actor
    this->actor = vtkSmartPointer<vtkImageActor>::New();

}

ImageWidget::~ImageWidget()
{
    this->renderWindow->Finalize();
    this->qvtkWidget = NULL;
    this->vtkImage = NULL;
}

void ImageWidget::open(QString filename)
{
    // Obtain image information    
    //    this->setImageProperties(filename.toAscii().data(), true);

    // reads an image with the vtkImage readers
    vtkSmartPointer <vtkImageReader2Factory> readerFactory =
            vtkSmartPointer <vtkImageReader2Factory>::New();
    
    vtkSmartPointer <vtkImageReader2> reader =
            readerFactory->CreateImageReader2(filename.toAscii().data());

    reader->SetFileName(filename.toAscii().data());
    reader->Update();

    this->vtkImage = reader->GetOutput();

    //    this->isFliped = true;
    this->displayImage(vtkImage);

    readerFactory = NULL;
    reader = NULL;

}

void ImageWidget::displayImage(vtkImageData* image)
{
    int *dim = image->GetDimensions();
    double *spacing = image->GetSpacing();
    double *origin = image->GetOrigin();

    float Cx = (dim[0] * spacing[0]) / 2. + origin[0];
    float Cy = (dim[1] * spacing[1]) / 2. + origin[1];
    
    camera->ParallelProjectionOn();
    camera->SetFocalPoint(Cx, Cy, 0);
    camera->SetPosition(Cx, Cy, 1);

    // set actor properties
    actor->SetInput(image);
    actor->InterpolateOff();

    renderer->AddActor(actor);
    renderer->SetActiveCamera(camera);
    renderer->ResetCamera();

    qvtkWidget->SetRenderWindow(renderWindow);

    // window interactor style for display images 
    vtkSmartPointer<vtkInteractorStyleImage> style =
            vtkSmartPointer<vtkInteractorStyleImage>::New();

    // set interactor style to the qvtkWidget Interactor
    qvtkWidget->GetInteractor()->SetInteractorStyle(style);

    this->update();
}

