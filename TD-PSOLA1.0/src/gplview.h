#ifndef GPLVIEW_H
#define GPLVIEW_H

#include <QDialog>

namespace Ui {
class GPLView;
}

class GPLView : public QDialog
{
    Q_OBJECT

public:
    explicit GPLView(QWidget *parent = nullptr);
    ~GPLView();

private:
    Ui::GPLView *ui;
};

#endif // GPLVIEW_H
