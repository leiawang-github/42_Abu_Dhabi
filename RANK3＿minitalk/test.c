// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     pid_t pid = getpid(); // 获取当前进程ID
//     printf("当前进程的ID是: %d\n", pid);
//     return 0;
// }

// int main()
// {
//     for (int i = 0 ; i <= 5; i++ )
//     {
//         printf("第 %d 次打印\n", i+ 1);
//         sleep(5);
//     } 
// }


// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     printf("开始...\n");
//     usleep(500000); // 暂停 0.5 秒
//     printf("延迟 0.5 秒后...\n");
//     return 0;
// }

// #include <stdio.h>
// #include <unistd.h>

// int main() {
//     for (int i = 0; i < 10; i++) {
//         printf("第 %d 次打印\n", i + 1);
//         usleep(100000); // 延迟 100,000 微秒（0.1 秒）
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// int main(int argc, char *argv[]) {
//     if (argc != 2) {
//         printf("使用方法: %s <pid>\n", argv[0]);
//         return 1;
//     }

//     pid_t pid = atoi(argv[1]); // 获取目标进程ID
//     if (kill(pid, SIGKILL) == 0) {
//         printf("成功向进程 %d 发送 SIGKILL 信号\n", pid);
//     } else {
//         perror("kill 失败");
//     }

//     return 0;
// }



// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>

// //自定义信号处理函数
// void signal_handler(int signum) {
//     printf("接收到信号: %d\n", signum);
// }

// int main() {
//     // 注册信号处理函数
//     signal(SIGTERM, signal_handler);
//     printf("进程ID: %d\n", getpid());
    
//     // 无限循环等待信号
//     while (1) {
//         printf("等待信号...\n");
//         sleep(3);
//     }
//     return 0;
// }

// #include <unistd.h>
// #include <stdio.h>

// int main()
// {
//     printf("Here is a test of pid : %d\n", getpid());
// }

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function

// Signal handler function
void signal_handler(int signum) 
{
    // Print a message indicating which signal was received
    if (signum == SIGINT) {
        printf("Received SIGINT! Exiting gracefully.\n");
    } else if (signum == SIGTERM) {
        printf("Received SIGTERM! Exiting gracefully.\n");
    } else {
        printf("Received signal %d! Exiting.\n", signum);
    }
    exit(0); // Exit the program
}

int main() 
{
    // Set the signal handler for the SIGINT and SIGTERM signals
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    printf("Program is running. Press Ctrl+C to trigger SIGINT or send SIGTERM to terminate.\n");

    while (1) {
        // Simulate some work by printing a message and sleeping
        printf("Working...\n");
        sleep(1); // Pause for 1 second
    }

    return 0; // This will never be reached
}
