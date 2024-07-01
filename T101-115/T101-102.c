int main() {
    char ch;

    printf("Enter a character: ");
    scanf(" %c", &ch); // Пробел перед %c для игнорирования пробелов и символов переноса строки

    // Преобразование регистра с использованием битовых операций
    ch ^= (1 << 5); // XOR с 32 (бинарно 00100000), чтобы менять регистр символа

    printf("Transformed character: %c\n", ch);

    return 0;
}