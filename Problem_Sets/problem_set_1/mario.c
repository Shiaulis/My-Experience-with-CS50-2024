#include <cs50.h>
#include <stdio.h>

int get_height();
void draw_pyramids(int);
void draw_pyramid_line(int);
void draw_inset(int);

int main(void)
{
    int lower_bound = 1;
    int upper_bound = 8;
    int height = get_height(lower_bound, upper_bound);
    draw_pyramids(height);
}

// promts user for integer within given range
int get_height(int low, int up)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < low || height > up);

    return height;
}

// draws 2 pyramids with a give height
void draw_pyramids(int height)
{
    for (int line_number = 1; line_number <= height; line_number++)
    {
        int inset = height - line_number;
        draw_inset(inset);
        draw_pyramid_line(line_number);
        draw_inset(2);
        draw_pyramid_line(line_number);
        printf("\n");
    }
}

// draw pyramid line with a given length
void draw_pyramid_line(int length)
{
    for (int i = 1; i <= length; i++)
    {
        printf("#");
    }
}

// dra line of spaces with a given length
void draw_inset(int length)
{
    for (int i = 1; i <= length; i++)
    {
        printf(" ");
    }
}
