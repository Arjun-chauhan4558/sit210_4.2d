const firebaseConfig = {
    apiKey: "AIzaSyDxwZIyO24ZCJlDQvUzniKlfEO_W0PpSPg",
    authDomain: "sit210-d-task.firebaseapp.com",
    databaseURL: "https://sit210-d-task-default-rtdb.asia-southeast1.firebasedatabase.app",
    projectId: "sit210-d-task",
    storageBucket: "sit210-d-task.firebasestorage.app",
    messagingSenderId: "651315469302",
    appId: "1:651315469302:web:14e523285f38068c9185d7",
    measurementId: "G-YY5Q3CXKG3"
};

firebase.initializeApp(firebaseConfig);

const db = firebase.database();

function toggleLight(room) {

    const light = db.ref(room);

    light.once("value").then(function(snapshot) {

        const currentState = snapshot.val();

        light.set(!currentState);

    });
}