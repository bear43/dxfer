#ifndef DXFPARSER_H
#define DXFPARSER_H

#include <libdxfrw0/libdxfrw.h>
#include <iostream>
#include <QtCore>
#include "dxfdatacontainerimpl.h"


class DXFParser : public DRW_Interface
{
private:
    std::vector<DRW_Polyline*> polylineList;
    std::vector<DRW_LWPolyline*> lwpolylineList;
    std::vector<DRW_Circle*> circleList;
public:
    DXFParser();

    // DRW_Interface interface
public:
    void addHeader(const DRW_Header *data) override;
    void addLType(const DRW_LType &data) override;
    void addLayer(const DRW_Layer &data) override;
    void addDimStyle(const DRW_Dimstyle &data) override;
    void addVport(const DRW_Vport &data) override;
    void addTextStyle(const DRW_Textstyle &data) override;
    void addAppId(const DRW_AppId &data) override;
    void addBlock(const DRW_Block &data) override;
    void setBlock(const int handle) override;
    void endBlock() override;
    void addPoint(const DRW_Point &data) override;
    void addLine(const DRW_Line &data) override;
    void addRay(const DRW_Ray &data) override;
    void addXline(const DRW_Xline &data) override;
    void addArc(const DRW_Arc &data) override;
    void addCircle(const DRW_Circle &data) override;
    void addEllipse(const DRW_Ellipse &data) override;
    void addLWPolyline(const DRW_LWPolyline &data) override;
    void addPolyline(const DRW_Polyline &data) override;
    void addSpline(const DRW_Spline *data) override;
    void addKnot(const DRW_Entity &data) override;
    void addInsert(const DRW_Insert &data) override;
    void addTrace(const DRW_Trace &data) override;
    void add3dFace(const DRW_3Dface &data) override;
    void addSolid(const DRW_Solid &data) override;
    void addMText(const DRW_MText &data) override;
    void addText(const DRW_Text &data) override;
    void addDimAlign(const DRW_DimAligned *data) override;
    void addDimLinear(const DRW_DimLinear *data) override;
    void addDimRadial(const DRW_DimRadial *data) override;
    void addDimDiametric(const DRW_DimDiametric *data) override;
    void addDimAngular(const DRW_DimAngular *data) override;
    void addDimAngular3P(const DRW_DimAngular3p *data) override;
    void addDimOrdinate(const DRW_DimOrdinate *data) override;
    void addLeader(const DRW_Leader *data) override;
    void addHatch(const DRW_Hatch *data) override;
    void addViewport(const DRW_Viewport &data) override;
    void addImage(const DRW_Image *data) override;
    void linkImage(const DRW_ImageDef *data) override;
    void addComment(const char *comment) override;
    void writeHeader(DRW_Header &data) override;
    void writeBlocks() override;
    void writeBlockRecords() override;
    void writeEntities() override;
    void writeLTypes() override;
    void writeLayers() override;
    void writeTextstyles() override;
    void writeVports() override;
    void writeDimstyles() override;
    void writeAppId() override;
    bool ReadDXF(std::string& filename);
    bool ReadDXF(QString& filename);
    bool ReadDXF(const char* filename);
    void FillContainer(DXFDataContainerImpl* pDataContainer);
    std::vector<DRW_Polyline*> GetPolylines();
    std::vector<DRW_LWPolyline*> GetLWPolylines();
    std::vector<DRW_Circle*> GetCircles();
};

#endif // DXFParser_H
