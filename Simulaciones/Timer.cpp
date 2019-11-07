#include "Timer.h"

float 
Timer::GetDeltaTime(TIME::E format) {
  if (TIME::E::Microseconds == format) {
    return  static_cast<float>(m_time.asMicroseconds());
  }
  else if (TIME::E::Miliseconds == format) {
    return  static_cast<float>(m_time.asMilliseconds());
  }
  return m_time.asSeconds();
}

float
Timer::GetElapsedTime(TIME::E format) {
  if (TIME::E::Microseconds == format) {
    return  static_cast<float>(m_clock.getElapsedTime().asMicroseconds());
  }
  else if (TIME::E::Miliseconds == format) {
    return  static_cast<float>(m_clock.getElapsedTime().asMilliseconds());
  }
  return m_clock.getElapsedTime().asSeconds();
}

void 
Timer::Initialize() {
  m_clock.restart();
  m_delta.restart();
  m_time.Zero;
}

void
Timer::Restart() {
  m_clock.restart();
}

void 
Timer::Update() {
  m_time = m_delta.getElapsedTime();
  m_delta.restart();
}

Timer::Timer() {
  m_clock.restart();
  m_delta.restart();
  m_time.Zero;
}
