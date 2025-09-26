#include <stdio.h>

typedef struct {
    char name[20];
    int score1;
    int score2;
} Student;

int average(Student s) {
    return (s.score1 + s.score2) / 2;
}

int main() {
    Student s = {"Kim", 90, 80};
    printf("%s avg = %d\n", s.name, average(s));
    return 0;
}
