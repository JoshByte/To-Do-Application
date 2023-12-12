#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib> // Include for rand() and srand()
#include <limits>

class Item
{
private:
    int id;
    std::string description;
    bool completed;

public:
    Item();

    bool create(const std::string &new_description)
    {
        // Generates a random int between 1 and 100
        id = rand() % 100 + 1;
        description = new_description;
        return true;
    }

    int getId()
    {
        return id;
    }

    std::string getDescription()
    {
        return description;
    }

    bool isComplete()
    {
        return completed;
    }

    // int getId() const { return id; }
    // std::string getDescription() const { return description; }
    // bool isCompleted() const { return completed; }

    void setCompleted(bool val)
    {
        completed = val;
    }
};

Item::Item() : id(0), description(""), completed(false)
{
}

int main()
{
    std::list<Item> todoItems;
    std::list<Item>::iterator it;
    int user_choice;
    int user_input_id;
    std::string user_input_description;

    srand(static_cast<unsigned int>(time(NULL))); // Use static_cast to avoid warning

    while (true)
    {
        system("cls");
        std::cout << "Welcome to the To-Do List.\n\n";

        if (todoItems.empty())
        {
            std::cout << "The to-do list is empty. Add an entry.\n\n";
        }
        else
        {
            for (Item item : todoItems)
            {
                std::string completed = item.isComplete() ? "Task Completed" : "Task Not Completed";

                std::cout << "Task ID: " << item.getId() << " | "
                          << "Task Description: " << item.getDescription() << " | "
                          << "Task Status: " << completed << std::endl;
            }
        }

        std::cout << "\n1. Add a new To-Do item.\n";
        std::cout << "2. Complete a To-Do item.\n";
        std::cout << "3. Quit.\n\n";

        std::cout << "Enter your choice: ";
        std::cin >> user_choice;

        if (user_choice == 3)
        {
            std::cout << "Thanks for using the To-Do Application.";
            break;
        }
        else if (user_choice == 1)
        {
            std::cout << "Add a new To-Do item: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Use numeric_limits to clear input buffer
            std::getline(std::cin, user_input_description);

            Item newTodoItem;
            newTodoItem.create(user_input_description);
            todoItems.push_back(newTodoItem);
        }
        else if (user_choice == 2)
        {
            std::cout << "Enter the id of the item you want to complete: ";
            std::cin >> user_input_id;

            for (it = todoItems.begin(); it != todoItems.end(); it++)
            {
                std::string completed = it->isComplete() ? "Task Complete" : "Task Not Complete";

                std::cout << "Task ID: " << it->getId() << " | "
                          << "Task Description: " << it->getDescription() << " | "
                          << "Completion Status: " << completed << std::endl;

                if (user_input_id == it->getId())
                {
                    it->setCompleted(true);
                    break;
                }
                else
                {
                    std::cout << "ID does not exist. Try again.\n";
                }
            }
        }
    }
    return 0;
}
