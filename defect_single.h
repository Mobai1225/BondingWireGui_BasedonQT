#ifndef DEFECT_SINGLE_H
#define DEFECT_SINGLE_H

#include <QWidget>

namespace Ui {
class defect_single;
}

class defect_single : public QWidget
{
    Q_OBJECT

public:
    explicit defect_single(QWidget *parent = nullptr);
    ~defect_single();

private:
    Ui::defect_single *ui;
};

#endif // DEFECT_SINGLE_H
