#include "canpch.h"
#include "MetalVertexArray.h"

namespace Can
{

MetalVertexArray::MetalVertexArray(){}
MetalVertexArray::~MetalVertexArray(){}

void MetalVertexArray::Bind() const {}
void MetalVertexArray::Unbind() const {}

void MetalVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexbuffer){}
void MetalVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexbuffer) {}

}
