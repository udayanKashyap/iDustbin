#include <Firebase_ESP_Client.h>

// Provide the token generation process info.
#include "addons/TokenHelper.h"
// Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

//database config details
#define API_KEY "AIzaSyD6-VygKdMQMI_H0eIAmCmmiTICTF6tERw"
#define USER_EMAIL "ankitsharmagh093@gmail.com"
#define USER_PASSWORD "ankit501"
#define DATABASE_URL "https://mini-project-6th-sem-7c942-default-rtdb.asia-southeast1.firebasedatabase.app"

// Variable to save USER UID
String uid;

// Variables to save database paths
String databasePath;

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

// Write float values to the database
void sendFloat(String path, float value){
  if (Firebase.RTDB.setFloat(&fbdo, path.c_str(), value)){
    Serial.print("Writing value: ");
    Serial.print (value);
    Serial.print(" on the following path: ");
    Serial.println(path);
    Serial.println("PASSED");
    Serial.println("PATH: " + fbdo.dataPath());
    Serial.println("TYPE: " + fbdo.dataType());
  }
  else {
    Serial.println("FAILED");
    Serial.println("REASON: " + fbdo.errorReason());
  }
}

/*
<script type="module">
  // Import the functions you need from the SDKs you need
  import { initializeApp } from "https://www.gstatic.com/firebasejs/10.10.0/firebase-app.js";
  // TODO: Add SDKs for Firebase products that you want to use
  // https://firebase.google.com/docs/web/setup#available-libraries

  // Your web app's Firebase configuration
  const firebaseConfig = {
    apiKey: "AIzaSyD6-VygKdMQMI_H0eIAmCmmiTICTF6tERw",
    authDomain: "mini-project-6th-sem-7c942.firebaseapp.com",
    databaseURL: "https://mini-project-6th-sem-7c942-default-rtdb.asia-southeast1.firebasedatabase.app",
    projectId: "mini-project-6th-sem-7c942",
    storageBucket: "mini-project-6th-sem-7c942.appspot.com",
    messagingSenderId: "1075242417542",
    appId: "1:1075242417542:web:2f8bfba0c3b714f8df4007"
  };

  // Initialize Firebase
  const app = initializeApp(firebaseConfig);
</script>
*/