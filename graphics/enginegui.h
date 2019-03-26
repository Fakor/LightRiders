#ifndef GRIDBOARDGUI_H
#define GRIDBOARDGUI_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>

#include "squaregui.h"

#include "../static/standard_definitions.h"
#include "../static/engine.h"

namespace graph{

    class EngineGUI: public QWidget
    {
        Q_OBJECT
    public:
        EngineGUI(QSize set_size, QWidget *parent, standard::Agent_S* a0, standard::Agent_S* a1);

    protected:
        void keyPressEvent(QKeyEvent *event) override;
    signals:
        void Update();
    private:
        standard::Engine engine_;
    };

}

#endif // GRIDBOARDGUI_H
