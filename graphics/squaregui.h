#ifndef SQUAREGUI_H
#define SQUAREGUI_H

#include <QLabel>

#include "../static/standard_definitions.h"

namespace graph {

    class SquareGUI: public QLabel
    {
        Q_OBJECT
    public:
        SquareGUI(base::Position position, const standard::Status_S* status);
        virtual ~SquareGUI();
    public slots:
        void Update();
    private:
        const standard::Status_S* status_;
        int index_;
    };
}

#endif // SQUAREGUI_H
