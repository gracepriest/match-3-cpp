#pragma once

#include <iostream>
#include <functional>

    template <typename T>
    class Tween {
    public:
        Tween(T startValueX, T endValueX, T startValueY, T endValueY, float duration, std::function<T(T, T, float)> interpolator)
            : startValueX(startValueX), endValueX(endValueX), startValueY(startValueY), endValueY(endValueY),duration(duration), interpolator(interpolator), elapsedTime(0.0f) {}

        Tween(T startValue, T endValue, float duration, std::function<T(T, T, float)> interpolator)
            : startValue(startValue), endValue(endValue), duration(duration), interpolator(interpolator), elapsedTime(0.0f) {}
        

        bool update(float deltaTime) {
            elapsedTime += deltaTime;

            if (elapsedTime >= duration) {
                currentValue = endValue;
                return true;
            }

            float t = elapsedTime / duration;
            currentValue = interpolator(startValue, endValue, t);
            return false;
        }

        /*T getValue() const {
            return currentValue;
        }*/
        bool updateF(float deltaTime) 
        {
            elapsedTime += deltaTime;

            if (elapsedTime >= duration) {
                currentValueX = endValueX;
                currentValueY = endValueY;
                return true;
            }

            float t = elapsedTime / duration;
            currentValueX = interpolator(startValueX, endValueX, t);
            currentValueY = interpolator(startValueY, endValueY, t);
            return false;
        }

        T getValueX() const {
            return currentValueX;
        }
        T getValueY() const {
            return currentValueY;
        }
        Tween() = default;

    private:
        T startValueX;
        T endValueX;
        T startValueY;
        T endValueY;
        T currentValueX;
        T currentValueY;
        T startValue;
        T endValue;
        T currentValue;
        float duration;
        float elapsedTime;
        std::function<T(T, T, float)> interpolator;
        
   
    };
    template <typename T>
    inline T lerp(T start, T end, float t) {
        return start + (end - start) * t;
    }


   
    class Tween1 {
    public:
        Tween1(std::pair<float, float> startValue1, std::pair<float, float> endValue1, float duration1, std::function<std::pair<float, float>(std::pair<float, float>, std::pair<float, float>, float)> interpolator1)
            : startValue1(startValue1), endValue1(endValue1), duration1(duration1), interpolator1(interpolator1), elapsedTime1(0.0f) {}

        Tween1() = default;
        bool update1(float deltaTime) {
            elapsedTime1 += deltaTime;

            if (elapsedTime1 >= duration1) {
                currentValue1 = endValue1;
                return true;
            }

            float t = elapsedTime1 / duration1;
            currentValue1 = interpolator1(startValue1, endValue1, t);
            return false;
        }

        std::pair<float, float> getValue1() const {
            return currentValue1;
        }

    private:
        std::pair<float, float> startValue1;
        std::pair<float, float> endValue1;
        std::pair<float, float> currentValue1;
        float duration1;
        float elapsedTime1;
        std::function<std::pair<float, float>(std::pair<float, float>, std::pair<float, float>, float)> interpolator1;
    };
    
    inline std::pair<float, float> lerpF(const std::pair<float, float>& start, const std::pair<float, float>& end, float t) {
        float lerpedX = start.first + (end.first - start.first) * t;
        float lerpedY = start.second + (end.second - start.second) * t;
        return std::make_pair(lerpedX, lerpedY);
    }
    
   
