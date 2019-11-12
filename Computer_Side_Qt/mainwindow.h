#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QThread>
#include "serialparser.h"
#include "telemetryrawdisplay.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow();
    SerialParser Parser;

public slots:
    void update(QByteArray data);

private:
    QTextEdit *m_textWindow;
    TelemetryRawDisplay* telemetryDisplay;

};

#endif // MAINWINDOW_H
