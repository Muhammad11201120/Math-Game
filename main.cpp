#include <iostream>
#include <string>

using namespace std;
/********************Enums***************************/
enum enLevel
{
    Easy = 1,
    Mid = 2,
    Hard = 3,
    levelMix = 4,
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
    char add;
    char sub;
    char mul;
    char div;
};
struct stModArrays
{
    int easy[10];
    int mid[20];
    int hard[50];
    int mix[50];
};

struct stGameChoices
{
    enLevel level;
    enOperations operation;
    stQuestions questios;
};

/********************Functions***************************/
void seprator()
{
    cout << "-----------------------" << endl;
};
void setQuestionNumbers(stQuestions &questions)
{
    cout << "How Many Question You Want ? : ";
    cin >> questions.questions;
}
void setquestiosLevel(stQuestions &level)
{
    cout << "What is The Level Of Querstions: [1]-> Easy| [2]-> Mid| [3]-> Hard| [4]-> Mix ? ";
    cin >> level.level;
}
enOperations setquestionOperation()
{
    short userChoice;
    cout << "What is The Level Of Querstions: [1]-> Add| [2]-> Sub| [3]-> Mult| [4]-> Divi| [5]-> Mix ? ";
    cin >> userChoice;
    return (enOperations)userChoice;
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
            arr[i] = randNumber(1, 10);
        }
    }
    else if (level.level == enLevel::Mid)
    {
        for (int i = 0; i < 50; i++)
        {
            arr[i] = randNumber(1, 20);
        }
    }
    else if (level.level == enLevel::Hard)
    {
        for (int i = 0; i < 50; i++)
        {
            arr[i] = randNumber(1, 50);
        }
    }
    else if (level.level == enLevel::levelMix)
    {
        // todo
    }
}

enOperations getMixLeve()
{
    short level = randNumber(1, 4);
    switch (level)
    {
    case 1:
        return enOperations::Add;
    case 2:
        return enOperations::Sub;
    case 3:
        return enOperations::Mul;

    default:
        return enOperations::Divi;
    }
}

void startGame()
{
    stGameChoices choices;
    setQuestionNumbers(choices.questios);
    cout << choices.questios.questions << endl;
    setquestiosLevel(choices.questios);
    cout << choices.questios.level << endl;
    cout << setquestionOperation();
}
int main()
{
    srand((unsigned)time(NULL));
    startGame();
    return 0;
}