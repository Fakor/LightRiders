#include "gridboardgui.h"

namespace graph {

GridBoardGUI::GridBoardGUI(standard::GridBoard_S* board, QSize set_size, QWidget *parent)
    : QWidget (parent),
      board_{board}
{
    setFixedSize(set_size);
    QGridLayout* layout = new QGridLayout(this);

    int cell_height = size().height() / board_->GetHeight();
    int cell_width = size().width() / board_->GetWidth();

    QSize cell_size{ cell_height, cell_width };

    for (short i = 0; i < board_->GetWidth(); ++i) {
        for (short j = 0; j < board->GetHeight(); ++j) {
            QLabel* label = new QLabel;
            char v = board_->GetSquareValue(base::Position{i,j});
            label->setText(QString(v));
            layout->addWidget(label, i, j);
        }
    }
}

}
