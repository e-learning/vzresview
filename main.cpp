#include <QtGui/QApplication>
#include "resourcesschedule.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ResourcesSchedule w;
    w.show();
    return a.exec();
}
