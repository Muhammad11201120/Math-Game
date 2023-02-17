#include <iostream>
#include <string>

using namespace std;
/********************Enums***************************/
enum enLevel
{
    Easy = 1,
    Mid = 2,
    Hard = 3,
    levelMix = 4
};
enum enOperations
{
    Add = 1,
    Sub = 2,
    Mul = 3,
    Divi = 4,
    Mix = 5
};

/********************Structs***************************/
struct stQuestions
{
    short questions;
    short level;
};
struct stOperations
{
    short add;
    short sub;
    short mul;
    short div;
};
struct stGameChoices
{
    enLevel level;
    enOperations operation;
    stQuestions questios;
    int userAnswer;
    short arr[50];
    short randOperationArr[4];
    short randLevelArr[3];
};

/********************Functions***************************/
void seprator()
{
    cout << "\n-----------------------\n"
         << endl;
};
short setQuestionNumbers(stQuestions &questions)
{
    cout << "How Many Question You Want ? : ";
    cin >> questions.questions;
    return questions.questions;
}
void setquestiosLevel(stQuestions &level)
{
    cout << "What is The Level Of Querstions: [1]-> Easy| [2]-> Mid| [3]-> Hard| [4]-> Mix ? ";
    cin >> level.level;
}
enOperations setquestionOperation(enOperations &operation)
{
    short oper;
    cout << "What is The type Of Operation: [1]-> Add| [2]-> Sub| [3]-> Mult| [4]-> Divi| [5]-> Mix ? ";
    cin >> oper;
    return (enOperations)oper;
}
void numberOfQuestions(stGameChoices numbers, short &counter)
{
    cout << "\nQuestion [" << counter++ << "|" << numbers.questios.questions << "]\n"
         << endl;
}
int randNumber(int from, int to)
{
    int randNum = rand() % (to - from + 1) + from;
    return randNum;
}
void randomArrayFromOntToHundred(int arr[], int &arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = randNumber(1, 100);
    }
}
short findNumberInArray(int arr[], int indexes, int numberToSearchfor)
{
    for (int i = 0; i < indexes; i++)
    {
        if (arr[i] == numberToSearchfor)
        {
            return i;
        }
    }
    return -1;
}
void getNumberOFQuestion(stQuestions questionNumber)
{
    for (short i = 1; i < questionNumber.questions; i++)
    {
        cout << "Question: [" << i << "| " << questionNumber.questions << "]" << endl;
    }
}
int add(int number1, int number2)
{
    return number1 + number2;
}
int sub(int number1, int number2)
{
    return number1 - number2;
}
int mult(int number1, int number2)
{
    return number1 * number2;
}
int divi(int number1, int number2)
{
    return number1 / number2;
}
int mix(int number1, int number2)
{
    int operation = randNumber(1, 4);
    switch (operation)
    {
    case 1:
        return add(number1, number2);
    case 2:
        return sub(number1, number2);
    case 3:
        return mult(number1, number2);
    default:
        return divi(number1, number2);
    }
}
void setModArray(short arr[50], stQuestions level)
{
    if (level.level == enLevel::Easy)
    {
        for (int i = 0; i < 50; i++)
        {
            arr[i] = randNumber(1, 20);
        }
    }
    else if (level.level == enLevel::Mid)
    {
        for (int i = 0; i < 50; i++)
        {
            arr[i] = randNumber(1, 50);
        }
    }
    else if (level.level == enLevel::Hard)
    {
        for (int i = 0; i < 50; i++)
        {
            arr[i] = randNumber(1, 100);
        }
    }
    else if (level.level == enLevel::levelMix)
    {
        for (int i = 0; i < 50; i++)
        {
            arr[i] = randNumber(1, 100);
        }
    }
}
short getMixOperation()
{
    short operation = randNumber(1, 4);
    return operation;
}
void rightAnswer()
{
    cout << "Right Answer :)" << endl;
    seprator();
    cout << "Result is => ";
    system("color 2F");
}
void wrongAnswer()
{
    cout << "Bad Answer :(" << endl;
    seprator();
    cout << "Result is => ";
    system("color 4F");
}
void addResult(stGameChoices gamchoices)
{

    cout << "What is The Result of " << gamchoices.arr[0] << " + " << gamchoices.arr[1] << endl;
    cin >> gamchoices.userAnswer;
    if (gamchoices.userAnswer == gamchoices.arr[0] + gamchoices.arr[1])
    {
        rightAnswer();
        cout << gamchoices.arr[0] + gamchoices.arr[1];
    }
    else
    {
        wrongAnswer();
        cout << gamchoices.arr[0] + gamchoices.arr[1];
    }
}
void subResult(stGameChoices gamchoices)
{
    cout << "What is The Result of " << gamchoices.arr[0] << " - " << gamchoices.arr[1] << endl;
    cin >> gamchoices.userAnswer;
    if (gamchoices.userAnswer == gamchoices.arr[0] - gamchoices.arr[1])
    {
        rightAnswer();
        cout << gamchoices.arr[0] - gamchoices.arr[1];
    }
    else
    {
        wrongAnswer();
        cout << gamchoices.arr[0] - gamchoices.arr[1];
    }
}
void multResult(stGameChoices gamchoices)
{
    cout << "What is The Result of " << gamchoices.arr[0] << " * " << gamchoices.arr[1] << endl;
    cin >> gamchoices.userAnswer;
    if (gamchoices.userAnswer == gamchoices.arr[0] * gamchoices.arr[1])
    {
        rightAnswer();
        cout << gamchoices.arr[0] * gamchoices.arr[1];
    }
    else
    {
        wrongAnswer();
        cout << gamchoices.arr[0] * gamchoices.arr[1];
    }
}
void diviResult(stGameChoices gamchoices)
{
    cout << "What is The Result of " << gamchoices.arr[0] << " / " << gamchoices.arr[1] << endl;
    cin >> gamchoices.userAnswer;
    if (gamchoices.userAnswer == gamchoices.arr[0] / gamchoices.arr[1])
    {
        rightAnswer();
        cout << gamchoices.arr[0] / gamchoices.arr[1];
    }
    else
    {
        wrongAnswer();
        cout << gamchoices.arr[0] / gamchoices.arr[1];
    }
}
void mixResult(stGameChoices gamchoices)
{
    switch (getMixOperation())
    {
    case enOperations::Add:
        cout << "What is The Result of " << gamchoices.arr[0] << " + " << gamchoices.arr[1] << endl;
        cin >> gamchoices.userAnswer;
        if (gamchoices.userAnswer == gamchoices.arr[0] + gamchoices.arr[1])
        {
            rightAnswer();
            cout << gamchoices.arr[0] + gamchoices.arr[1];
        }
        else
        {
            wrongAnswer();
            cout << gamchoices.arr[0] + gamchoices.arr[1];
        }
        break;
    case enOperations::Sub:
        cout << "What is The Result of " << gamchoices.arr[0] << " - " << gamchoices.arr[1] << endl;
        cin >> gamchoices.userAnswer;
        if (gamchoices.userAnswer == gamchoices.arr[0] - gamchoices.arr[1])
        {
            rightAnswer();
            cout << gamchoices.arr[0] - gamchoices.arr[1];
        }
        else
        {
            wrongAnswer();
            cout << gamchoices.arr[0] - gamchoices.arr[1];
        }
        break;
    case enOperations::Mul:
        cout << "What is The Result of " << gamchoices.arr[0] << " * " << gamchoices.arr[1] << endl;
        cin >> gamchoices.userAnswer;
        if (gamchoices.userAnswer == gamchoices.arr[0] * gamchoices.arr[1])
        {
            rightAnswer();
            cout << gamchoices.arr[0] * gamchoices.arr[1];
        }
        else
        {
            wrongAnswer();
            cout << gamchoices.arr[0] * gamchoices.arr[1];
        }
        break;

    default:
        cout << "What is The Result of " << gamchoices.arr[0] << " / " << gamchoices.arr[1] << endl;
        cin >> gamchoices.userAnswer;
        if (gamchoices.userAnswer == gamchoices.arr[0] / gamchoices.arr[1])
        {
            rightAnswer();
            cout << gamchoices.arr[0] / gamchoices.arr[1];
        }
        else
        {
            wrongAnswer();
            cout << gamchoices.arr[0] / gamchoices.arr[1];
        }
        break;
    }
}
char askToPlayAgain()
{
    char playAgain;
    cout << "Do You Want To Play Again ? : ";
    cin >> playAgain;
    return playAgain;
}
bool PlayAgainOrNot()
{
    char playAgain = askToPlayAgain();
    if (playAgain == 'Y' || playAgain == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void startExam(stGameChoices gamchoices)
{
    system("cls");
    system("color 0F");
    bool playAgain = true;
    while (playAgain)
    {
        short counter = 1;
        gamchoices.questios.questions = setQuestionNumbers(gamchoices.questios);
        setquestiosLevel(gamchoices.questios);
        gamchoices.operation = setquestionOperation(gamchoices.operation);
        for (short j = 0; j < gamchoices.questios.questions; j++)
        {
            numberOfQuestions(gamchoices, counter);
            if (gamchoices.operation == enOperations::Add)
            {
                setModArray(gamchoices.arr, gamchoices.questios);
                addResult(gamchoices);
            }
            else if (gamchoices.operation == enOperations::Sub)
            {
                setModArray(gamchoices.arr, gamchoices.questios);
                subResult(gamchoices);
            }
            else if (gamchoices.operation == enOperations::Mul)
            {
                setModArray(gamchoices.arr, gamchoices.questios);
                multResult(gamchoices);
            }
            else if (gamchoices.operation == enOperations::Divi)
            {
                setModArray(gamchoices.arr, gamchoices.questios);
                diviResult(gamchoices);
            }
            else if (gamchoices.operation == enOperations::Mix)
            {
                setModArray(gamchoices.arr, gamchoices.questios);
                mixResult(gamchoices);
            }
        }
        if (!PlayAgainOrNot())
        {
            playAgain = false;
            system("cls");
            system("color 0F");
        }
    }
}
void startGame()
{

    stGameChoices gamchoices;
    startExam(gamchoices);
}
int main()
{
    srand((unsigned)time(NULL));
    startGame();
    return 0;
}