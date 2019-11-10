#ifndef SERIALPARSER_H
#define SERIALPARSER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class SerialParser : public QObject
{
    Q_OBJECT

public:
    SerialParser();

public slots:
    void process();

signals:
    void finished();
    void dataReady(QByteArray data);

private:
    QSerialPort *serial;

};

#endif // SERIALPARSER_H
