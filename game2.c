#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    int rounds = 5;
    int correct = 0;
    int wrong = 0;

    printf("=== Typing Speed Test ===\n");
    printf("Type the words as fast and correctly as you can!\n\n");

    srand(time(0));
    clock_t start = clock();

    for (int i = 0; i < rounds; i++)
    {
        const char *word = words[rand() % n];
        char input[50];

        printf("Word %d: %s\n", i + 1, word);
        printf("Your input: ");
        scanf("%s", input);

        if (strcmp(input, word) == 0)
        {
            printf("Correct!\n\n");
            correct++;
        }
        else
        {
            printf("Wrong! The correct word was: %s\n\n", word);
            wrong++;
        }
    }

    clock_t end = clock();
    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("=== Test Finished ===\n");
    printf("Correct: %d\n", correct);
    printf("Wrong: %d\n", wrong);
    printf("Time Taken: %.2f seconds\n", timeTaken);
    printf("Typing Speed: %.2f words per minute\n", (rounds / timeTaken) * 60);

    return 0;
}