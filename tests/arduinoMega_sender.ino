String f;
char ch1 = '0';
char ch2 = '1';

void setup() {
  Serial.begin(9600);
  Serial3.begin(115200);
  Serial.println("Initialized.\n");
}
void loop() {
  f = "<" + ch1;
  f = f + ",";
  f = f + ch2;
  f = f + ">";
//f="<28,23>";
  Serial3.println(f);
  Serial.println(f);
  delay(1000);
  ch1++; ch2++;
}
