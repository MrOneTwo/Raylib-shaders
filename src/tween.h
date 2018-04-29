#ifndef TWEEN_H
#define TWEEN_H

#include <stdint.h>

typedef enum {
  TWEEN_FORWARD = 1,
  TWEEN_BACKWARD = -1
} TweenDirection;

typedef struct _Tween {
  bool active = false;
  
  int delayCounter = 0;
  int delay = 0;
  int startTime = 0;
  int currentTime = 0;
  int durationTime = 0;
  int endTime = 0;
  int step = 0;

  float startValue = 0;
  float currentValue = 0;
  float finalValue = 0;

  TweenDirection direction = TWEEN_FORWARD;
} Tween;

void InitTween(
  Tween* tween,
  float startValue,
  float finalValue,
  uint16_t delay,
  uint16_t duration,
  uint8_t step,
  TweenDirection direction,
  bool active
  );
void ProcessTween(Tween* tween);
void ResetTween(Tween* tween);
Tween InvertTween(Tween* tween);

#endif /* end of include guard: TWEEN_H */
