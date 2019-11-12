#include "telemetryrawdisplay.h"

TelemetryRawDisplay::TelemetryRawDisplay()
{
    // SWITCH TO

    // Label initialization

    labelRobot = new QLabel("Robot");
    labelGhost = new QLabel("Ghost");
    labelX = new QLabel("X");
    labelY = new QLabel("Y");
    labelZ = new QLabel("Z");
    labelTh = new QLabel("Th");
    labelV = new QLabel("V");
    labelW = new QLabel("W");
    labelIdle = new QLabel("Idle");

    labelRobotX = new QLabel("0");
    labelRobotY = new QLabel("0");
    labelRobotZ = new QLabel("0");
    labelRobotTh = new QLabel("0");
    labelRobotV = new QLabel("0");
    labelRobotW = new QLabel("0");
    labelRobotIdle = new QLabel("True");

    labelGhostX = new QLabel("0");
    labelGhostY = new QLabel("0");
    labelGhostZ = new QLabel("0");
    labelGhostTh = new QLabel("0");
    labelGhostV = new QLabel("0");
    labelGhostW = new QLabel("0");
    labelGhostIdle = new QLabel("True");

    // Labels placement
    layoutLabels = new QGridLayout;

    layoutLabels->addWidget(labelX, 0, 1);
    layoutLabels->addWidget(labelY, 0, 2);
    layoutLabels->addWidget(labelZ, 0, 3);
    layoutLabels->addWidget(labelTh, 0, 4);
    layoutLabels->addWidget(labelV, 0, 5);
    layoutLabels->addWidget(labelW, 0, 6);
    layoutLabels->addWidget(labelIdle, 0, 7);

    layoutLabels->addWidget(labelRobot, 1, 0);
    layoutLabels->addWidget(labelGhost, 2, 0);

    this->setLayout(layoutLabels);
}
