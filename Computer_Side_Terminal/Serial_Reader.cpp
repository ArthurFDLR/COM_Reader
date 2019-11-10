#include <iostream>
#include "SerialPort.h"
#include <stdio.h>

#define MAX_DATA_LENGTH 255

char incomingData[MAX_DATA_LENGTH];

char* portName = "COM7"; //Only readable

SerialPort *arduino;

void ConnectCOM()
{
    arduino = new SerialPort(portName);

    while (!arduino->isConnected())
    {
        Sleep(200);
        arduino = new SerialPort(portName);
        std::cout << "Waiting for connection." << std::endl;
    }

    std::cout << "Connection established at port " << portName << std::endl;
}

int main(void)
{   
    ConnectCOM();
    
    while (arduino->isConnected())
    {
        arduino->readSerialPort(incomingData, MAX_DATA_LENGTH);
        printf("%s", incomingData);
        Sleep(5);
    }

}