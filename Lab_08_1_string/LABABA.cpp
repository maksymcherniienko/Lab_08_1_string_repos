#include <iostream>
#include <string>
using namespace std;

// Функція Count приймає рядок s та повертає кількість входжень слова "while"
int Count(const string s)
{
    int k = 0; // Лічильник входжень
    size_t pos = 0;

    // Цикл пошуку 'w' у рядку s
    while ((pos = s.find('w', pos)) != -1)
    {
        pos++; // Збільшення позиції для пошуку наступного 'w'

        // Перевірка, чи слідом за 'w' йде 'h', 'i', 'l', 'e', якщо так, збільшуємо лічильник
        if (s[pos] == 'h' && s[pos + 1] == 'i' && s[pos + 2] == 'l' && s[pos + 3] == 'e')
            k++;
    }

    return k; // Повертаємо кількість входжень
}

// Функція Change приймає рядок s та модифікує його, замінюючи всі входження "while" на "***"
string Change(string& s)
{
    size_t pos = 0;

    // Цикл пошуку 'w' у рядку s
    while ((pos = s.find('w', pos)) != -1)
    {
        // Перевірка, чи слідом за 'w' йде 'h', 'i', 'l', 'e', якщо так, замінюємо "while" на "***"
        if (s[pos + 1] == 'h' && s[pos + 2] == 'i' && s[pos + 3] == 'l' && s[pos + 4] == 'e')
            s.replace(pos, 5, "***");
        else
            pos++; // Якщо 'while' не знайдено, збільшуємо позицію для пошуку наступного 'w'
    }

    return s; // Повертаємо модифікований рядок
}

// Головна функція програми
int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    // Виводимо кількість входжень "while" у введеному рядку
    cout << "String contained " << Count(str) << " groups of 'while'" << endl;

    // Модифікуємо рядок та виводимо його
    string dest = Change(str);
    cout << "Modified string (param): " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0; // Завершуємо програму
}
