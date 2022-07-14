#include "canpch.h"
#include "MetalRendererAPI.h"

namespace Can
{

void MetalRendererAPI::Init() {}
void MetalRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)  {}
void MetalRendererAPI::SetClearColor(const v4& color) {}
void MetalRendererAPI::Clear()  {}

void MetalRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray)  {}
void MetalRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount ) {}

void MetalRendererAPI::enable_depth_testing(bool enable) {}
}
