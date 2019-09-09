#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;
using namespace pcl;
using namespace pcl::io;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // setup algorithms related variables
    for (int i = 0; i < algorithmNames.size(); i++)
    {
      this->ui->comboBox->addItem(algorithmNames[i]);
      Algorithm_to_code[algorithmNames[i].toStdString()] = i;
    }
    currentAlgorithm = 0; //default A*

    // Setup QGraphicsView

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open PointCloud"), "", tr("Maze Files (*.txt)"));
    if (fileName == "") {
        return;
    }
    TextProccessor txtProcessor;
    maze = txtProcessor.readText2Vector(fileName.toStdString());
    plot(maze);
}

void MainWindow::plot(vector<vector<int>> &maze)
{
    image = QImage(maze.size(),maze[0].size(),QImage::Format_RGB32);
    // Draw Obstacles;
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[0].size(); j++) {
            if (maze[i][j] == 1) {
                image.setPixel(j,i,qRgb(0,0,0));
            }else{
                image.setPixel(j,i,qRgb(0,0,255));
            }
        }
    }

    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(image));
    ui->mazePlot->setScene(graphic);
    ui->mazePlot->fitInView(graphic->sceneRect());
}

void MainWindow::on_searchButton_clicked()
{
    if (maze.size() == 0 || start->x == -1 || start->y == -1 || target->x == -1 || target->y == -1) {
        cout << "Error Occurred" << endl;
        return;
    }
    plot(maze);
    vector<Point*> res;
    switch (currentAlgorithm) {
        case 0: {
            Astar obj(maze);
            res = obj.search(start,target);
        }
            break;
        case 1: {
                Bfs obj(maze);
                res = obj.search(start,target);
                break;
        }
        case 2: {
                Dfs obj(maze);
                res = obj.search(start,target);
        }
            break;
    };

    vector<Point*> path;
    Point *final = res[res.size()-1];
    while (final != nullptr){
        path.push_back(final);
        int x = final->x;
        int y = final->y;
        image.setPixel(y,x,qRgb(0,255,0));
        QGraphicsScene *graphic = new QGraphicsScene(this);
        graphic->addPixmap(QPixmap::fromImage(image));
        ui->mazePlot->setScene(graphic);
        ui->mazePlot->fitInView(graphic->sceneRect());
        final = final->parent;
    }
}

void MainWindow::on_comboBox_activated(const QString &algorithm)
{
    currentAlgorithm = Algorithm_to_code[algorithm.toStdString()];
}

void MainWindow::on_sendStartButton_clicked()
{
    if (maze.size() == 0) {
        cout << "Setup Maze First" << endl;
        return;
    }
    plot(maze);
    QString start_x = ui->lineEdit_startX->text();
    QString start_y = ui->lineEdit_startY->text();
    QString target_x = ui->lineEdit_targetX->text();
    QString target_y = ui->lineEdit_targetY->text();
    if (start_x == "" || start_y == "" || target_x == "" || target_y == "") {
        cout << "Start and Target Input Error" << endl;
        return;
    }
    start->x = stoi(start_x.toStdString());
    start->y = stoi(start_y.toStdString());
    target->x = stoi(target_x.toStdString());
    target->y = stoi(target_y.toStdString());

    image.setPixel(start->y,start->x,qRgb(255,0,0));
    image.setPixel(target->y,target->x,qRgb(255,0,0));
    QGraphicsScene *graphic = new QGraphicsScene(this);
    graphic->addPixmap(QPixmap::fromImage(image));
    ui->mazePlot->setScene(graphic);
    ui->mazePlot->fitInView(graphic->sceneRect());
}

void MainWindow::on_actionSave_triggered()
{
    map<string,string> id2value;
    id2value[to_string(testID)] = "'Paul', 32, 'California', 20000.00";
    testID++;
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save TestData"),"",tr("SQL DataBase (*.db)"));
    SQLDataBase database;
    database.openDataBase(fileName.toStdString());
    database.createTable(fileName.toStdString(),"company");
    database.insert2Table("company",id2value);
    database.close();
}
