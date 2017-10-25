#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    auto constexpr useIcon = false;

    QPixmap pixmap = QPixmap("://gears.png").scaledToWidth(64);
    QIcon icon(pixmap);
    QString text = "Item text";

    ui->setupUi(this);

    {
        QTableWidgetItem *item = new QTableWidgetItem;
        if(useIcon) item->setIcon(icon);
        else item->setData(Qt::DecorationRole, pixmap);
        item->setText(text);
        ui->tableWidget->setItem(0, 0, item);
    }

    {
        QListWidgetItem *item = new QListWidgetItem;
        if(useIcon) item->setIcon(icon);
        else item->setData(Qt::DecorationRole, pixmap);
        item->setText(text);
        ui->listWidget->addItem(item);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
