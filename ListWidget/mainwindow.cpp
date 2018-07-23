#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->MainListWidget->addItem("Sphere");
    ui->MainListWidget->addItem("Cylinder");
    ui->MainListWidget->addItem("Cone");
    ui->MainListWidget->addItem("Torus");
    ui->MainListWidget->addItem("Cube");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createSpinBoxes(QString s)
{
    QByteArray ba = s.toLatin1();
     const char *c_str2 = ba.data();

    spinBoxesGroup = new QGroupBox(tr(c_str2));
       QSpinBox *integerSpinBox = new QSpinBox;
       integerSpinBox->setRange(-20, 20);
       integerSpinBox->setSingleStep(1);
       integerSpinBox->setValue(0);
}

void MainWindow::on_MainListWidget_itemClicked(QListWidgetItem *item)
{
    ui->statusBar->showMessage(item->text());

    if (spinBoxesGroup)
        delete spinBoxesGroup;
    createSpinBoxes(item->text());
    ui->MainVerticalLayout->addWidget(spinBoxesGroup);
}

void MainWindow::on_btnAdd_clicked()
{
    QListWidgetItem* item1 = new QListWidgetItem(ui->comboBox->currentText());
    ui->MainListWidget->addItem(item1);
}

void MainWindow::on_btnClean_clicked()
{
    ui->MainListWidget->clear();
    QMessageBox::information(this, "Scene is cleaned","You have deleted everything :(");
}
