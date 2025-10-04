#include <iostream>
#include <queue>
#include <string>
#include <thread> //for std::this_thread::sleep_for
#include <chrono> // for std::chrono::seconds

// A simple structure to represent a print job
struct PrintJob
{
    std::string documentName;
    int pages;
};

int main()
{
    // The printer queue
    std::queue<PrintJob> printQueue;

    std::cout << "--- Printer Queue Simulaton ---\n";

    // Users submit print jobs. They are added to the back of the queue.
    printQueue.push({"report.docx", 5});
    std::cout << "[Submitted] report.docx (5 pages)\n";

    printQueue.push({"presentations.pptx", 12});
    std::cout << "[Submitted] presentations.pptx (12 pages)\n";

    printQueue.push({"memo.txt", 1});
    std::cout << "[Submitted] memo.txt (1 page)\n";

    std::cout << "\n--- Printer starting to process jobs ---\n";

    // The printer processes jobs as long as the queue is not empty
    while (!printQueue.empty())
    {
        // 1. Get the job at the front of the queue
        PrintJob currentJob = printQueue.front();

        // 2. Process the job (simulate printing)
        std::cout << "\n[Printing] " << currentJob.documentName << " (" << currentJob.pages << " pages....)\n";

        // Simulate the time it takes to print
        std::this_thread::sleep_for(std::chrono::seconds(currentJob.pages / 5 + 1));

        std::cout << "[Completed]\n";

        // 3. Remove the job from the front of the queue
        printQueue.pop();
    }

    std::cout << "\n--- All print jobs are completed. Printer is idle. ---\n";

    return 0;
}