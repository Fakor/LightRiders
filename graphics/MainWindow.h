#pragma once

#include <QMainWindow>

#include "enginegui.h"
#include "keyboardagent.h"

namespace graph{

    class MainWindow: public QMainWindow
    {
        Q_OBJECT
    public:
        MainWindow();
        virtual ~MainWindow();
    };

}


