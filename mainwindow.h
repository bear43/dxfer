#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dxfdatacontainerimpl.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    DXFDataContainerImpl* GetDataContainer()
    {
        return dataContainer;
    }
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    DXFDataContainerImpl* dataContainer = nullptr;
};

#endif // MAINWINDOW_H
