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
            QLabel* label = new QLabel;
            char v = engine_.GetStatus().GetElement(base::Position{j,i});
            label->setText(QString(v));
            layout->addWidget(label, i, j);
        }
    }
}

}
