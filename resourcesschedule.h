#ifndef RESOURCESSCHEDULE_H
#define RESOURCESSCHEDULE_H

#include <qwt_plot_canvas.h>
#include <qwt_plot_grid.h>
#include <qwt_plot_curve.h>
#include <qwt_plot_zoomer.h>

#include <QWidget>

namespace Ui {
    class ResourcesSchedule;
}

class ResourcesSchedule : public QWidget {
    Q_OBJECT
public:
    ResourcesSchedule(QWidget *parent = 0);
    ~ResourcesSchedule();

protected:
    void changeEvent(QEvent *e);
    void updateVEList();
    void updateResourceList();
    QTimer *timer;
    QwtPlotZoomer *zoom;
    QwtPlotGrid *grid;
    QwtPlotCurve *curve;
    double getMaxVal();
    double getCurVal();

private:
    Ui::ResourcesSchedule *ui;
    const size_t timeLim;
    double* X;
    double* Y;
    size_t currentTime;
    int refreshTimer;

private slots:
    void repaintSchedule();
    void on_VEBox_currentIndexChanged();
    void on_ResourceBox_currentIndexChanged();
    void on_StartButton_pressed();
    void on_StopButton_pressed();
};

#endif // RESOURCESSCHEDULE_H
