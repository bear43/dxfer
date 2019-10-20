#ifndef DXFDATACONTAINER_H
#define DXFDATACONTAINER_H

#include <vector>

struct vertex {
    float x;
    float y;
    float z;
};

class DXFDataContainer
{
public:
    DXFDataContainer();
    virtual std::vector<vertex> GetVertices() = 0;
    virtual std::vector<vertex> GetNormals() = 0;
};

#endif // DXFDATACONTAINER_H
