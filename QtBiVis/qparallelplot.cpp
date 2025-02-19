#include "qparallelplot.h"
#include <limits>
qParallelPlot::qParallelPlot()
{
    resize(400,400);
    setWindowTitle(tr("Parallel Coordinates"));
    plot->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
    plot->axisRect()->setRangeZoom(Qt::Vertical|Qt::Horizontal);
}
void qParallelPlot::setData()
{

}
void qParallelPlot::setData(QList<QStringList> *values, QString Bicluster, QCPRange range)
{
    QStringList split = Bicluster.split("|");
    QString tempRows = split[0];
    QString tempCols = split[1];
    QStringList rows = tempRows.split(QRegExp("\\s+"));
    rows.removeAll("");
    QStringList cols = tempCols.split(QRegExp("\\s+"));
    cols.removeAll("");

    plot->xAxis->setLabel("Cols");
    plot->yAxis->setLabel("Values");
    plot->xAxis->setNumberFormat("f");
    plot->xAxis->setNumberPrecision(0);
    //plot->axisRect()->setRangeZoom(Qt::Vertical);
    double min, max,maxx, minx;
    min=INT_MAX; max=0;maxx=0;minx=INT_MAX;
    for(int i=0; i<rows.size();i++)
    {
        plot->addGraph(plot->xAxis,plot->yAxis);
        QVector<double> x(cols.size());
        QVector<double> y(cols.size());
        for(int j=0;j<cols.size();j++)
        {
            x[j]=cols.at(j).toInt();
            y[j]=(*values)[rows.at(i).toInt()].at(cols.at(j).toInt()).toDouble();
            if(y[j]<min)
                min=y[j];
            if(y[j]>max)
                max=y[j];
            if(x[j]>maxx)
                maxx=x[j];
            if(x[j]<minx)
                minx=x[j];
        }
        plot->graph(i)->setData(x,y);
    }
    plot->xAxis->setRange(minx, maxx);
    plot->yAxis->setRange(min,max);
}

