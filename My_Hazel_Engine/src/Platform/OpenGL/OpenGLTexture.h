#pragma once
#include "MyHazel/Renderer/Texture.h"
#include <glad/glad.h>

namespace MyHazel {

	class OpenGLTexture2D :public Texture2D 
	{
	public:
		OpenGLTexture2D(uint32_t width, uint32_t height);
		OpenGLTexture2D(const std::string& path);
		virtual ~OpenGLTexture2D();

		virtual uint32_t GetWidth()const override { return m_Width; }
		virtual uint32_t GetHeight()const override { return m_Height;}

		virtual void SetData(void* data, uint32_t size) override;

		virtual void Bind() const override;

	private:
		uint32_t m_Width, m_Height;
		std::string m_Path;
		uint32_t m_RendererID;
		GLenum m_InternalFormat, m_DataFormat;
	};
}
