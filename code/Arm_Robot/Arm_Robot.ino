#include <Servo.h>  // تضمين مكتبة التحكم في السيرفو

// تعريف المنافذ المستخدمة لكل محرك سيرفو
#define servo1 9  // القاعدة (Up/Down)
#define servo2 8  // الاتجاه (Left/Right)
#define servo3 7  // الامتداد للأمام/الخلف
#define servo4 6  // المقبض (Clamp)

Servo mservo1, mservo2, mservo3, mservo4;  // إنشاء كائنات السيرفو

// متغيرات الزوايا الحالية للمحركات
int srv1 = 100;
int srv2 = 0;
int srv3 = 80;
int srv4 = 0;

char Incoming_value = 0; // لحفظ القيمة القادمة من السيريال
char usechar = '0';      // الحرف الذي سيتم استخدامه للتحكم

void setup() {
  Serial.begin(9600);  // بدء الاتصال التسلسلي بسرعة 9600
  // ربط السيرفو بالمنافذ المحددة
  mservo1.attach(servo1); 
  mservo2.attach(servo2); 
  mservo3.attach(servo3); 
  mservo4.attach(servo4); 

  // تعيين المواضع الافتراضية عند بدء التشغيل
  mservo1.write(srv1); 
  mservo2.write(srv2); 
  mservo3.write(srv3); 
  mservo4.write(srv4); 
}

void loop() {
  // استقبال بيانات من منفذ السيريال
  if (Serial.available() > 0) {
    Incoming_value = Serial.read();
    usechar = Incoming_value;  // حفظ الحرف للتحكم
  }

  // التحكم في السيرفو 1 (القاعدة) لأعلى
  if (usechar == 'A' && srv1 < 150) {
    srv1++;
    mservo1.write(srv1);
    delay(10);
  }

  // التحكم في السيرفو 1 (القاعدة) لأسفل
  if (usechar == 'B' && srv1 > 50) {
    srv1--;
    mservo1.write(srv1);
    delay(10);
  }

  // السيرفو 2 (يمين)
  if (usechar == 'C' && srv2 < 180) {
    srv2++;
    mservo2.write(srv2);
    delay(10);
  }

  // السيرفو 2 (يسار)
  if (usechar == 'D' && srv2 > 0) {
    srv2--;
    mservo2.write(srv2);
    delay(10);
  }

  // السيرفو 3 (للأمام)
  if (usechar == 'G' && srv3 < 120) {
    srv3++;
    mservo3.write(srv3);
    delay(10);
  }

  // السيرفو 3 (للخلف)
  if (usechar == 'J' && srv3 > 40) {
    srv3--;
    mservo3.write(srv3);
    delay(10);
  }

  // السيرفو 4 (فتح المقبض)
  if (usechar == 'F' && srv4 < 35) {
    srv4++;
    mservo4.write(srv4);
    delay(10);
  }

  // السيرفو 4 (إغلاق المقبض)
  if (usechar == 'I' && srv4 > 0) {
    srv4--;
    mservo4.write(srv4);
    delay(10);
  }
}
