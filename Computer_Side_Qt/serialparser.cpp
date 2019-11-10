#include "serialparser.h"

SerialParser::SerialParser()
{

}

void SerialParser::process()
{
    serial = new QSerialPort;
    //Auto-detect COM port
    foreach (
             const QSerialPortInfo &info, QSerialPortInfo::availablePorts()
             ) {
        qDebug() << "Name        : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();

        serial->setPort(info);
    }
    serial->setBaudRate(QSerialPort::Baud9600);
    // Example use QSerialPort

    if (serial->open(QIODevice::ReadWrite)){

        qDebug()<<serial->isOpen();

        while(1){
            if(serial->waitForReadyRead(10)){
                QByteArray ba = serial->readAll();
                qDebug()<<ba ;
                emit dataReady(ba);
            }
        }
        emit finished();
        serial->close();
    }
}
