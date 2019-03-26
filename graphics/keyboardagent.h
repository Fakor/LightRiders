#ifndef KEYBOARDAGENT_H
#define KEYBOARDAGENT_H

#include <QWidget>
#include <QKeyEvent>
#include <QDebug>

#include "../static/standard_definitions.h"

namespace graph {

    class KeyboardAgent: public standard::Agent_S, QWidget
    {
    public:
        KeyboardAgent();
        virtual ~KeyboardAgent() override {}
        void ChooseAction() override;
    protected:
        void keyPressEvent(QKeyEvent *event) override;
    private:
        base::Action action_;
    };
}

#endif // KEYBOARDAGENT_H
