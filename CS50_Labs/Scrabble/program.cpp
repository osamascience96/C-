#include <iostream>

/// <summary>
/// struct for key value pair for the dashboard of scrabble
/// </summary>
struct ScrabbleBoard
{
    // key
    char alphabet;
    // value
    int value;
}sb;

/// <summary>
/// ScrabbleBoard Array that contains 25 alphabet keys and their respective values
/// </summary>
ScrabbleBoard scrableBoardArray[] = {
    {sb.alphabet = 'A', sb.value = 1},
    {sb.alphabet = 'B', sb.value = 3},
    {sb.alphabet = 'C', sb.value = 3},
    {sb.alphabet = 'D', sb.value = 2},
    {sb.alphabet = 'E', sb.value = 1},
    {sb.alphabet = 'F', sb.value = 4},
    {sb.alphabet = 'G', sb.value = 2},
    {sb.alphabet = 'H', sb.value = 4},
    {sb.alphabet = 'I', sb.value = 1},
    {sb.alphabet = 'J', sb.value = 8},
    {sb.alphabet = 'K', sb.value = 5},
    {sb.alphabet = 'L', sb.value = 1},
    {sb.alphabet = 'M', sb.value = 3},
    {sb.alphabet = 'N', sb.value = 1},
    {sb.alphabet = 'O', sb.value = 1},
    {sb.alphabet = 'P', sb.value = 3},
    {sb.alphabet = 'Q', sb.value = 10},
    {sb.alphabet = 'R', sb.value = 1},
    {sb.alphabet = 'S', sb.value = 1},
    {sb.alphabet = 'T', sb.value = 1},
    {sb.alphabet = 'U', sb.value = 1},
    {sb.alphabet = 'V', sb.value = 4},
    {sb.alphabet = 'W', sb.value = 4},
    {sb.alphabet = 'X', sb.value = 8},
    {sb.alphabet = 'Y', sb.value = 4},
    {sb.alphabet = 'Z', sb.value = 10},
};

/// <summary>
/// Convert any given character to uppercase
/// </summary>
/// <param name="input">character type input</param>
/// <returns>return the modified character to upper case(numbers are returned as it is they are)</returns>
char ToUpperCase(char input) {
    return toupper(input);
}

/// <summary>
/// Callback for getting the particular score of the board
/// </summary>
/// <param name="input">takes input of the char type</param>
/// <returns>returns the score of the given input character</returns>
int GetCharacterScore(char input) {
    int arrLen = sizeof(scrableBoardArray) / sizeof(scrableBoardArray[0]);
    for (int i = 0; i < arrLen; i++) {
        if (ToUpperCase(input) == scrableBoardArray[i].alphabet) {
            return scrableBoardArray[i].value;
        }
    }

    return 0;
}

/// <summary>
/// Compute the Score of the given word
/// </summary>
/// <param name="word">takes the input of char* type</param>
/// <returns>returns the score</returns>
int ComputeScore(char* word) {
    int sum = 0;
    for (int i = 0; i < strlen(word); i++) {
        sum += GetCharacterScore(word[i]);
    }

    return sum;
}

int main()
{
    /* write a scrabble program that takes input in the form of string for both player 1 and player 2 and compute the score from the 
    score board in the form of key pair values and then display the player wins with the hightest points and tie if the score is same.*/

    // take inputs for player 1 and 2
    char *player1word = new char();
    char *player2word = new char();

    std::cout << "Player 1: ";
    std::cin >> player1word;

    std::cout << "Player 2: ";
    std::cin >> player2word;

    // init the score for each player score
    int player1Score = ComputeScore(player1word);
    int player2Score = ComputeScore(player2word);

    if (player1Score > player2Score) {
        std::cout << "Player 1 Wins!" << std::endl;
    }
    else if (player1Score < player2Score) {
        std::cout << "Player 2 Wins!" << std::endl;
    }
    else {
        std::cout << "Tie!" << std::endl;
    }
}
