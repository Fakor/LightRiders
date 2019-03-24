#pragma once

#include <QMainWindow>

#include "enginegui.h"

namespace graph{

    class MainWindow: public QMainWindow
    {
        Q_OBJECT
    public:
        MainWindow();
        virtual ~MainWindow();
    };

}


