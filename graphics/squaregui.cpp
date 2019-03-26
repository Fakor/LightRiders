#include "squaregui.h"

namespace graph {

    SquareGUI::SquareGUI(base::Position position, const standard::Status_S* status)
        : status_{status}
    {
        index_ = position.Y() * standard::WIDTH + position.X();
    }

    SquareGUI::~SquareGUI(){

    }

    void SquareGUI::Update(){
        char name = status_->GetElement(index_);
        if(name == '0'){
            setStyleSheet("QLabel { color : blue; }");
        } else if(name == '1'){
            setStyleSheet("QLabel { color : red; }");
        }
        setText(QString(name));
    }


}
