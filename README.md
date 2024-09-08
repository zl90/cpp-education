# Learning modern C++

I'm using this repository to tinker and test various things while I learn C++. This **will** be an unorganised mess.

## Basic syntax refresher course

The last time I used C++, the standard was C++11. I've wanted to check out modern C++ for a while now, so in this repository I'll be going through Nicholas Day's playlist on [Youtube](https://www.youtube.com/watch?v=cg08V-cj3Zw&list=PL9HfA4ZKbzimKyvquT1MZ2x9d6UHjFNFA) and doing my own exercises to learn the language.

## Learning C++ build systems and metaprogramming

I'm going through this awesome playlist [here](https://www.youtube.com/watch?v=Gwvn8ruzXT8&list=PLxNPSjHT5qvu27ax_VIAalaGIEjxj2Bp0&pp=iAQB). CoffeeBeforeArch is a performance engineer who works with C++. In this playlist he explains how to use various compilers, debuggers, build tools and library creation tools.

## I built my own lock-free single-producer single-consumer FIFO queue

Inspired by [Charles Frasch's video](https://youtu.be/K3P_Lmq6pw0?si=p1GSMT2aW-EdKYxg), I built my own lock-free FIFO queue. The initial implementation used mutexes (not lock-free) which I benchmarked at ~900,000 enqueues/dequeues per second. Over time I improved the performance of the queue by refactoring it as I learned new low-latency performance techniques (eg: pre-allocating memory with placement new, using alignment to prevent false sharing, using C++ atomics, using `memory_order_seq_cst` and then `memory_order_release` and `memory_order_acquire`). Using these techniques I was able to improve the performance to ~15,000,000 enqueues/dequeues per second.
