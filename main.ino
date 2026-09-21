#define ENABLE_USER_AUTH
#define ENABLE_DATABASE

#include <WiFiNINA.h>
#include <WiFiSSLClient.h>
#include <FirebaseClient.h>

// Wi-Fi
#define WIFI_SSID "oneplus12"
#define WIFI_PASSWORD "arjun123"

// Firebase
#define API_KEY "AIzaSyDxwZIyO24ZCJlDQvUzniKlfEO_W0PpSPg"

#define USER_EMAIL "arjunchauhan2721@gmail.com"
#define USER_PASSWORD "arjun123"

#define DATABASE_URL "https://sit210-d-task-default-rtdb.asia-southeast1.firebasedatabase.app"

// LED pins
const int livingRoom = 4;
const int bathroom = 5;
const int closet = 6;

// Firebase
UserAuth user_auth(
  API_KEY,
  USER_EMAIL,
  USER_PASSWORD
);

FirebaseApp app;

WiFiSSLClient ssl_client;

using AsyncClient = AsyncClientClass;

AsyncClient aClient(ssl_client);

RealtimeDatabase Database;

void setup() {

  Serial.begin(115200);

  pinMode(livingRoom, OUTPUT);
  pinMode(bathroom, OUTPUT);
  pinMode(closet, OUTPUT);

  digitalWrite(livingRoom, LOW);
  digitalWrite(bathroom, LOW);
  digitalWrite(closet, LOW);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.println("Wi-Fi connected");

  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  initializeApp(
    aClient,
    app,
    getAuth(user_auth),
    120000
  );

  app.getApp<RealtimeDatabase>(Database);

  Database.url(DATABASE_URL);

  Serial.println("Firebase initialized");
}

void loop() {

  app.loop();

  if (app.ready()) {

    bool living = Database.get<bool>(
      aClient,
      "/livingroom"
    );

    bool bath = Database.get<bool>(
      aClient,
      "/bathroom"
    );

    bool closetState = Database.get<bool>(
      aClient,
      "/closet"
    );

    digitalWrite(
      livingRoom,
      living ? HIGH : LOW
    );

    digitalWrite(
      bathroom,
      bath ? HIGH : LOW
    );

    digitalWrite(
      closet,
      closetState ? HIGH : LOW
    );

    Serial.print("Living Room: ");
    Serial.println(living);

    Serial.print("Bathroom: ");
    Serial.println(bath);

    Serial.print("Closet: ");
    Serial.println(closetState);

    delay(1000);
  }
}