#ifndef MacOSWindow_h
#define MacOSWindow_h

#include "Can/Window.h"
#include "Can/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>


namespace Can::Platform::MacOS
{
    class  MacOSWindow : public Window
    {
    public:
        MacOSWindow(const WindowProps& props);
        virtual ~MacOSWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;
        inline void* GetNativeWindow() const override { return m_Window; }

        void set_resolution(u32 width, u32 height) override;

    private:
        virtual void Init(const WindowProps& props);
        virtual void ShutDown();
    private:
        GLFWwindow* m_Window;
        Scope<GraphicsContext> m_Context;
        struct WindowData
        {
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;
    };

}


#endif /* MacOSWindow_h */
