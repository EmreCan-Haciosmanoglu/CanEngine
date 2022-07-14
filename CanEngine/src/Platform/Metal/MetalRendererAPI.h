#ifndef METAL_RENDERER_API
#define METAL_RENDERER_API
#include "Can/Core.h"
#include "Can/Renderer/RendererAPI.h"

namespace Can
{
    class MetalRendererAPI : public RendererAPI
    {
    public:
        virtual void Init() override;
        virtual void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
        virtual void SetClearColor(const v4& color) override;
        virtual void Clear() override;

        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) override;
        virtual void DrawIndexed(const Ref<VertexArray>& vertexArray, uint32_t indexCount ) override;

        virtual void enable_depth_testing(bool enable) override;
    };
}
#endif
