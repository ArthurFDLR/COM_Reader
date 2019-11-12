#include "mainwindow.h"

MainWindow::MainWindow() : QWidget()
{
    // Create thread dedicated to read data

    QThread* thread = new QThread;
    SerialParser* parser = new SerialParser();
    parser->moveToThread(thread);
    connect(thread, SIGNAL(started()), parser, SLOT(process()));
    connect(parser, SIGNAL(finished()), thread, SLOT(quit()));
    connect(parser, SIGNAL(finished()), parser, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    connect(parser, SIGNAL(dataReady(QByteArray)), this, SLOT(update(QByteArray)));
    thread->start();


    m_textWindow = new QTextEdit(this);
    m_textWindow->setText("Hello, world!!!!!");

    telemetryDisplay = new TelemetryRawDisplay;

    QVBoxLayout *layoutPrincipal = new QVBoxLayout;
    layoutPrincipal->addWidget(telemetryDisplay);
    layoutPrincipal->addWidget(m_textWindow);

    this->setLayout(layoutPrincipal);

}

void MainWindow::update(QByteArray data)
{
    m_textWindow->append(data);
}
