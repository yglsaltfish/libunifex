#include <unifex/sync_wait.hpp>
#include <unifex/then.hpp>
#include <unifex/just.hpp>
#include <iostream>
#include <string>

int main() {
    // 1. 创建一个最简单的 Sender，它会立即产生值 42
    auto start_sender = unifex::just(std::string("ggbond"));

    // 2. 使用管道符 | 和 then 算法创建一个新的 Sender
    //    这个新的 Sender 会在上一个 Sender 完成后，将其结果加 1
    auto transformed_sender = start_sender | unifex::then([](std::string value) {
        std::cout << "In then, value is: " << value << std::endl;
        return value + " and ggbond2";
    });

    // 3. 使用 sync_wait 启动整个 Sender 链，并阻塞等待结果
    //    transformed_sender 直到这里才真正开始执行
    auto result = unifex::sync_wait(transformed_sender);

    if (result) {
        // sync_wait 返回一个 std::optional，因为 Sender 可能被取消
        std::cout << "Final result: " << *result << std::endl;
    }

    return 0;
}