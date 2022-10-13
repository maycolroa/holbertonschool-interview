#ifndef _slide_line_H_
#define _slide_line_H_
#include <stdlib.h>
#include <stdio.h>
#define SLIDE_RIGHT 1
#define SLIDE_LEFT 0
/**
 * slide_line - function that slides and merges an array of integers.
 * @line: points
 * @size: elements
 * @direction: represented by direction
 * Return: 1, or 0.
 *
 */
int slide_line(int *line, size_t size, int direction);
#endif /* _slide_line_H_ */
