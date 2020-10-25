#include <stdio.h>
#include <string.h>

int main() {
    char str1[1000] = {};
    char word[16] = {};
    int words = 0;
    int num = 0;
    char c = 0;
    int count = 0;//计数器
    int numberRepetitions = 0;

    gets(str1);
    for (int i = 0;(c = str1[i]) != '\0';i++){
        if (c < 65 || (c > 90 && c < 97) || c > 122) words = 0;//判定要优化,已完成
        else if (words == 0){
            words = 1;
            num++;
        }
    }
    printf("它有%d个单词\n请输入检索的单词：",num);
    words = 0;
    scanf("%s",word);

    num = strlen(word);
    for (int i = 0;i < strlen(str1);){
        //判断字母个数是否相同
        for (int j = i;;j++){
            if ((str1[j] > 96 && str1[j] < 123) || (str1[j] > 64 && str1[j] < 91)){
                words++;
            }else if (words != num){
                i += ++words;
                words = 0;
                break;
            }else{//判断是否相同
                count = 0;
                for (int z = 0;z < num;z++){
                    if (word[z] != str1[i + z])break;
                    else count++;
                }
                i += ++words;
                words = 0;
                if (count != num) break;
                else numberRepetitions++;
        }
        }
        
    }
    printf("单词\"%s\"重复%d次",word,numberRepetitions);
    getchar();
    getchar();
    return 0;
}
