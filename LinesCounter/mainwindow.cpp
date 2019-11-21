#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "linescounter.h"
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("GeniusVlyf Lines Counter");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonOpen_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,"select the file", "./");
    QFile f(file);
    f.open(QFile::ReadOnly);
    QTextStream out(&f);
    ui->textEdit->setText(QString(out.readAll()));
    LinesCounter lc(file);
    lc.Counter();
    ui->lineEditCode->setText(QString::number(lc.GetCodeLines()));
    ui->lineEditComment->setText(QString::number(lc.GetCommentLines()));
    ui->lineEditBlank->setText(QString::number(lc.GetBlankLines()));
    ui->lineEditSum->setText(QString::number(lc.GetCodeLines()+lc.GetCommentLines()+lc.GetBlankLines()));
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->lineEditSum->setText("0");
    ui->lineEditCode->setText("0");
    ui->lineEditBlank->setText("0");
    ui->lineEditComment->setText("0");
    ui->textEdit->setText("");
}
