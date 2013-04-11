#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qapplication.h>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QRadioButton>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <vector>
#include <QTextEdit>
#include <QLineEdit>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
#include "board.h"
#include "GUITile.h"
#include "mylist.h"

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

using namespace std;
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    void show();
    int counter;
    
    Mylist<GUITile*> *tiles;
    QLineEdit *size;
    void MainWindowmoveTile(int number, GUITile* tile);
    Board *b;

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    QPushButton *button;
    //QLineEdit *size;
    QLineEdit *seed;
    QLineEdit *moves;
    QPushButton *quit;
    QPushButton *cheat;
    QListView *sequence;
    QRadioButton *heur;
    QRadioButton *oop;
    QStandardItemModel *hint;
    //Board *board;
    QListView *solution;
    QLineEdit *error;

public slots:
 
    void newGameClicked();
    void AStar();
    void handleTimer();
};

#endif // MAINWINDOW_H
