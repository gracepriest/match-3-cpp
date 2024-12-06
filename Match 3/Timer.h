#pragma once

#include <thread>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <functional>

#include "Clock.h"

template<typename T=uint64_t>
class _Timer {
public:
    
    struct TimerInstance; // forward decl

    using TimerFunction = std::function<void(TimerInstance&)>;

    struct TimerInstance {
        _Timer<T>* _controller; // controller access
        T _id; // instance id

        enum Type {
            AFTER, EVERY
        } type;

        // time is measured in milliseconds
        int interval; // or delay for type AFTER
        int64_t until; // for every
        Clock clock; // internal clock for checking ms interval
        Clock clock_until; // internal clock for checking ms until end

        TimerFunction callback;

        void stop() {
            _controller->stop(_id);
        }
    };

private:
    std::map<T, TimerInstance> instances;
    std::vector<T> remove_list;
    T ii_counter;

public:
	
	_Timer(): ii_counter(0) {};

    // main update that must be called externally
    void Update() {
        
        // garbage collect timer instances
        if(remove_list.size()){
            for(auto id : remove_list){
                if(instances.count(id)){
                    instances.erase(id);
                }
            }
            remove_list.clear();
        }

        if(instances.empty()) return;

        // runtime check for all timer instances
        for(auto& [id,ii] : instances){
            switch(ii.type){
                // After Instance
                case TimerInstance::AFTER:
                    if(ii.clock.getMilliseconds() >= ii.interval){
                        ii.callback(ii);
                        stop(ii._id);
                    }
                break;
                // Every Instance
                case TimerInstance::EVERY:
                    if(ii.until >= 0 && ii.clock_until.getMilliseconds() >= ii.until){
                        ii.callback(ii);
                        stop(ii._id);
                        continue;
                    }
                    if(ii.clock.getMilliseconds() >= ii.interval){
                        ii.callback(ii);
                        ii.clock.restart();
                    }
                break;
            }
        }
    }

    // add an after instance (callback function, interval ms)
    T after(TimerFunction function, int delay) {
        TimerInstance ii;
        ii._controller = this;
        ii._id = ii_counter;
        ii.type = TimerInstance::AFTER;
        ii.interval = delay;
        ii.callback = function;

        instances.insert_or_assign(ii._id, std::move(ii));
        return ii_counter++;
    }

    // add an every instance (callback function, interval ms, until ms; -1 = infinity)
    T every(TimerFunction function, int interval, int64_t until = -1) {
        TimerInstance ii;
        ii._controller = this;
        ii._id = ii_counter;
        ii.type = TimerInstance::EVERY;
        ii.interval = interval;
        ii.until = until;
        ii.callback = function;

        instances.insert_or_assign(ii._id, std::move(ii));
        return ii_counter++;
    }

    void stop(T number) {
        remove_list.emplace_back(number);
    }

    void stop_all() {
        for(auto& [id,_] : instances){
            remove_list.emplace_back(id);
        }
    }
};

using Timer = _Timer<>;