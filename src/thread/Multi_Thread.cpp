/*
** EPITECH PROJECT, 2024
** raytracer
** File description:
** Mumti_Thread
*/

#include "Multi_Thread.hpp"

void Threads::execute(std::function<void(int, int)> render_segment, int
start, int end, int num_threads) {
    int rows_per_thread = (end - start) / num_threads;
    for (int k = 0; k < num_threads; ++k) {
        int start_row = start + k * rows_per_thread;
        int end_row = (k + 1 == num_threads) ? end : start_row + rows_per_thread;
        threads.emplace_back(render_segment, start_row, end_row);
    }

    for (auto &t : threads) {
        t.join();
    }
}