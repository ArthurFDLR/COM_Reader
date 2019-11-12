#ifndef TELEMETRYRAWDISPLAY_H
#define TELEMETRYRAWDISPLAY_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>

class TelemetryRawDisplay : public QWidget
{
public:
    TelemetryRawDisplay();
private:
    QLabel* labelRobot;
    QLabel* labelGhost;
    QLabel* labelX;
    QLabel* labelY;
    QLabel* labelZ;
    QLabel* labelTh;
    QLabel* labelV;
    QLabel* labelW;
    QLabel* labelIdle;

    QLabel* labelRobotX;
    QLabel* labelRobotY;
    QLabel* labelRobotZ;
    QLabel* labelRobotTh;
    QLabel* labelRobotV;
    QLabel* labelRobotW;
    QLabel* labelRobotIdle;

    QLabel* labelGhostX;
    QLabel* labelGhostY;
    QLabel* labelGhostZ;
    QLabel* labelGhostTh;
    QLabel* labelGhostV;
    QLabel* labelGhostW;
    QLabel* labelGhostIdle;

    QGridLayout* layoutLabels;
};

#endif // TELEMETRYRAWDISPLAY_H
