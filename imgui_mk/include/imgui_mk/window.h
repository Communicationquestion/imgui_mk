#pragma once
#include <imgui_mk/windowRendereren.h>
#include <memory>

namespace Mk {

	class window {
	public:
		 window(const char* title, int width, int height) : m_Handle(nullptr) {
		
			m_Handle = Rendererengine<opengl,int>::init(title, width, height);
			glfwSetWindowUserPointer(m_Handle, this);

		
		}

		GLFWwindow* getHandle() const {
			return m_Handle;
		}
		void render() {
			if(!m_Handle) return;
			glfwMakeContextCurrent(m_Handle);
			glfwSwapBuffers(m_Handle);
		}
		void show() {
		
		
		}

		bool shouldClose() const {
		
			return glfwWindowShouldClose(m_Handle);
		}

		~window() {
			if(m_Handle) {
				glfwDestroyWindow(m_Handle);
				m_Handle = nullptr;
			}
		}

	private:
		GLFWwindow* m_Handle;
		bool isshow=false;
	};
} // namespace Mk