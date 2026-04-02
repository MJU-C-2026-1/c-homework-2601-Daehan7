/* 
  파일이름: main.c
  작 성 자: 장대한
  하 는 일: 이용자의 정보를 받은 후 BMI 계산과 예상 기초대사령(BMR) 계산
*/

int main() {

  char name[20]; //이용자의 이름
  int age; //나이
  char gender; //성별
  double height, weight, bmi, bmr; //처음부터 키, 몸무게, BMI, BMR

  printf("--- 안녕하세요 BMI, BMR 계산기입니다. ---\n")
  printf("당신의 이름은 무엇입니까? : ");
  scanf(%s, &name);
  printf("당신의 성별은 무엇인가요?(M/W로 입력해주세요) : ');
  scanf(%s, &gender);
  printf("나이, 키(cm), 몸무게(kg)를 순서대로 입력해주세요. : ")
  scanf(%d %lf %lf, &age, &height, &weight);
  
  double height_m;
  height_m = height / 100.0;
  bmi = weight / (height_m * height_m);
  bmr = 10 * weight + 6.25 * height - 5 * age + 5;

  printf("\n--- %s님의 분석 결과입니다. ---\n", name);
  printf("성별: %s / 나이 %d\n", gender, age);
  printf("현재 BMI 지수: %.2f\n", bmi);
  printf("현재 예상 기초 대사량(BMR): %.2f kcal\n", bmr);

  return 0;
}
  
  
