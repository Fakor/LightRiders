#ifndef GRIDBOARDGUI_H
#define GRIDBOARDGUI_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

#include "../static/standard_definitions.h"

namespace graph{

    class GridBoardGUI: public QWidget
    {
        Q_OBJECT
    public:
        GridBoardGUI(standard::GridBoard_S* board, QSize set_size, QWidget *parent);
    private:
        standard::GridBoard_S* board_;
    };

}

#endif // GRIDBOARDGUI_H
