#define echopin 9
#define trigpin 10
long sure;
long uzaklik;
void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  Serial.begin(9600);
}

void loop() {
digitalWrite(trigpin, LOW); //İlk olarak trip pinimizi low durumunda başlatıyoruz.
delayMicroseconds(5); //5 Mikrosaniye(saniyenin milyonda biri) beklemesini belirtiyoruz.
digitalWrite(trigpin, HIGH); //Daha sonra pinimizin ses dalgası göndermesi için emir veriyoruz.
delayMicroseconds(10);
digitalWrite(trigpin, LOW);   //Yeni ses dalgası üretebilmesi için trig pinimizi pasif durumuna getiriyoruz.
sure = pulseIn(echopin, HIGH); //Gönderilen ses dalgasının geri dönmesindeki süre ölçülüyor.
uzaklik = sure /29.1/2; //Ölçütüğümüz süre uzaklığa çevriliyor.
if(uzaklik > 200){
uzaklik = 200;
}
Serial.print("Uzaklik "); 
Serial.print(uzaklik); //Ölçtüğümüz uzaklığımız bilgisayarımızda Seri Port Ekranı kısmına yazılıyor.
Serial.println(" CM "); 
delay(100); }
