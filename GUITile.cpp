#include "GUITile.h"
#include <iostream>
#include <string>
#include <QString>
#include <cmath>
#include "mainwindow.h"

/** GUITile class used to make a Graphical user interface. inherits from
*QGraphicsRectItem 
* @author Haley Lenner
* @param none
*/
using namespace std;

/**constructor for creating necessary objects going in the view of the GUI.

@pre must have a main class creating mainwindow object to perform all actions
@post creates buttons, timer, layouts, lineedits, and sets the geometry/texts
@param x location, y location, height, width, and value of the tile. mainwindow
the tile exists in, and the scene. inherits from QGraphicsRectItem
@return none
*/
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
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));

}
/**Method called when the user clicks on a tile.

@pre event is clicking a specific tile
@post calls to MainWindowMoveTile giving the GuiTile and number as parameters 
so it can call moveTile
@param QGraphicsSceneMouseEvent event, clicking the tile
@return none
*/
void GUITile::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        //timer->start();
        gui->MainWindowmoveTile(number, this);
    }
}
/**method for finding out if a specific tile has a value of 0

@pre must have a main class creating mainwindow object to perform all actions
@post find out if the tile has a value of 0
@param tile
@return boolean true if it is not 0, false if it is 0
*/
bool GUITile::exists(int tile) {
    if (gui->tiles->at(tile)!=0) {
        // cout << "not 0" << endl;
        return true;
    }
    return false;
}
/**Slot for attempting to animate, created to handle the timer info.

@pre None
@post moves tile specific amount before stopping at the final position
@param none
@return none
*/
void GUITile::handleTimer() {
    /*//counter++;
    //cout << "counter: " <<counter<<  endl;
    //if (this->pos() == goalpos){
    //	timer->stop();
    //}
    moveTile(bb, number, size);*/
}
/**Method for internally moving the tile and getting the tile to move on the screen.

@pre tile must be next to empty space in order to move
@post moves tile 
@param board pointer, tile number being moved, size of the board
@return none
*/
void GUITile::moveTile(Board *b, int tile, int size) {
    
    cout << endl;
    int *x = b->getTiles();
    int dim = sqrt(size);
    cout <<"Board *tiles before move: ";
    for (int i=0; i<size; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    // cout << "Tile: " << tile << endl;
    if (b->move(tile)==true) {
        int index=0;
        int cols=sqrt(size);
        for (int i=0; i<size; i++) {
            if (gui->tiles->at(i)==this) {
                index = i;
                break;
            }
        }
        if ((index-cols)>=0 && gui->tiles->at(index-dim)->number==0) {
            cout << "up" << endl;
            this->moveBy(0, -50);
            num->moveBy(0, -50);
            GUITile *temp;
            temp=gui->tiles->at(index-cols);
            gui->tiles->at(index-cols)=gui->tiles->at(index);
            gui->tiles->at(index)=temp;
        }
        else if (index % cols != 0 && gui->tiles->at(index-1)->number==0) {
            cout << "left" << endl;
            this->moveBy(-50, 0);
            num->moveBy(-50, 0);
            GUITile *temp;
            temp=gui->tiles->at(index-1);
            gui->tiles->at(index-1)=gui->tiles->at(index);
            gui->tiles->at(index)=temp;
        }
        else if((index+cols)<=(cols*cols-1) && gui->tiles->at(index+cols)->number==0) {
            cout << "down" << endl;
            this->moveBy(0, 50);
            num->moveBy(0, 50);
            GUITile *temp;
            temp=gui->tiles->at(index+cols);
            gui->tiles->at(index+cols)=gui->tiles->at(index);
            gui->tiles->at(index)=temp;
        }
        else if ((index+1) % cols !=0 && gui->tiles->at(index+1)->number==0) {
            cout << "right" << endl;
            this->moveBy(50, 0);
            num->moveBy(50, 0);
            GUITile *temp;
            temp=gui->tiles->at(index+1);
            gui->tiles->at(index+1)=gui->tiles->at(index);
            gui->tiles->at(index)=temp;
        }
       }
cout <<"Board *tiles after move: ";
    for (int i=1; i<size; i++) {
        cout << x[i] << " ";
    }
        for (int i=0; i<size; i++) {
            if (gui->tiles->at(i)->number==i) {
                if(i==size) {
                cout << "Sizzzzze" << endl;
                    QMessageBox *win = new QMessageBox();
                    win->setText("You win!");
                    win->show();
                }
            }
            else {
            	cout << "break" << endl;
                break;
            }
        }
    }
