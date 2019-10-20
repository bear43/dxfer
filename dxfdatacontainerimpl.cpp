#include "dxfdatacontainerimpl.h"

DXFDataContainerImpl::DXFDataContainerImpl()
{

}

DXFDataContainerImpl::~DXFDataContainerImpl()
{
    for(DRW_Polyline* pPolyline : polylineList)
    {
        delete pPolyline;
    }
    for(DRW_LWPolyline* pLWPolyline : lwpolylineList)
    {
        delete pLWPolyline;
    }
    for(DRW_Circle* pCircle : circleList)
    {
        delete pCircle;
    }
}


std::vector<vertex> DXFDataContainerImpl::GetVertices()
{
    return std::vector<vertex>();
}

std::vector<vertex> DXFDataContainerImpl::GetNormals()
{
    return std::vector<vertex>();
}

void DXFDataContainerImpl::SetPolylines(std::vector<DRW_Polyline *> &data)
{
    polylineList.clear();
    polylineList.insert(polylineList.end(), data.begin(), data.end());
}

void DXFDataContainerImpl::SetLWPolylines(std::vector<DRW_LWPolyline *> &data)
{
    lwpolylineList.clear();
    lwpolylineList.insert(lwpolylineList.end(), data.begin(), data.end());
}

void DXFDataContainerImpl::SetCircles(std::vector<DRW_Circle *> &data)
{
    circleList.clear();
    circleList.insert(circleList.end(), data.begin(), data.end());
}

void DXFDataContainerImpl::FillUIInfo(Ui::MainWindow *ui)
{
   ui->labelPolylineInfo->setText(QString::number(polylineList.size()));
   ui->labelLWPolylineInfo->setText(QString::number(lwpolylineList.size()));
   ui->labelCircleInfo->setText(QString::number(circleList.size()));
}
