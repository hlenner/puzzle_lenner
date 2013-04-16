#ifndef GUITile_H
#define GUITile_H
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QObject>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qapplication.h>
#include <QGraphicsSceneMouseEvent>
#include "board.h"

class MainWindow;


class GUITile : public QObject, public QGraphicsRectItem {/**inheriting from QObject and QGraphicsRectItem*/
Q_OBJECT
public:
    GUITile(int x, int y, int height, int width, int val, MainWindow *t,  QGraphicsScene *scene);/**constructor passing in relevent/appropriate stuff*/
    void moveTile(Board *b, int tile, int size);/**performs the moving of the tile*/
    void mousePressEvent(QGraphicsSceneMouseEvent *event);/**handles tiles being clicked on*/
    MainWindow *gui;/**makes mainwindow accessible to GUITile class*/
    int number;/**value of the number*/
    QGraphicsSimpleTextItem *num;/**displays the actual number*/
    bool exists(int tile);/**checks if the tile shown exists*/
    QTimer *timer;/**timer to do animation stuff*/
    
private:
	
public slots:
	void handleTimer();
};
#endif
