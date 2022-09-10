#pragma once

#include "MyHazel.h"

class ExampleLayer : public MyHazel::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(MyHazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(MyHazel::Event& e) override;
private:
	MyHazel::ShaderLibrary m_ShaderLibrary;
	MyHazel::Ref<MyHazel::Shader> m_Shader;
	MyHazel::Ref<MyHazel::VertexArray> m_VertexArray;

	MyHazel::Ref<MyHazel::Shader> m_FlatColorShader;
	MyHazel::Ref<MyHazel::VertexArray> m_SquareVA;

	MyHazel::Ref<MyHazel::Texture2D> m_Texture, m_ChernoLogoTexture;

	MyHazel::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};