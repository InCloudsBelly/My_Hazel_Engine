
#include "Sandbox2D.h"

#include <ImGui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>




Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	HZ_PROFILE_FUNCTION();

	m_Texture = MyHazel::Texture2D::Create("assets/textures/brickwall.jpg");

}

void Sandbox2D::OnDetach()
{
	HZ_PROFILE_FUNCTION();

}

void Sandbox2D::OnUpdate(MyHazel::Timestep ts)
{

	HZ_PROFILE_FUNCTION();
	// Update
	{
		m_CameraController.OnUpdate(ts);
	}


	// Render
	MyHazel::Renderer2D::ResetStats();
	{
		HZ_PROFILE_SCOPE("Renderer Prep");
		MyHazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		MyHazel::RenderCommand::Clear();
	}

	{
		static float rotation = 0;

		rotation += ts * 50.0f;

		HZ_PROFILE_SCOPE("Renderer Draw");
		MyHazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
		MyHazel::Renderer2D::DrawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		MyHazel::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		MyHazel::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_ImGUIColor);
		MyHazel::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_Texture, 10.0f);
		MyHazel::Renderer2D::DrawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_Texture, 20.0f);
		MyHazel::Renderer2D::EndScene();
	}

	MyHazel::Renderer2D::BeginScene(m_CameraController.GetCamera());
	for (float y = -5.0f; y < 5.0f; y += 0.5f)
	{
		for (float x = -5.0f; x < 5.0f; x += 0.5f)
		{
			glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
			MyHazel::Renderer2D::DrawQuad({ x,y }, { 0.45f,0.45f }, color);
		}
	}
	MyHazel::Renderer2D::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	HZ_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

	auto stats = MyHazel::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_ImGUIColor));
	ImGui::End();
}


void Sandbox2D::OnEvent(MyHazel::Event& e)
{
	m_CameraController.OnEvent(e);
}