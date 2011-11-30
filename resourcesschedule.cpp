#include "resourcesschedule.h"
#include "ui_resourcesschedule.h"

#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>

#include <QTimer>

ResourcesSchedule::ResourcesSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ResourcesSchedule),
    timeLim(180),
    refreshTimer(1000)
{
    ui->setupUi(this);

    X = new double[timeLim];
    Y = new double[timeLim];

    updateVEList();
    updateResourceList();

    //Накладываем сетку
    grid = new QwtPlotGrid;
    grid->enableXMin(true);
    grid->setMajPen(QPen(Qt::black,0,Qt::DotLine));
    grid->setMinPen(QPen(Qt::gray,0,Qt::DotLine));
    grid->attach(ui->schedulePlot);
    //Наименование x и y
    ui->schedulePlot->setAxisTitle(QwtPlot::xBottom,QString::fromLocal8Bit("Time (sec)"));
    ui->schedulePlot->setAxisScale(QwtPlot::xBottom,-0.25,(timeLim+0.25));
    ui->schedulePlot->setAxisTitle(QwtPlot::yLeft,QString::fromLocal8Bit("Values"));
    ui->schedulePlot->setAxisScale(QwtPlot::yLeft,-0.25,(getMaxVal()+0.25));
    // Моя кривая
    curve = new QwtPlotCurve(QString("Curve"));
    //Zoom
    zoom = new QwtPlotZoomer(ui->schedulePlot->canvas());
    zoom->setRubberBandPen(QPen(Qt::white));
    //назначаем тип курсора для канвы графика (значение по умолчанию Qt::CrossCursor)
    ui->schedulePlot->canvas()->setCursor(Qt::ArrowCursor);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(repaintSchedule()));
    timer->start(refreshTimer);

    /* initialize random seed: */
      srand ( time(NULL) );
}

ResourcesSchedule::~ResourcesSchedule()
{
    timer->stop();
    delete timer;
    delete[] X;
    delete[] Y;
    delete grid;
    delete curve;
    delete zoom;
    delete ui;
}

void ResourcesSchedule::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void ResourcesSchedule::updateVEList()
{
    DIR * procDir;
    struct dirent * entry;

    procDir = opendir("/proc/bc");
        if (!procDir){
            std::cerr << "ERROR! Can't read proc directory(((\n" << std::endl;
        } else {
            while ((entry = readdir(procDir))) {
                if(entry->d_name) {
                    if ( !strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..") || !strcmp(entry->d_name, "resources") )
                             continue;
                    ui->VEBox->addItem(entry->d_name,NULL);
                }
            }
        }
        closedir(procDir);
}

void ResourcesSchedule::updateResourceList()
{
    std::string line;
    std::ifstream myfile("/proc/bc/0/resources");
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            myfile >> line;
            if (line.length()>1)
                ui->ResourceBox->addItem(line.c_str(),NULL);
            for ( size_t i(0); i < 5; i++ )
                myfile >> line;
        }
        myfile.close();
    }
    else std::cerr << "Unable to open file" << std::endl;
}

void ResourcesSchedule::repaintSchedule()
{
    if (currentTime<=timeLim)
    {
        for(size_t i=0; i < currentTime; i++)
            X[i]--;
        X[currentTime]=timeLim;

        Y[currentTime] = getCurVal();

        currentTime++;
    }
    else
    {
        for(size_t i=0; i < currentTime; i++)
            Y[i]=Y[i+1];

        Y[currentTime] = getCurVal();
    }
    //Далее, передаем кривым подготовленные данные
    curve->setData(X,Y,currentTime);

    //Помещаем кривые на график
    curve->attach(ui->schedulePlot);

    //Перестраиваем график
    ui->schedulePlot->replot();
}

void ResourcesSchedule::on_VEBox_currentIndexChanged()
{
    ui->schedulePlot->setAxisScale(QwtPlot::yLeft,-0.25,(getMaxVal()+0.25));
    currentTime=0;
}

void ResourcesSchedule::on_ResourceBox_currentIndexChanged()
{
    ui->schedulePlot->setAxisScale(QwtPlot::yLeft,-0.25,(getMaxVal()+0.25));
    currentTime=0;
}

double ResourcesSchedule::getMaxVal()
{
    std::string fileName,param,line;
    double maxVal=-1;
    fileName = "/proc/bc/";
    fileName += ui->VEBox->currentText().toStdString();
    fileName += "/resources";
    param = ui->ResourceBox->currentText().toStdString();
    std::ifstream myfile(fileName.c_str());
    if (param.length())
    {
        if (myfile.is_open())
        {
            while ( myfile.good() && ( maxVal < 0 ) )
            {
                myfile >> line;
                if ( !line.compare(param) )
                    for ( size_t i(0); i < 3; i++ )
                        myfile >> maxVal;
                else
                    for ( size_t i(0); i < 5; i++ )
                        myfile >> line;
            }
            myfile.close();
        }
        else std::cerr << "Unable to open file" << std::endl;
    }
    return maxVal;
}

double ResourcesSchedule::getCurVal()
{
    std::string fileName,param,line;
    double curVal=-1;
    fileName = "/proc/bc/";
    fileName += ui->VEBox->currentText().toStdString();
    fileName += "/resources";
    param = ui->ResourceBox->currentText().toStdString();
    std::ifstream myfile(fileName.c_str());
    if (param.length())
    {
        if (myfile.is_open())
        {
            while ( myfile.good() && ( curVal < 0 ) )
            {
                myfile >> line;
                if ( !line.compare(param) )
                    myfile >> curVal;
                else
                    for ( size_t i(0); i < 5; i++ )
                        myfile >> line;
            }
            myfile.close();
        }
        else std::cerr << "Unable to open file" << std::endl;
    }
    return curVal;
}

void ResourcesSchedule::on_StartButton_pressed()
{
    if( ui->radioButton->isChecked() )
        refreshTimer = 500;
    else
        refreshTimer = 1000;
    timer->stop();
    timer->start(refreshTimer);
}

void ResourcesSchedule::on_StopButton_pressed()
{
    timer->stop();
}
