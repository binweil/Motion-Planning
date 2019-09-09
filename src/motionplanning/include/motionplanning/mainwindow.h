#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <ros/ros.h>

#include <QMainWindow>
#include <QFileDialog>
#include <QString>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

#include <vector>
#include <unordered_map>


#include <src/Algorithms/motionplanningalgorithms.h>
#include <src/Algorithms/astar.h>
#include <src/Algorithms/bfs.h>
#include <src/Algorithms/dfs.h>
#include <src/Algorithms/rrt.h>

#include <src/Helper/TextProccessor.h>

using namespace std;
using namespace pcl;
using namespace pcl::io;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_searchButton_clicked();

    void on_comboBox_activated(const QString &algorithm);

    void on_sendStartButton_clicked();

private:
    int currentAlgorithm;
    QImage image;
    Ui::MainWindow *ui;
    vector<vector<int>> maze;
    void plot(vector<vector<int>> &maze);
    vector<vector<int>> readText2Vector (string filename);
    vector<QString> algorithmNames = {"A*","BFS","DFS"};
    unordered_map<string,int> Algorithm_to_code;
    Point *start = new Point(-1,-1);
    Point *target = new Point(-1,-1);
};

#endif // MAINWINDOW_H
