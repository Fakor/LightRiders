#include "enginegui.h"

namespace graph {

EngineGUI::EngineGUI(QSize set_size, QWidget *parent, standard::Agent_S* a0, standard::Agent_S* a1)
    : QWidget (parent),
      engine_(a0, a1)
{
    setFixedSize(set_size);
    QGridLayout* layout = new QGridLayout(this);

    int cell_height = size().height() / standard::HEIGHT;
    int cell_width = size().width() / standard::WIDTH;

    QSize cell_size{ cell_height, cell_width };

    engine_.Reset({4,6});
    for (short i = 0; i < standard::HEIGHT; ++i) {
        for (short j = 0; j < standard::WIDTH; ++j) {
            SquareGUI* square = new SquareGUI({j,i}, engine_.GetStatusPtr());
            layout->addWidget(square, i, j);
            connect(this, SIGNAL(Update()), square, SLOT(Update()));
        }
    }
    Update();

    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TurnAndUpdate()));
    timer->start(500);
}

void EngineGUI::keyPressEvent(QKeyEvent *event){
    int input_char = event->key();
    qDebug() << "Input character " << input_char;
    if(input_char == Qt::Key_Space){
        engine_.PerformTurn();
        Update();
    }
}

void EngineGUI::TurnAndUpdate(){
    engine_.PerformTurn();
    Update();
}

}
