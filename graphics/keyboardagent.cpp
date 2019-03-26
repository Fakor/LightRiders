#include "keyboardagent.h"

namespace graph {

    KeyboardAgent::KeyboardAgent()
    {
        grabKeyboard();
    }

    void KeyboardAgent::ChooseAction(){
        SetAction(action_);
    }

    void KeyboardAgent::keyPressEvent(QKeyEvent *event){
        int input_char = event->key();
        qDebug() << "Agent Input character " << input_char;
        if(input_char == Qt::Key_Up){
            action_ = base::Action::UP;
        } else if(input_char == Qt::Key_Down){
            action_ = base::Action::DOWN;
        } else if(input_char == Qt::Key_Left){
            action_ = base::Action::LEFT;
        } else if(input_char == Qt::Key_Right){
            action_ = base::Action::RIGHT;
        }
    }

}
