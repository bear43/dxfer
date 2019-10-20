#ifndef DXFDATACONTAINERIMPL_H
#define DXFDATACONTAINERIMPL_H

#include "dxfdatacontainer.h"

#include <libdxfrw0/libdxfrw.h>
#include "ui_mainwindow.h"

class DXFDataContainerImpl : public DXFDataContainer
{
private:
    std::vector<DRW_Polyline*> polylineList;
    std::vector<DRW_LWPolyline*> lwpolylineList;
    std::vector<DRW_Circle*> circleList;
public:
    DXFDataContainerImpl();
    virtual ~DXFDataContainerImpl();

    // DXFDataContainer interface
public:
    std::vector<vertex> GetVertices() override;
    std::vector<vertex> GetNormals() override;
    void SetPolylines(std::vector<DRW_Polyline*>& data);
    void SetLWPolylines(std::vector<DRW_LWPolyline*>& data);
    void SetCircles(std::vector<DRW_Circle*>& data);
    void FillUIInfo(Ui::MainWindow* ui);
};

#endif // DXFDATACONTAINERIMPL_H
