#pragma once

#include <QMainWindow>

#include "gridboardgui.h"

namespace graph{

    class MainWindow: public QMainWindow
    {
        Q_OBJECT
    public:
        MainWindow();
        virtual ~MainWindow();
    };

}


