#include<stdio.h>
struct pancake {
   int d;     //팬 케이크의 크기
   int p;     //팬 케이크의 위치
};

int maximum(int arr[30], int n)   //해당 배열에서 가장 큰 값 찾아줌
{
   int max = 0;     //가장 큰 값
   int maxlo = 0;    //가장 큰 값의 위치
   for (int i = 0; i < n; i++)
   {
      if (arr[i] > max) {
         max = arr[i];
         maxlo = i;
      }
   }
   return maxlo;    //반환은 가장 큰 값으로 반환
}

void flip(int* arr, int index)    //숫자 뒤집기
{
   int temp;
   for (int i = 0; i <= index/2; i++)
   {
      temp = arr[i];             
      arr[i] = arr[index - i];
      arr[index - i] = temp;
   }
}

int main(void)
{
   int cake[30] = {0};
   int len = 0;   //팬 케이크의 개수
   
   while(1)
   {
      scanf("%d", &cake[len]);
      if (cake[len] < 0)
      {
         break;
      }
      len++;
   }    //팬 케이크 입력과 동시에 개수 저장.
   printf("length: %d\n", len);

   int maxpos;   //max값이 저장된 위치 가장 큰 팬케이크의 위치가 저장되어 있음
   
   int cursor = len;   //max값이 어디 저장되어야 하는지 값 지정, max값 하나가 bottom으로 하나 씩 갈수록 값이 증가함.

   int res[100] = {0,};    //결과 저장 배열

   int i = 0;    //결과 저장 배열의 반복용 변수

   while (cursor != 1)    //만약 커서가 1에 왔다면, 종료. 커서는 배열의 크기부터 1까지 수가 제대로 초기화 될 경우 움직인다.
   {      
      maxpos = maximum(cake, cursor);    //가장 큰 값을 찾음

      if (maxpos == cursor - 1)   //만약 가장 큰 값이랑 커서의 위치가 같다면, ex) 1 3 5 2 5 7 의 경우 7을 이동시킬 필요가 없음
      {
         cursor--;   //커서는 6으로 보내줌
         continue;    //아무 일 없이 패스
      }
      else if (maxpos == 0)   //만약 가장 큰 수의 위치가 0이면(처음이면) 이미 탑으로 보냈으니 바닥으로만 보내면 됨
      {
         cursor--;    //일단 커서 줄여줌
         flip(cake, cursor);    //팬케이크를 커서의 위치로 보내줌
         res[i] = len - cursor;   //결과값 저장
         i++;
      }
      else if (maxpos != cursor) //가장 큰 케잌은 바닥에 있지도 커서에 있지도 않다. 젤 위로 보낸 뒤 다시 뒤집어서 커서위치로 보내줌
      {
         flip(cake, maxpos);   //탑으로 케잌 보내줌
         res[i] = len - maxpos;   //결과저장
         i++;
         cursor--;
         maxpos = maximum(cake, cursor);    
         flip(cake, cursor); //탑에 있는 케잌을 다시 커서로 보내줌
         res[i] = len - cursor;
         i++;
      }
   }
   res[i] = 0;

   for (int j = 0; j<=i; j++)
   {
      printf("%-5d", res[j]);
   }
}