#pragma once
#include "Headers.h"



class Timer
{
  Clock m_clock;
  Clock m_delta;
  Time  m_time;

 public:

   float
   GetDeltaTime(TIME::E format = TIME::E::Seconds);

   float
   GetElapsedTime(TIME::E format = TIME::E::Seconds);

   void
   Initialize();

   void
   Restart();

   void
   Update();

   Timer();

   ~Timer() = default;
};

