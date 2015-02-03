#include "application.h"

int a =0;
char myIpAddress[24];
TCPClient webClient;
TCPServer webServer = TCPServer(80);

int test(String command) {
    return 0;
}



void setup() {
     IPAddress myIp = WiFi.localIP();
    sprintf(myIpAddress, "%d.%d.%d.%d", myIp[0], myIp[1], myIp[2], myIp[3]);
    Spark.function("test", test);
    Spark.variable("a", &a, INT);
    Spark.variable("ip", &myIpAddress, STRING);
    webServer.begin();
}

void loop() {
    if (webClient.connected() && webClient.available()) {
     serveWebpage();
  }
  else {
    webClient = webServer.available();
  }
}

void serveWebpage() {
  webClient.print("<html><body>Bubbina Uptime: ");
  webClient.print(millis()/1000);
  webClient.println(" seconds</body></html>\n\n");
  webClient.flush();
  webClient.stop();
}
