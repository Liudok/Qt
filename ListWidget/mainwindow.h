#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QObject>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <QMainWindow>
#include<QListWidget>
#include<QGridLayout>
#include<QSpinBox>
#include<QLabel>
#include<QGroupBox>
#include<QMessageBox>
#include<QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
     void on_MainListWidget_itemClicked(QListWidgetItem *item);
     void createSpinBoxes(QString s);
     void on_btnAdd_clicked();

     void on_btnClean_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene * m_scene;
    QGroupBox *spinBoxesGroup;

};

#endif // MAINWINDOW_H
