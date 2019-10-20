#include "DXFParser.h"

DXFParser::DXFParser()
{

}

bool DXFParser::ReadDXF(std::string &filename)
{
    return ReadDXF(filename.c_str());
}

bool DXFParser::ReadDXF(QString &filename)
{
    return ReadDXF(filename.toUtf8().constData());
}

bool DXFParser::ReadDXF(const char *filename)
{
    dxfRW* dxf = new dxfRW(filename);
    bool result = dxf->read(this, true);
    delete dxf;
    return result;
}

void DXFParser::FillContainer(DXFDataContainerImpl *pDataContainer)
{
    pDataContainer->SetPolylines(polylineList);
    pDataContainer->SetLWPolylines(lwpolylineList);
    pDataContainer->SetCircles(circleList);
}



std::vector<DRW_Polyline *> DXFParser::GetPolylines()
{

}

std::vector<DRW_LWPolyline *> DXFParser::GetLWPolylines()
{

}

std::vector<DRW_Circle *> DXFParser::GetCircles()
{

}


void DXFParser::addHeader(const DRW_Header *data)
{
}

void DXFParser::addLType(const DRW_LType &data)
{
}

void DXFParser::addLayer(const DRW_Layer &data)
{
}

void DXFParser::addDimStyle(const DRW_Dimstyle &data)
{
}

void DXFParser::addVport(const DRW_Vport &data)
{
}

void DXFParser::addTextStyle(const DRW_Textstyle &data)
{
}

void DXFParser::addAppId(const DRW_AppId &data)
{
}

void DXFParser::addBlock(const DRW_Block &data)
{
}

void DXFParser::setBlock(const int handle)
{
}

void DXFParser::endBlock()
{
}

void DXFParser::addPoint(const DRW_Point &data)
{
}

void DXFParser::addLine(const DRW_Line &data)
{
}

void DXFParser::addRay(const DRW_Ray &data)
{
}

void DXFParser::addXline(const DRW_Xline &data)
{
}

void DXFParser::addArc(const DRW_Arc &data)
{
}

void DXFParser::addCircle(const DRW_Circle &data)
{
    DRW_Circle* pCircle = new DRW_Circle();
    *pCircle = data;
    circleList.push_back(pCircle);
}

void DXFParser::addEllipse(const DRW_Ellipse &data)
{
}

void DXFParser::addLWPolyline(const DRW_LWPolyline &data)
{
    DRW_LWPolyline* pLWPolyline = new DRW_LWPolyline();
    *pLWPolyline = data;
    lwpolylineList.push_back(pLWPolyline);
}

void DXFParser::addPolyline(const DRW_Polyline &data)
{
    DRW_Polyline* pPolyline = new DRW_Polyline();
    *pPolyline = data;
    polylineList.push_back(pPolyline);
}

void DXFParser::addSpline(const DRW_Spline *data)
{
}

void DXFParser::addKnot(const DRW_Entity &data)
{
}

void DXFParser::addInsert(const DRW_Insert &data)
{
}

void DXFParser::addTrace(const DRW_Trace &data)
{
}

void DXFParser::add3dFace(const DRW_3Dface &data)
{
}

void DXFParser::addSolid(const DRW_Solid &data)
{
}

void DXFParser::addMText(const DRW_MText &data)
{
}

void DXFParser::addText(const DRW_Text &data)
{
}

void DXFParser::addDimAlign(const DRW_DimAligned *data)
{
}

void DXFParser::addDimLinear(const DRW_DimLinear *data)
{
}

void DXFParser::addDimRadial(const DRW_DimRadial *data)
{
}

void DXFParser::addDimDiametric(const DRW_DimDiametric *data)
{
}

void DXFParser::addDimAngular(const DRW_DimAngular *data)
{
}

void DXFParser::addDimAngular3P(const DRW_DimAngular3p *data)
{
}

void DXFParser::addDimOrdinate(const DRW_DimOrdinate *data)
{
}

void DXFParser::addLeader(const DRW_Leader *data)
{
}

void DXFParser::addHatch(const DRW_Hatch *data)
{
}

void DXFParser::addViewport(const DRW_Viewport &data)
{
}

void DXFParser::addImage(const DRW_Image *data)
{
}

void DXFParser::linkImage(const DRW_ImageDef *data)
{
}

void DXFParser::addComment(const char *comment)
{
}

void DXFParser::writeHeader(DRW_Header &data)
{
}

void DXFParser::writeBlocks()
{
}

void DXFParser::writeBlockRecords()
{
}

void DXFParser::writeEntities()
{
}

void DXFParser::writeLTypes()
{
}

void DXFParser::writeLayers()
{
}

void DXFParser::writeTextstyles()
{
}

void DXFParser::writeVports()
{
}

void DXFParser::writeDimstyles()
{
}

void DXFParser::writeAppId()
{
}
