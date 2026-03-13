Tips for making code run a little faster:

Matrix optimization:

- When declaring a matrix, choose the smallest dimention first, because it avoids more cache misses.
- Exemple: [40][100] is better than mat[100][40]

Memory alocation:

- Use global variables and static alocated memory, they are a little faster

Operations:

- Division is a very slow operation, try to avoid if possible
