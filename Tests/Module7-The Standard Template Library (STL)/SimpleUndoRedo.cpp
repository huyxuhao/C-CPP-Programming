#include <iostream>
#include <string>
#include <stack>

// Use global variables for simplicity
std::string document = "";
std::stack<std::string> undo_stack;
std::stack<std::string> redo_stack;

// Helper function to print the current state
void print_document()
{
    std::cout << " Document: \"" << document << "\"\n\n";
}

// Simulate a user typing text
void type(const std::string &text)
{
    std::cout << ">> Typing '" << text << "'\n";
    // Add the typed text to the document
    document += text;

    // Push the action (the text that was added) onto the undo stack
    undo_stack.push(text);

    // A new action clears the redo history
    // Create an empty stack and swap to clear it efficiently
    std::stack<std::string> empty;
    std::swap(redo_stack, empty);
}

// Simulate pressing Ctrl+Z (Undo)
void undo()
{
    std::cout << ">> Undoing...\n";
    if (undo_stack.empty())
    {
        std::cout << " (Nothing to undo)\n\n";
        return;
    }

    // Get the last action from the undo stack
    std::string last_action = undo_stack.top();
    undo_stack.pop();

    // Remove the last action from the document
    document.erase(document.size() - last_action.size());

    // Move the action to the redo stack
    redo_stack.push(last_action);
}

// Simulate pressing Ctrl+Y (Redo)
void redo()
{
    std::cout << ">> Redoing...\n";
    if (redo_stack.empty())
    {
        std::cout << " (Nothing to redo)\n\n";
        return;
    }

    // Get the last undone action from the redo stack
    std::string last_undone = redo_stack.top();
    redo_stack.pop();

    // Reapply the action to the document
    document += last_undone;

    // Move the action back to the undo stack
    undo_stack.push(last_undone);
}

int main()
{
    std::cout << "Simple Undo/Redo Example\n";

    print_document();

    type("Hello");
    print_document();

    type("World!");
    print_document();

    type("How are you?");
    print_document();

    undo(); // undo "How are you?"
    print_document();

    undo(); // undo "World!"
    print_document();

    redo(); // redo "World!"
    print_document();

    // Typing a new action clears the redo stack
    type("C++!");
    print_document();

    redo(); // Try to redo again, but there's nothing to redo
    print_document();

    return 0;
}