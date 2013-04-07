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
#include "bouncingrectangle.h"
#include <QTextEdit>
#include "board.h"

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
    void newGameClicked();
    vector <BouncingRectangle*> rectangles;
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    BouncingRectangle *item;
    QPushButton *button;
    QTextEdit *size;
    QTextEdit *seed;
    QTextEdit *moves;
    QPushButton *quit;
    //Board *board;

public slots:

    void handleButton();
};

#endif // MAINWINDOW_H
