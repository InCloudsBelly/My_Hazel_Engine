#pragma once
#include "MyHazel.h"

class Sandbox2D :public MyHazel::Layer
{
public:

	Sandbox2D();
	virtual ~Sandbox2D() = default;
	 
	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(MyHazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(MyHazel::Event& e)override;


private:
	MyHazel::OrthographicCameraController m_CameraController;

	MyHazel::Ref<MyHazel::VertexArray> m_SquareVA;
	MyHazel::Ref<MyHazel::Shader> m_FlatColorShader;
	MyHazel::Ref<MyHazel::Texture2D> m_Texture;

	glm::vec4 m_SquareColor = { 0.2,0.3,0.8,1.0f };
};
