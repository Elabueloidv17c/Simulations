#include "Application.h"

void 
Application::Run() {
  Initialize(WindowData(sf::Style::Default, "Simulación de fisicas", Size(1280, 720)));

  while (m_window.isOpen()) {
    ProcessInput();
    Update();
    Render();
  }

  Destroy();
}

void
Application::Initialize(WindowData window) {
  //--------------------------------------------------------------------------------
	//Window
	//--------------------------------------------------------------------------------
	m_window.create(VideoMode(window.size.width, window.size.height), window.name, window.style);

	//--------------------------------------------------------------------------------
	// World
	//--------------------------------------------------------------------------------
  m_world.Initialize(&m_window, &m_timer);

	//--------------------------------------------------------------------------------
	//Timer
	//--------------------------------------------------------------------------------
  m_timer.Initialize();
}

void 
Application::ProcessInput() {
  while (m_window.pollEvent(m_event)) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
        Event::Closed == m_event.type) {
      m_window.close();
    }
    else if (Event::Resized == m_event.type) {
      m_window.setSize(Vector2u(m_event.size.width, 
                                m_event.size.height));
      m_window.setView(View(FloatRect(0, 
                                      0, 
                                      static_cast<float>(m_event.size.width),
                                      static_cast<float>(m_event.size.height))));
    }
    m_world.ProcessInput(m_event);
  }
}

void 
Application::Destroy() {
  m_world.Destroy();
}

void 
Application::Update() {
  m_timer.Update();
  m_world.Update();
}

void 
Application::Render() {
  m_world.Render();
}
