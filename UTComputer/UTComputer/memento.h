#ifndef MEMENTO_H
#define MEMENTO_H

#include "stack.h"

class Memento {
private:
    friend class Stack;
    QStack<Literal*> state;
public:
    Memento(QStack <Literal*> l){
        state = l;
    }
};

//class Command {

//public:
//    typedef void (Stack:: * Action)();
//    Command (Stack* rec, Action act){
//        receiver= rec;
//        action= act;
//    }
//    virtual void execute()
//    {
//        mementoList[numCommand]= receiver->createMemento();
//        commandList[numCommand]=this;
//        if(numCommand>highWater)
//            highWater=numCommand;
//        numCommand++;
//        (receiver->*action)();
//    }
//    static void undo(){
//        if (numCommand == 0)
//            throw("Effectuez une action avant de sauvegarder!");
//        else{
//            commandList[numCommand - 1]->receiver->reinstateMemento(mementoList[numCommand - 1]);
//            numCommand--;
//        }

//    }
//    static void redo(){
//        if(numCommand>higWater)
//            throw("Il faut d'abord undo avant de redo!");
//        else{
//            (commandList [numCommand]->receiver->*(commandList[numCommand]->action))();
//            numCommand++;
//        }
//    }
//protected:
//    Stack* receiver;
//    Action action;
//    static Command * commandList[2];
//    static Memento * mementoList[2];
//    static int numCommand;
//    static int highWater;
//};


#endif // MEMENTO_H
