/*
** EPITECH PROJECT, 2023
** Day 04
** File description:
** Task 06
*/

void my_sort_int_array(int *array, int size)
{
    int x = 0;
    int tmp = 0;
    int y = 0;

    while (x < size - 1) {
        if (array[x] > array[x + 1]) {
            tmp = array[x];
            array[x] = array[x + 1];
            array[x + 1] = tmp;
            y = 1;
        }
        x++;
        if (x == size - 1 && y) {
            x = 0;
            y = 0;
        }
    }
}
