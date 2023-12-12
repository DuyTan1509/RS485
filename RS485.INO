int signall = 2;
String add = "";
bool slave = true;
//bool Dkien = false;
String st = "";
String startflag = "";
String sender = "";
String receiver = "";
String cmd = "";
String data = "";
String stopflag = "";
void setup() 
{
  for (int i = 10; i < 14; i++) 
  {
    pinMode(i, OUTPUT);
  }
  pinMode(signall, OUTPUT);
  delay(10);
  digitalWrite(signall, LOW);
  Serial.begin(9600);
  pinMode(4, INPUT);
  delay(10);
  int digitalValue = digitalRead(4);
  if (digitalValue == 1) 
  {
    slave = true;
  } 
  else 
  {
    slave = false;
  }
  delay(10);
}
void ledon(int i, String st) 
{
  digitalWrite(i + 9, HIGH);
  delay(10);
  digitalWrite(signall, HIGH);
  Serial.println(st);
  delay(10);
  digitalWrite(signall, LOW);
  delay(10);
}
void ledoff(int i, String st) 
{
  digitalWrite(i + 9, LOW);
  delay(10);
  digitalWrite(signall, HIGH);
  Serial.println(st);
  delay(10);
  digitalWrite(signall, LOW);
  delay(10);
}
void loop() 
{
 
  while (Serial.available() > 0) 
  {
    char c = Serial.read();
    st += c;
    delay(2);
    //Dkien == true ;
  }
 // if (Dkien == true)
  
    st.trim();
    if (st != "") 
    {
      startflag = st.substring(0, 1);
      sender = st.substring(1, 2);
      receiver = st.substring(2, 3);
      cmd = st.substring(3, 4);
      int leng = st.length();
      int a = leng - 1;
      data = st.substring(4, a);
      stopflag = st.substring(a, leng);
      int intdata = data.toInt();
      if (startflag == "@" && stopflag == "#") 
      {
        if (slave == true && receiver == "1")
        {
          if (cmd == "B") 
          {
           ledon(intdata, st);
          } 
          else if (cmd == "T") 
          {
           ledoff(intdata,  st);
          }
      } 
      else if (slave == false  && receiver == "2") 
      {
        if (cmd == "B") 
        {
          ledon(intdata, st);
        } 
        else if (cmd == "T") 
        {
          ledoff(intdata, st);
        }
      }
    }
    st = "";
    //Dkien = false;
  }
  
}

