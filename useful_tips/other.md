This file contains useful tips for competitive programming
ALWAYS declare a matrix with the lower bound before, example: mat[40][100] is better than mat[100][40]
ALWAYS remember to use long long or long double, except in cases where you are already consuming a lot of space and the limits fit ina normal int
In problems that ask you to output a float, output with the precision asked for the problem or more, using cout<<fixed<<setprecision(x)<<float;
to compute a division MOD, con't make (n/y)%MOD, make (n*(MOD+x)/y)%MOD, this ensures that you are dividing the whole value, and not just the modulos by two, x is y - mod%y
Constant time optimization: use global variables and static alocated memory if possible
