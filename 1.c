#include <stdio.h>
#define N 5
typedef struct student {
    long sno;
    char name[10];
    float score[3];
} STU;
void fun(char *filename, STU n) {
    FILE *fp;
    // 第一处填空：打开文件，filename 是要操作的文件名
    fp = fopen(filename, "rb+");
    // 第二处填空：移动文件指针到最后一个学生数据的起始位置
    fseek(fp, -(long)sizeof(STU), SEEK_END);
    // 第三处填空：将新学生数据写入文件，fp 是文件指针
    fwrite(&n, sizeof(STU), 1, fp);
    fclose(fp);
}
void main() {
    STU t[N] = { {10001,"MaChao", 91, 92, 77},
                 {10002,"CaoKai", 75, 60, 88},
                 {10003,"LiSi", 85, 70, 78},
                 {10004,"FangFang", 90, 82, 87},
                 {10005,"ZhangSan", 95, 80, 88} };
    STU n = {10006,"ZhaoSi", 55, 70, 68}, ss[N];
    int i, j;
    FILE *fp;
    fp = fopen("student.dat", "wb");
    fwrite(t, sizeof(STU), N, fp);
    fclose(fp);
    fp = fopen("student.dat", "rb");
    fread(ss, sizeof(STU), N, fp);
    fclose(fp);
    printf("\nThe original data :\n\n");
    for (j = 0; j < N; j++) {
        printf("\nNo: %ld  Name: %-8s Scores: ", ss[j].sno, ss[j].name);
        for (i = 0; i < 3; i++) printf("%6.2f ", ss[j].score[i]);
        printf("\n");
    }
    fun("student.dat", n);
    printf("\nThe data after modifying :\n\n");
    fp = fopen("student.dat", "rb");
    fread(ss, sizeof(STU), N, fp);
    fclose(fp);
    for (j = 0; j < N; j++) {
        printf("\nNo: %ld  Name: %-8s Scores: ", ss[j].sno, ss[j].name);
        for (i = 0; i < 3; i++) printf("%6.2f ", ss[j].score[i]);
        printf("\n");
    }
}