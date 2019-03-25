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
        QString value(status_->GetElement(index_));
        setText(value);
    }


}
