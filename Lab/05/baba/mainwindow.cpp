#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QImage>
#include <QFileDialog>
void MainWindow::loadImage()
{
QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Image Files (*.png)"));
image.convertTo(QImage::Format_ARGB32);
ui->label->setText("Изображение успешно загружено");

}
void MainWindow::saveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/home/jana/untitled.png",
                               tr("Images (*.png)"));

}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::loadImage);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::saveImage);
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;

}


