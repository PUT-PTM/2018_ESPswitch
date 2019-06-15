#include <ESP8266WiFi.h>
 
const char* ssid = "";
const char* password = "";
 
int Pin1 = 5; // GPIO5----D1 of NodeMCU
int Pin2 = 4; // GPIO4----D2 of NodeMCU
int Pin3 = 0; // GPIO0----D3 of NodeMCU
int Pin4 = 16; // GPIO16--D0 of NodeMCU
int Pin5 = 14; // GPIO14--D5 of NodeMCU
int Pin6 = 12; // GPIO12--D6 of NodeMCU
int Pin7 = 13; // GPIO13--D7 of NodeMCU

WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  pinMode(Pin5, OUTPUT);
  pinMode(Pin6, OUTPUT);
  pinMode(Pin7, OUTPUT);
  digitalWrite(Pin1, HIGH);
 digitalWrite(Pin2, HIGH);
 digitalWrite(Pin3, HIGH);
 digitalWrite(Pin4, HIGH);
 digitalWrite(Pin5, HIGH);
 digitalWrite(Pin6, HIGH);
 digitalWrite(Pin7, HIGH);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  int value = HIGH;
  
    if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, HIGH);
    digitalWrite(Pin3, HIGH);
    digitalWrite(Pin4, HIGH);
    digitalWrite(Pin5, HIGH);
    digitalWrite(Pin6, HIGH);
    digitalWrite(Pin7, HIGH);
    
    value = HIGH;
  }  
    if (request.indexOf("/LED=0") != -1)  {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
    digitalWrite(Pin4, LOW);
    digitalWrite(Pin5, LOW);
    digitalWrite(Pin6, LOW);
    digitalWrite(Pin7, HIGH);
    
    value = HIGH;
  }
  if (request.indexOf("/LED=1") != -1)  {
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
    digitalWrite(Pin4, HIGH);
    digitalWrite(Pin5, HIGH);
    digitalWrite(Pin6, HIGH);
    digitalWrite(Pin7, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=2") != -1)  {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, HIGH);
    digitalWrite(Pin4, LOW);
    digitalWrite(Pin5, LOW);
    digitalWrite(Pin6, HIGH);
    digitalWrite(Pin7, LOW);
    value = HIGH;
  }
  if (request.indexOf("/LED=3") != -1)  {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
    digitalWrite(Pin4, LOW);
    digitalWrite(Pin5, HIGH);
    digitalWrite(Pin6, HIGH);
    digitalWrite(Pin7, LOW);
    value = HIGH;
  }
  if (request.indexOf("/LED=4") != -1)  {
    digitalWrite(Pin1, HIGH);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
    digitalWrite(Pin4, HIGH);
    digitalWrite(Pin5, HIGH);
    digitalWrite(Pin6, LOW);
    digitalWrite(Pin7, LOW);
    value = HIGH;
  }
  if (request.indexOf("/LED=5") != -1)  {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, HIGH);
    digitalWrite(Pin3, LOW);
    digitalWrite(Pin4, LOW);
    digitalWrite(Pin5, HIGH);
    digitalWrite(Pin6, LOW);
    digitalWrite(Pin7, LOW);
    value = HIGH;
  }
  if (request.indexOf("/LED=6") != -1)  {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, HIGH);
    digitalWrite(Pin3, LOW);
    digitalWrite(Pin4, LOW);
    digitalWrite(Pin5, LOW);
    digitalWrite(Pin6, LOW);
    digitalWrite(Pin7, LOW);
    value = HIGH;
  }
  if (request.indexOf("/LED=7") != -1)  {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
    digitalWrite(Pin4, HIGH);
    digitalWrite(Pin5, HIGH);
    digitalWrite(Pin6, HIGH);
    digitalWrite(Pin7, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=8") != -1)  {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
    digitalWrite(Pin4, LOW);
    digitalWrite(Pin5, LOW);
    digitalWrite(Pin6, LOW);
    digitalWrite(Pin7, LOW);
    value = HIGH;
  }
  if (request.indexOf("/LED=9") != -1)  {
    digitalWrite(Pin1, LOW);
    digitalWrite(Pin2, LOW);
    digitalWrite(Pin3, LOW);
    digitalWrite(Pin4, LOW);
    digitalWrite(Pin5, HIGH);
    digitalWrite(Pin6, LOW);
    digitalWrite(Pin7, LOW);
    value = HIGH;
  }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led is now: ");
 
  if((digitalRead(Pin1)==LOW)||(digitalRead(Pin2)==LOW)||(digitalRead(Pin3)==LOW)||(digitalRead(Pin4)==LOW)||(digitalRead(Pin5)==LOW)||(digitalRead(Pin6)==LOW)||(digitalRead(Pin7)==LOW))  
  {
    client.print("On");
  } 
  else 
  {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=OFF\"\"><button style=>OFF </button></a><br />");
  client.println("<a href=\"/LED=0\"\"><button>0 </button></a>");
  client.println("<a href=\"/LED=1\"\"><button>1 </button></a>");
  client.println("<a href=\"/LED=2\"\"><button>2 </button></a>");
  client.println("<a href=\"/LED=3\"\"><button>3 </button></a>");
  client.println("<a href=\"/LED=4\"\"><button>4 </button></a>");
  client.println("<a href=\"/LED=5\"\"><button>5 </button></a>");
  client.println("<a href=\"/LED=6\"\"><button>6 </button></a>");
  client.println("<a href=\"/LED=7\"\"><button>7 </button></a>");
  client.println("<a href=\"/LED=8\"\"><button>8 </button></a>");
  client.println("<a href=\"/LED=9\"\"><button>9 </button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
