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
#include <QMessageBox>

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

using namespace std;
class MainWindow : public QWidget {
    Q_OBJECT
    
public:
/**constructor */
    explicit MainWindow();
    ~MainWindow();/**destructor*/
    void show();/**shows everything in the view*/
    int counter;/**used to help with the timer*/
    
    Mylist<GUITile*> *tiles;/**tiles pointer of GUITile pointers*/
    QLineEdit *size;/**size pointer*/
    
    void MainWindowmoveTile(int number, GUITile* tile);/**move tile*/
    Board *b;/**board pointer*/

private:
    QGraphicsScene *scene;/**scene to display GUI*/
    QGraphicsView *view;/**adds items to change display*/
    QTimer *timer;/**timer to handle animating tiles*/
    QPushButton *button;/**start button connected to newGame*/
    QLineEdit *seed;/**randomization, user input*/
    QLineEdit *moves;/**initial moves, user input*/
    QPushButton *quit;/**quit button, exits out*/
    QPushButton *cheat;/**cheat button, must */
    QListView *sequence;/***/
    QRadioButton *heur;/**manhattan heuristic button clicked to perform cheat*/
    QRadioButton *oop;/**out of place heuristic button clicked to perform cheat*/
    QStandardItemModel *hint;/**hint displayed in window, shows tiles to move in order to win*/
    //Board *board;
    QListView *solution;/**helps display hint in window*/
    QLineEdit *error;/**prints out different errors based on bad user input*/

public slots:
 
    void newGameClicked();
    void AStar();
};

#endif // MAINWINDOW_H
