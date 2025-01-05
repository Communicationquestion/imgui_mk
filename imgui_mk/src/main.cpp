#include <imgui_mk/application.h>
#include <iostream>
#include <vector>
float f = 1.0;
std::vector<char> buf1(1024);
std::vector<char> buf2(1024);
std::vector<char> buf3(1024);
std::vector<char> buf4(1024);
void Render() {
  ImGui::Text("Hello, world %d", 123);

  if (ImGui::BeginChild("left_panel", ImVec2(150, 0), true)) {
    // 左侧子窗口内容...
    if (ImGui::Button("Save"))
      ([]() { std::cout << "save" << "\n"; })();
    ImGui::SameLine(100);
    if (ImGui::Button("encode"))
      ([]() { std::cout << "encode" << "\n"; })();
  }
  ImGui::EndChild();

  ImGui::SameLine(); // 放置下一个子窗口在同一行上

  if (ImGui::BeginChild("right_panel", ImVec2(0, 0), true)) {
    // 右侧子窗口内容...
    ImGui::InputText("string1", buf1.data(), IM_ARRAYSIZE(buf1.data()));
    ImGui::InputText("string2", buf2.data(), IM_ARRAYSIZE(buf2.data()));
    ImGui::InputText("string3", buf3.data(), IM_ARRAYSIZE(buf3.data()));
    ImGui::InputText("string4", buf4.data(), IM_ARRAYSIZE(buf4.data()));
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
  }
  ImGui::EndChild();
}

int main() {
  Mk::Application app;
  app.run([](){Render();});
  return 0;
}
