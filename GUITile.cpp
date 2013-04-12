#include "GUITile.h"
#include <iostream>
#include <string>
#include <QString>
#include <cmath>
#include "mainwindow.h"

using namespace std;
GUITile::GUITile(int x, int y, int height, int width, int val, MainWindow *t, QGraphicsScene *scene): QGraphicsRectItem(x, y, height, width) {
    QString newstring = QString::number(val);
    if (val == 0) {
        newstring = "";
    }
    QGraphicsSimpleTextItem *c= new QGraphicsSimpleTextItem();
    c->setText(newstring);
    c->setPos(x+width/2, y+height/2);
    scene->addItem(c);
    gui=t;
    number=val;
    num=c;
}
void GUITile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        gui->MainWindowmoveTile(number, this);
    }
}
bool GUITile::validMove(int size, int newsp){

		if (NULL != gui->tiles->at(newsp)){
		return false;
		}
	return true; 
}
void GUITile::moveTile( Board *b, int tile, int size) {
    
    cout << endl;
    int *x = b->getTiles();
    cout <<"Board *tiles after move: ";
    for (int i=0; i<size; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    //cout << "NUM: " << num->text().toStdString()<< endl;
    cout << "Tile: " << tile << endl;
    if (b->move(tile)==true) {
    cout << "hi" << endl;
        int index=0;
        int cols=sqrt(size);
        for (int i=0; i<size; i++) {
            if (gui->tiles->at(i)==this) {
                index = i;
                break;
            }
        }
        if ((index-cols)>=0 && validMove(size, index-cols)==true) {
            cout << "up" << endl;
            this->moveBy(0, -50);
            num->moveBy(0, -50);
            GUITile *temp;
            temp=gui->tiles->at(index-cols);
            gui->tiles->at(index-cols)=gui->tiles->at(index);
            gui->tiles->at(index)=temp;
        }
        else if (index % cols != 0 && validMove(size, index%cols)==true) {
            cout << "left" << endl;
            this->moveBy(-50, 0);
            num->moveBy(-50, 0);
            GUITile *temp;
            temp=gui->tiles->at(index-1);
            gui->tiles->at(index-1)=gui->tiles->at(index);
            gui->tiles->at(index)=temp;
        }
        else if((index+cols)<=(cols*cols-1) && validMove(size, index+cols)==true) {
            cout << "down" << endl;
            this->moveBy(0, 50);
            num->moveBy(0, 50);
            GUITile *temp;
            temp=gui->tiles->at(index+cols);
            gui->tiles->at(index+cols)=gui->tiles->at(index);
            gui->tiles->at(index)=temp;
            
        }
        else if ((index+1) % cols !=0 && validMove(size, index+1)==true) {
            cout << "right" << endl;
            this->moveBy(50, 0);
            num->moveBy(50, 0);
            GUITile *temp;
            temp=gui->tiles->at(index+1);
            gui->tiles->at(index+1)=gui->tiles->at(index);
            gui->tiles->at(index)=temp;
        }
        gui->tiles->at(index)=NULL;
    }

}
