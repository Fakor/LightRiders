#include "MainWindow.h"

namespace graph{

    MainWindow::MainWindow()
    {
        QVBoxLayout* layout = new QVBoxLayout;

        setFixedSize({500, 500});
        long seed = std::chrono::system_clock::now().time_since_epoch().count();
        KeyboardAgent* a0 = new KeyboardAgent();
        standard::RandomSafeAgent_S* a1 = new standard::RandomSafeAgent_S(static_cast<unsigned int>(seed));

        graph::EngineGUI* board_g = new graph::EngineGUI(size(), this, a0, a1);

        layout->addWidget(board_g);
    }


    MainWindow::~MainWindow()
    {
    }

}
