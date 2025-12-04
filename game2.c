#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>  // For Sleep() and clearing screen in Windows

void clearScreen() {
    system("cls");
}

int main()
{
    const char *words[] = {
        "apple","book","cat","dog","tree","sun","water","house","milk","chair",
        "school","pen","ball","fish","bird","star","car","door","hat","road",
        "juxtapose","quizzical","xylophone","zephyr","mnemonic","pseudonym",
        "onomatopoeia","labyrinth","ephemeral","cacophony","philanthropy",
        "idiosyncrasy","quintessential","obfuscate","perspicacious","verisimilitude",
        "sesquipedalian","circumlocution","magnanimous","antediluvian"
    };

    int n = sizeof(words) / sizeof(words[0]);

    int choice;
    int totalTime = 0;

    printf("=== Typing Speed Test ===\n");
    printf("Choose a time limit:\n");
    printf("1. 1 Minute\n");
    printf("2. 3 Minutes\n");
    printf("3. 5 Minutes\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) totalTime = 60;
    else if (choice == 2) totalTime = 180;
    else if (choice == 3) totalTime = 300;
    else {
        printf("Invalid choice! Exiting...");
        return 0;
    }

    clearScreen();
    printf("Timer starts NOW! Type as many words as you can!\n");
    Sleep(1000);
    clearScreen();

    int score = 0;
    char input[50];
    srand(time(0));

    time_t start = time(NULL);
    time_t now;

    while (1)
    {
        now = time(NULL);
        int timeLeft = totalTime - (int)(now - start);

        if (timeLeft <= 0)
            break;

        const char *word = words[rand() % n];

        printf("Time Left: %d seconds\n", timeLeft);
        printf("Word: %s\n", word);
        printf("Type: ");
        scanf("%s", input);

        clearScreen();

        if (strcmp(input, word) == 0) {
            score++;
            printf("Correct! Score: %d\n\n", score);
        } else {
            printf("Wrong! Score: %d\n\n", score);
        }
    }

    clearScreen();
    printf("=== TIME'S UP! ===\n");
    printf("Total Correct Words: %d\n", score);
    printf("Time Used: %d seconds\n", totalTime);

    double wpm = (score * 60.0) / totalTime;
    printf("Typing Speed: %.2f WPM\n", wpm);

    return 0;
}
