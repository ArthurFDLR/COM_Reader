#include "mainwindow.h"

MainWindow::MainWindow() : QWidget()
{

    setFixedSize(400, 425);
    m_textWindow = new QTextEdit(this);
    m_textWindow->setGeometry(25,25,350,350);
    m_textWindow->setText("Hello, world!!!!!");

    QThread* thread = new QThread;
    SerialParser* parser = new SerialParser();
    parser->moveToThread(thread);
    connect(thread, SIGNAL (started()), parser, SLOT (process()));
    connect(parser, SIGNAL (finished()), thread, SLOT (quit()));
    connect(parser, SIGNAL (finished()), parser, SLOT (deleteLater()));
    connect(thread, SIGNAL (finished()), thread, SLOT (deleteLater()));

    connect(parser, SIGNAL (dataReady(QByteArray)), this, SLOT (update(QByteArray)));
    thread->start();
}

void MainWindow::update(QByteArray data)
{

    m_textWindow->append(data);
}
