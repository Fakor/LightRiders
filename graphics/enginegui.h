#ifndef GRIDBOARDGUI_H
#define GRIDBOARDGUI_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

#include "../static/standard_definitions.h"
#include "../static/engine.h"
#include "../static/simple_agents.h"

namespace graph{

    class EngineGUI: public QWidget
    {
        Q_OBJECT
    public:
        EngineGUI(QSize set_size, QWidget *parent, standard::Agent_S* a0, standard::Agent_S* a1);
    private:
        standard::Engine engine_;
    };

}

#endif // GRIDBOARDGUI_H
