#ifndef GUITile_H
#define GUITile_H
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <qapplication.h>
#include <QGraphicsSceneMouseEvent>
#include "board.h"

class MainWindow;


class GUITile : public QGraphicsRectItem {
public:
    GUITile(int x, int y, int height, int width, int val, MainWindow *t,  QGraphicsScene *scene);
    void moveTile(Board *b, int tile, int size);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    MainWindow *gui;
    int number;
    QGraphicsSimpleTextItem *num;
    GUITile *blank; 
    bool validMove(int size, int newsp);
private:
	
};
#endif
