#include "tween.h"

#include "raylib.h"
#include "rayeasings.h"

#include <stdint.h>

void InitTween(
  Tween* tween,
  float startValue,
  float finalValue,
  uint16_t delay,
  uint16_t duration,
  uint8_t step,
  TweenDirection direction,
  bool active
  )
{
  tween->startValue = startValue;
  tween->finalValue = finalValue - startValue;
  tween->delay = delay;
  tween->durationTime = duration;
  tween->step = step;
  tween->direction = direction;
  tween->active = active;

  tween->delayCounter = tween->delay;
  tween->startTime = 0;
  tween->currentTime = 0;
  tween->endTime = tween->startTime + tween->durationTime;
  tween->currentValue = tween->startValue;
}

void ProcessTween(Tween* tween)
{
  if (tween->currentTime > tween->endTime || tween->currentTime < tween->startTime)
  {
    tween->active = false;
  }

  if (tween->active) {

    // postpone action if delayed
    if (tween->delayCounter) {
      tween->delayCounter--;
      return;
    }

    if (tween->direction == TWEEN_FORWARD) {
      tween->currentValue = EaseCircIn(
        tween->currentTime,
        tween->startValue,
        tween->finalValue,
        tween->durationTime);
    }
    else if (tween->direction == TWEEN_BACKWARD) {
      tween->currentValue = EaseCircIn(
        tween->currentTime,
        tween->startValue,
        tween->finalValue,
        tween->durationTime);
    }

    // make a step
    tween->currentTime += (tween->direction * tween->step);
  }
}

void ResetTween(Tween* tween)
{
  tween->currentValue = tween->startValue;
  tween->currentTime  = tween->startTime;
  tween->delayCounter = tween->delay;
  tween->active = true;
}

// @NOTE: passing through value because functional programming...?
Tween InvertTween(Tween* tween)
{
  tween->direction = (TweenDirection)(-1 * tween->direction);
  // move the time back into active range
  if (tween->direction == TWEEN_FORWARD) {
    tween->currentTime++;
  }
  else if (tween->direction == TWEEN_BACKWARD) {
    tween->currentTime--;
  }
}
