#include "MainWindow.h"

namespace graph{

    MainWindow::MainWindow()
    {
        QVBoxLayout* layout = new QVBoxLayout;

        setFixedSize({500, 500});

        standard::SafeClockwiseBias_S* a0 = new standard::SafeClockwiseBias_S(base::Action::UP);
        standard::SafeClockwiseBias_S* a1 = new standard::SafeClockwiseBias_S(base::Action::DOWN);

        graph::EngineGUI* board_g = new graph::EngineGUI(size(), this, a0, a1);

        layout->addWidget(board_g);
    }


    MainWindow::~MainWindow()
    {
    }

}
