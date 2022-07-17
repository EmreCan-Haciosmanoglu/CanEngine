#include "canpch.h"

#include "MacOSWindow.h"

#include "Can/Events/KeyEvent.h"
#include "Can/Events/MouseEvent.h"
#include "Can/Events/ApplicationEvent.h"

#include "Can/Input.h"

#include "Can/Renderer/Renderer.h"

#include "Platform/OpenGl/OpenGLContext.h"


namespace Can
{
Scope<Window> Window::Create(const WindowProps& props)
{
    return CreateScope<Platform::MacOS::MacOSWindow>(props);
}
}
namespace Can::Platform::MacOS
{
static uint8_t s_GLFWWindowCount = 0;

static void GLFWErrorCallback(int error, const char* message)
{
    printf("GLFW Error (%d): %s", error, message);
}

MacOSWindow::MacOSWindow(const WindowProps& props)
{
    Init(props);
}

MacOSWindow::~MacOSWindow()
{
    ShutDown();
}

void MacOSWindow::Init(const WindowProps& props)
{
    m_Data.Title = props.Title;
    m_Data.Width = props.Width;
    m_Data.Height = props.Height;
    
    printf("Creating window %s (%d, %d)\n", props.Title.c_str(), props.Width, props.Height);
    
    
    if (s_GLFWWindowCount == 0)
    {
        printf("Initializing GLFW\n");
        int success = glfwInit();
        //glfwWindowHint(GLFW_SAMPLES, 4);
        assert(success);
        glfwSetErrorCallback(GLFWErrorCallback);
    }
    
#if defined(CAN_DEBUG)
    if (Renderer::GetAPI() == RendererAPI::API::OpenGL)
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr/*glfwGetPrimaryMonitor()*/, nullptr);
    ++s_GLFWWindowCount;
    
    
    m_Context = CreateScope<OpenGLContext>(m_Window);
    m_Context->Init();
    
    glfwSetWindowUserPointer(m_Window, &m_Data);
    SetVSync(true);
    
    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
                              {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        data.Width = width;
        data.Height = height;
        
        Event::WindowResizeEvent event(width, height);
        data.EventCallback(event);
    });
    
    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
                               {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        Event::WindowCloseEvent event;
        data.EventCallback(event);
    });
    
    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
                       {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        
        switch (action)
        {
            case GLFW_PRESS:
            {
                Event::KeyPressedEvent event(static_cast<KeyCode>(key), 0);
                data.EventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                Event::KeyReleasedEvent event(static_cast<KeyCode>(key));
                data.EventCallback(event);
                break;
            }
            case GLFW_REPEAT:
            {
                Event::KeyPressedEvent event(static_cast<KeyCode>(key), 1);
                data.EventCallback(event);
                break;
            }
        }
    });
    
    glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
                        {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        Event::KeyTypedEvent event(static_cast<KeyCode>(keycode));
        data.EventCallback(event);
    });
    
    glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
                               {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        
        switch (action)
        {
            case GLFW_PRESS:
            {
                Event::MouseButtonPressedEvent event(static_cast<MouseCode>(button));
                data.EventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                Event::MouseButtonReleasedEvent event(static_cast<MouseCode>(button));
                data.EventCallback(event);
                break;
            }
        }
    });
    
    glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xScroll, double yScroll)
                          {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        
        Event::MouseScrolledEvent event((float)xScroll, (float)yScroll);
        data.EventCallback(event);
    });
    
    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
                             {
        WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
        
        Event::MouseMovedEvent event((float)xPos, (float)yPos);
        data.EventCallback(event);
    });
}

void MacOSWindow::ShutDown()
{
    glfwDestroyWindow(m_Window);
    s_GLFWWindowCount -= 1;
    
    if (s_GLFWWindowCount == 0)
    {
        printf("Terminating GLFW\n");
        glfwTerminate();
    }
}

void MacOSWindow::OnUpdate()
{
    glfwPollEvents();
    m_Context->SwapBuffers();
}

void MacOSWindow::SetVSync(bool enabled)
{
    glfwSwapInterval(enabled ? 1 : 0);
    m_Data.VSync = enabled;
}

bool MacOSWindow::IsVSync() const
{
    return m_Data.VSync;
}

void MacOSWindow::set_resolution(u32 width, u32 height)
{
    glfwSetWindowSize(m_Window, width, height);
}

}
