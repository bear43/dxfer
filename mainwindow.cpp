#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DXFParser.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dataContainer;
}

void FillContainer(Ui::MainWindow* ui, DXFParser* pParser, DXFDataContainerImpl* pDataContainer)
{
    pDataContainer = new DXFDataContainerImpl();
    pParser->FillContainer(pDataContainer);
    pDataContainer->FillUIInfo(ui);
}

void ReadDXF(Ui::MainWindow* ui, QString filename, DXFDataContainerImpl* pDataContainer)
{
    DXFParser* pParser = new DXFParser();
    if(pParser->ReadDXF(filename))
    {
        ui->statusBar->showMessage(QString::asprintf("%s readed successful", filename.toUtf8().constData()));
        ui->labelFileInfo->setText(filename);
    }
    else
    {
        QString errorMessage = QString::asprintf("Cannot parse %s. Fault!", filename.toUtf8().constData());
        QMessageBox::critical((QWidget*)ui, "Error", errorMessage);
        ui->statusBar->showMessage(errorMessage);
    }
    FillContainer(ui, pParser, pDataContainer);
    delete pParser;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this);
    delete dataContainer;
    dataContainer = nullptr;
    ReadDXF(ui, filename, GetDataContainer());
}
