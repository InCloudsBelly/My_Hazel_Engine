#include <MyHazel.h>
#include "MyHazel/Core/EntryPoint.h"

#include <imgui/imgui.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Sandbox2D.h"

class ExampleLayer :public MyHazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example"), m_CameraController(1280.0f/720.0f)
	{
		m_VertexArray = (MyHazel::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f,1.0f,0.0f,1.0f,1.0f,
			 0.5f, -0.5f, 0.0f,0.0f,0.0f,1.0f,1.0f,
			 0.0f,  0.5f, 0.0f,1.0f,1.0f,0.0f,1.0f
		};

		MyHazel::Ref<MyHazel::VertexBuffer> vertexBuffer = MyHazel::VertexBuffer::Create(vertices, sizeof(vertices));
		MyHazel::BufferLayout layout = {
			{MyHazel::ShaderDataType::Float3, "a_Position"},
			{MyHazel::ShaderDataType::Float4, "a_Color"}
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0,1,2 };
		MyHazel::Ref<MyHazel::IndexBuffer> indexBuffer = (MyHazel::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);


		/***  SquareVA  ***/

		m_SquareVA= (MyHazel::VertexArray::Create());

		float Squarevertices[4 * 5] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		MyHazel::Ref<MyHazel::VertexBuffer> squareVB = (MyHazel::VertexBuffer::Create(Squarevertices, sizeof(Squarevertices)));

		MyHazel::BufferLayout Squarelayout = {
			{MyHazel::ShaderDataType::Float3, "a_Position"},
			{MyHazel::ShaderDataType::Float2 , "a_TexCoord"}
		};
		squareVB->SetLayout(Squarelayout);
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t Squareindices[6] = { 0,1,2, 2,3,0 };
		MyHazel::Ref<MyHazel::IndexBuffer> squareIB = (MyHazel::IndexBuffer::Create(Squareindices, sizeof(Squareindices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);



		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in  vec3 a_Position;
			layout(location = 1) in  vec4 a_Color;
		
			uniform mat4 u_ViewProjection;
			uniform mat4 u_ModelMatrix;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_ModelMatrix * vec4(a_Position, 1.0);
			}
		)";

		std::string fragSrc = R"(
			#version 330 core
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main(){
				color = v_Color;
			}

		)";

		std::string vertexSrc2 = R"(
			#version 330 core

			layout(location = 0) in  vec3 a_Position;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_ModelMatrix;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_ModelMatrix* vec4(a_Position, 1.0);
			}
		)";

		std::string fragSrc2 = R"(
			#version 330 core
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			uniform vec3 u_Color;

			void main(){
				color = vec4(u_Color,1.0);
			}

		)";

		m_Shader = (MyHazel::Shader::Create("CertexColorTriangle", vertexSrc, fragSrc));
		m_SquareShader = (MyHazel::Shader::Create("FlatColor", vertexSrc2, fragSrc2));
		
		
		
		auto TextureShader = m_ShaderLibrary.load ("assets/shaders/Texture.glsl");
	
		m_Texture = (MyHazel::Texture2D::Create("assets/textures/awesomeface.png"));
		TextureShader->Bind();
		TextureShader->SetInt("u_Texture", 0);

}



	void OnUpdate(MyHazel::Timestep ts)override
	{
		//Update
		m_CameraController.OnUpdate(ts);


		//Render
		MyHazel::RenderCommand::SetClearColor({ 0.1f,0.1f,0.1f,1.0f });
		MyHazel::RenderCommand::Clear();


		MyHazel::Renderer::BeginScene(m_CameraController.GetCamera());
		{
			glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

			m_SquareShader->Bind();
			m_SquareShader->SetFloat3("u_Color", m_Color);

			for (int y = 0; y < 20; y++)
			{
				for (int x = 0; x < 20; x++)
				{
					glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
					glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
					MyHazel::Renderer::Submit(m_SquareShader, m_SquareVA, transform);
				}
			}

			auto TextureShader = m_ShaderLibrary.Get("Texture");

			m_Texture->Bind();
			MyHazel::Renderer::Submit(TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
			//MyHazel::Renderer::Submit(m_Shader, m_VertexArray);
		}
		MyHazel::Renderer::EndScene(); 
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_Color));
		ImGui::End();

	}

	void OnEvent(MyHazel::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}


private:
	MyHazel::ShaderLibrary m_ShaderLibrary;
	MyHazel::Ref<MyHazel::Shader> m_Shader;
	MyHazel::Ref<MyHazel::VertexArray> m_VertexArray;


	MyHazel::Ref<MyHazel::Shader> m_SquareShader;
	MyHazel::Ref<MyHazel::VertexArray> m_SquareVA;

	MyHazel::Ref<MyHazel::Texture2D> m_Texture;

	MyHazel::OrthographicCameraController m_CameraController;
	glm::vec3 m_Color = { 0.2,0.3,0.8 };

};

class Sandbox : public MyHazel::Application {
public:
	Sandbox() {
		PushLayer(new Sandbox2D());

	}

	~Sandbox() {
	
	}

};

MyHazel::Application* MyHazel::CreateApplication() 
{
	return new Sandbox();
}