#include "Camera.h"

View* 
Camera::GetView() {
  return &m_camera;
}

void
Camera::Initialize(Vector2f size, float movementSpeed, float rotationSpeed, 
                   float zoomSpeed, Timer* timer) {
  m_movementSpeed = movementSpeed;
  m_rotationSpeed = rotationSpeed;
  m_zoomSpeed = zoomSpeed;
  m_timer = timer;

  m_camera = View(FloatRect(0.0f, 0.0f, size.x, size.y));
  m_camera.setCenter(size * 0.5f);
  m_camera.setSize(size);
}

void 
Camera::Resize(Vector2f size) {
  m_camera = View(FloatRect(0.0f, 0.0f, size.x, size.y));
  m_camera.setCenter(size * 0.5f);
  m_camera.setSize(size);
}

void 
Camera::MoveUp() {
  m_camera.move(Vector2f(0.0f, m_movementSpeed * m_timer->GetDeltaTime()));
}

void 
Camera::MoveDown() {
  m_camera.move(Vector2f(0.0f, -m_movementSpeed * m_timer->GetDeltaTime()));
}

void 
Camera::MoveLeft() {
  m_camera.move(Vector2f(-m_movementSpeed * m_timer->GetDeltaTime(), 0.0f));
}

void 
Camera::MoveRight() {
  m_camera.move(Vector2f(m_movementSpeed * m_timer->GetDeltaTime(), 0.0f));
}

void 
Camera::ZoomIn() {
  m_camera.zoom(1.0f + (m_zoomSpeed * m_timer->GetDeltaTime()));
}

void 
Camera::ZoomOut() {
  m_camera.zoom(1.0f - (m_zoomSpeed * m_timer->GetDeltaTime()));
}
