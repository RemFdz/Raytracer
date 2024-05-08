//
// Created by Romain on 4/30/24.
//

#ifndef MULTI_THREAD_HPP
#define MULTI_THREAD_HPP

#include <thread>
#include <vector>
#include <functional>
#include <memory>

class Thread {
public:
    Thread() = default;

    template<typename Func, typename... Args>
    void start(Func&& func, Args&&... args) {
        thread = std::make_unique<std::thread>(std::forward<Func>(func), std::forward<Args>(args)...);
    }

    void join() {
        if (thread && thread->joinable()) {
            thread->join();
        }
    }

    ~Thread() {
        join();
    }

private:
    std::unique_ptr<std::thread> thread;
};

#endif // MULTI_THREAD_HPP
