#include "MainWindow.h"

namespace graph{

    MainWindow::MainWindow()
    {
        QVBoxLayout* layout = new QVBoxLayout;

        standard::GridBoard_S board;

        board.Reset({2,2}, {3,4});

        setFixedSize({500, 500});

        graph::GridBoardGUI* board_g = new graph::GridBoardGUI(&board, size(), this);

        layout->addWidget(board_g);
    }


    MainWindow::~MainWindow()
    {
    }

}
