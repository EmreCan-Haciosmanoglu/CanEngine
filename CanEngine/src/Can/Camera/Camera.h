#pragma once
#include "Can/Core.h"
namespace Can::Camera
{
	class Camera
	{
	protected:
		Camera() {}
		virtual ~Camera() {}
	public:
		const v3& GetPosition() const { return m_Position; }
		void SetPosition(const v3& position) { m_Position = position; RecalculateViewMatrix(); }

		const v3& GetRotation() const { return m_Rotation; }
		void SetRotation(const v3& rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		const m4& GetViewMatrix() const { return view; }
		const m4& GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

	protected:
		v3 m_Position{ 0.0f, 0.0f, 0.0f };
		v3 m_Rotation{ 0.0f, 0.0f, 0.0f };
		m4 view = m4(1.0f);
		m4 m_ViewProjectionMatrix;
		m4 m_ProjectionMatrix;

	private:
		void RecalculateViewMatrix();
	};

	class Perspective : public Camera
	{
	public:
		Perspective();
		virtual ~Perspective() override {}

		void Turn();

	private:
		v3 cameraTarget;
		v3 cameraDirection;
		v3 up;
		v3 cameraRight;
		v3 cameraUp;
	};

	class OrthographicCamera : public Camera
	{
	public:
		OrthographicCamera(f32 left, f32 right, f32 bottom, f32 top, f32 n = -1.0f, f32 f = 1.0f);
		void SetProjection(f32 left, f32 right, f32 bottom, f32 top, f32 n = -1.0f, f32 f = 1.0f);

		virtual ~OrthographicCamera() {}

		const m4& GetProjectionMatrix() const { return m_ProjectionMatrix; }
	private:
		void RecalculateViewMatrix();

	private:

		v3 m_Position{ 0.0f, 0.0f, 0.0f };
		v3 m_Rotation{ 0.0f, 0.0f, 0.0f };
	};

}
