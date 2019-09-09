#include <vector>
#include <queue>
#include <iostream>
#include <src/mainwindow.h>
#include <QApplication>
#include <ros/ros.h>

using namespace std;

int main(int argc, char* argv[]) {
    ros::init(argc,argv,"MotionPlanning");
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    app.exec();

    return 0;
}
