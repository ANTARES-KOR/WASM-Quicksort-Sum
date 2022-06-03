<p align="center"><img src="https://github.com/carlosbaraza/web-assembly-logo/blob/master/dist/logo/web-assembly-logo.png"></p>

## WebAssembly Experiment: Array Sum & Quicksort

Lately I wrote mostly Javascript and Javascript (and Typescript). It's great, I love it, but the idea that you can do Front-end with C intrigued me.

It can be achieved using [WebAssembly](https://en.wikipedia.org/wiki/WebAssembly). So I started digging into it, and that repo is a result of my first impression.

## Experiment #1: Array Sum

I was quite disappointed to hear that there is no query manipulation possible with WebAssembly. The appropriate utility for it is to outsource resource-intensive functions to WASM, and consume them from the ol' good Javascript.

So I wrote a basic array sum function in C. Then I compiled it to WASM using [WasmFiddle](https://wasdk.github.io/WasmFiddle/). 

Including Wasm to an HTML is straightforward ([using proper API](https://developer.mozilla.org/en-US/docs/WebAssembly/Loading_and_running)), but communicating with it may be tricky. One difficulty is because of the "memory safety" – you have to prepare a memory buffer to send an array from JS to WASM. It is not required for a simple integer though. 

## Experiment #2: Quick Sort

Previously, I was able to send an array from JS to WASM, and get back an integer. This time I wanted to get back an array. A sorted array.

A C implementation of quicksort algorithm from [GeeksForGeeks](https://www.geeksforgeeks.org/quick-sort/) was very helpful for that.

Sadly, I was unable to return an array from C++WASM. Instead, I used a void function for the Quicksort implementation, but because of the "memory buffer allocation" mentioned before – the array sent from JS to WASM is actually ["passed by reference"](https://levelup.gitconnected.com/pass-by-value-vs-pass-by-reference-in-javascript-82fa8736c9f7) – meaning it will store the result after the sorting.
