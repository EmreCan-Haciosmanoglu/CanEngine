#pragma once

#include "Event.h"
#include "Can/Input.h"

namespace Can::Event
{
	class  KeyEvent : public Event
	{
	public:
		inline KeyCode GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(KeyCode  keycode)
			:m_KeyCode(keycode) {}
		KeyCode  m_KeyCode;
	};

	class  KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode  keycode,int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}
		
		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}
        
        static EventType GetStaticType()
        {
            return EventType::KeyPressed;
        }
        virtual EventType GetEventType() const override
        {
            return GetStaticType();
            
        }
        virtual const char* GetName() const override
        {
            return "KeyPressed";
        }
	private:
		int m_RepeatCount;
	};

	class  KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(KeyCode  keycode)
			:KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}
        
        static EventType GetStaticType()
        {
            return EventType::KeyReleased;
        }
        virtual EventType GetEventType() const override
        {
            return GetStaticType();
            
        }
        virtual const char* GetName() const override
        {
            return "KeyReleased";
        }
	};

	class  KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(KeyCode  keycode)
			: KeyEvent(keycode){}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << m_KeyCode;
			return ss.str();
		}
        
        static EventType GetStaticType()
        {
            return EventType::KeyTyped;
        }
        virtual EventType GetEventType() const override
        {
            return GetStaticType();
            
        }
        virtual const char* GetName() const override
        {
            return "KeyTyped";
        }
	};
}
