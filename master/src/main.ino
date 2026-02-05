
#include "main.h"   

bool cb(Modbus::ResultCode event, uint16_t transactionId, void* data) {
  return true;
}

// Поднимаем хост и назначаем маршруты
void HTTP_connection()                                         
{           
  WiFi.mode(WIFI_AP);                                          //  Включаем режим точки доступа
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));  //  Маска сети
  WiFi.softAP(ssidAP.c_str(), passwordAP.c_str());             //  Подключение к точке доступа ssidAP с паролем paswordAP
  HTTP.on("/", site_S); 
  
  HTTP.on("/ConfigJSON", ConfigJSON);

  HTTP.on("/Button_Uout", Button_Uout);                      //  Формирование странички с данными для RadioButton1
  HTTP.on("/Button_Iout", Button_Iout);                      //  Формирование странички с данными для RadioButton2
  HTTP.on("/Button_Upp", Button_Upp);                      //  Формирование странички с данными для RadioButton3
  HTTP.on("/Button_Usp", Button_Usp); 
                     
  HTTP.on("/bootstrapCSS", bootstrapCSS);
  HTTP.on("/Jquer", Jquer);
  HTTP.on("/functions", functions);
  HTTP.on("/btnSITE", btnSITE);

  HTTP.begin();                                                //  Запускаем HTTP сервер
}   

void Button_Uout()                                            //     
{                                                              //                                        
  slct1 = true;                                                //  Ставим флаги в true в зависимости от того какой режим выбрали на форме web-сайта 
  slct2 = false;                                               //
  slct3 = false;                                               //
  slct4 = false;                                               //
                                                               //
  HTTP.send(200, "text/html", "OK");                         
}                                                              //
                                                              
void Button_Iout()                                            //
{                                                              //
  slct1 = false;                                               //  
  slct2 = true;                                                // 
  slct3 = false;                                               // 
  slct4 = false;                                               // 
                                                               // 
  HTTP.send(200, "text/html", "OK");                           //
}                                                              //
                                                               
void Button_Upp()                                            // 
{                                                              // 
  slct1 = false;                                               // 
  slct2 = false;                                               // 
  slct3 = true;                                                // 
  slct4 = false;                                               // 
                                                               // 
  HTTP.send(200, "text/html", "OK");                           // 
}                                                              // 
                                                                
void Button_Usp()                                            // 
{                                                              // 
  slct1 = false;                                               // 
  slct2 = false;                                               // 
  slct3 = false;                                               // 
  slct4 = true;                                                // 
                                                               // 
  HTTP.send(200, "text/html", "OK");                           // 
}        
                                  
void Jquer()
{
    HTTP.send(200, "text/json", Jquery);
}

void bootstrapCSS()
{
  HTTP.send(200, "text/css", BOOTSTRAPcss );
}

void functions()
{
  HTTP.send(200, "text/javascript", FUNCTIONS );
}

void btnSITE()                                                      
{    
  Num = HTTP.arg("num");                                                                                                   //
  
  if(slct2)                                                  
  {                                                          
    AO_write[0] = atoi(Num.c_str());
    OutputA_write();                           
  }                                                                                                                    //                                                          //                                                        //
  else if(slct4)                                                    
  {                                                           
    DO_write[0] = atoi(Num.c_str());
    Output_D_write();                            
  }    

  HTTP.send(200, "text/html", site); 
}

void site_S(){
  HTTP.send(200, "text/html", site);
}

void ConfigJSON() 
{    
  String json = "{";     
    json += "\"AI_read\":\"";
      json += AI_read[0];  
//    json += AI_read[1]; 
  json +=  "\",\"AO_read\":\"";
      json += AO_read[0];  
//     json += AO_read[1]; 
    json += "\",\"DI_read\":\"";
      json += DI_read[0];  
  json +=  "\",\"DO_read\":\"";
      json += DO_read[0];  
  json += "\"}";

  HTTP.send(200, "text/json", json);
}  

void InputA_read(){
    if (!mb.slave()) {    // Check if no transaction in progress
//    mb.writeHreg(SLAVE_ID, FIRST_REG, OutA, REG_COUNT, cb);
    mb.readIreg(SLAVE_ID, FIRST_REG, AI_read, REG_COUNT, cb);
    while(mb.slave()) { // Check if transaction is active
      mb.task();
      yield();
    }
  }
}

void OutputA_read(){
    if (!mb.slave()) {    // Check if no transaction in progress
    mb.readHreg(SLAVE_ID, FIRST_REG, AO_read, REG_COUNT, cb); 
    while(mb.slave()) { // Check if transaction is active
      mb.task();
      yield();
    }
  }
}

void InputD_read(){
    if (!mb.slave()) {    // Check if no transaction in progress
    mb.readIsts(SLAVE_ID, FIRST_REG, DI_read, REG_COUNT, cb);
    while(mb.slave()) { // Check if transaction is active
      mb.task();
      yield();
    }
  }
}

void Output_D_read(){
    if (!mb.slave()) {    // Check if no transaction in progress
    mb.readCoil(SLAVE_ID, FIRST_REG, DO_read, REG_COUNT, cb);
    while(mb.slave()) { // Check if transaction is active
      mb.task();
      yield();
    }
  }
}

void OutputA_write(){
    if (!mb.slave()) {    // Check if no transaction in progress
    mb.writeHreg(SLAVE_ID, FIRST_REG, AO_write, REG_COUNT, cb);
    while(mb.slave()) { // Check if transaction is active
      mb.task();
      yield();
    }
  }
}

void Output_D_write(){
    if (!mb.slave()) {    // Check if no transaction in progress
    mb.writeCoil(SLAVE_ID, FIRST_REG, DO_write, REG_COUNT, cb);
    while(mb.slave()) { // Check if transaction is active
      mb.task();
      yield();
    }
  }
}

void setup() {

  HTTP_connection(); 
  Serial.begin(9600);
  mb.begin(&Serial, 14);
  mb.master();
}

void loop() {
  InputA_read();
  OutputA_read();
  InputD_read();
  Output_D_read();
  HTTP.handleClient(); 
}
