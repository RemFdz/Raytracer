//
// Created by Romain on 4/30/24.
//

#ifndef MULTI_THREAD_HPP
#define MULTI_THREAD_HPP

#include <vector>
#include <thread>
#include <functional>

class Threads {
public:
    Threads() {}

    void execute(std::function<void(int, int)> render_segment, int start, int end, int num_threads);

private:
    std::vector<std::thread> threads;
};

#endif //MULTI_THREAD_HPP
