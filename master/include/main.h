#include "ModbusRTU.h"
#include <SoftwareSerial.h>

#include "site.html" 
#include "functionsPROJECT.js" 
#include "jquery-3.6.0.min.js" 
#include "bootstrap.min.css" 

#include "ESP8266WebServer.h"   

#define SLAVE_ID 3
#define FIRST_REG 0 
#define REG_COUNT 1

void HTTP_connection();   
void functions();   
void ConfigJSON();          
void site_S();
void Jquer();
void bootstrapCSS();
void btnSITE(); 
void Button_Uout();
void Button_Upp();  
void Button_Iout(); 
void Button_Usp(); 
void InputA_read();
void InputD_read();
void OutputA_read();
void Output_D_read();
void OutputA_write();
void Output_D_write();
bool cb(Modbus::ResultCode event, uint16_t transactionId, void* data);
                                                                               

String Num = "Значение не введено";                                  
String ssidAP = "ESP";                                         
String passwordAP = "";                                       
ESP8266WebServer HTTP(80);                                     
IPAddress apIP(192, 168, 10, 1);                              
            
uint16_t AI_read[REG_COUNT];
uint16_t AO_read[REG_COUNT];          // Holding register, Analog outout, 16-bit
bool DI_read[REG_COUNT];
bool DO_read[REG_COUNT];
uint16_t AO_write[1];
bool DO_write[1];

bool FLAG_SubmitAuntefication = false;
bool slct1, slct2, slct3, slct4 = false;    

ModbusRTU mb;  