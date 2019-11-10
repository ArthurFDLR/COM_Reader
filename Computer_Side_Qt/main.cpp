#include <QCoreApplication>
#include <QSerialPort>
#include <QDebug>
#include <iostream>
#include <QSerialPortInfo>

int main()
{

    QSerialPort serial;

    //Auto-detect COM port
    foreach (
             const QSerialPortInfo &info, QSerialPortInfo::availablePorts()
             ) {
        qDebug() << "Name        : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();

        serial.setPort(info);
    }

    // Example use QSerialPort

    serial.setBaudRate(QSerialPort::Baud9600);

    if (serial.open(QIODevice::ReadWrite)){

        qDebug()<<serial.isOpen();

        while(1){
            if(serial.waitForReadyRead(10)){
                QByteArray ba = serial.readAll();
                qDebug()<<ba ;
            }
        }
        serial.close();
    }
}
