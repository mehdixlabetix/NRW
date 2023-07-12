import {initializeApp} from 'firebase/app';
import {getDatabase} from 'firebase/database';

const firebaseConfig={
    "apiKey": "AIzaSyAR7Hrs-GJPB2mQ_ycBBx1iP78THeQzLO8",
    "authDomain": "esp32-dht11-4833b.firebaseapp.com",
    "databaseURL": "https://esp32-dht11-4833b-default-rtdb.firebaseio.com",
    "projectId": "esp32-dht11-4833b",
    "storageBucket": "esp32-dht11-4833b.appspot.com",
    "messagingSenderId": "349487023088",
    "appId": "1:349487023088:web:1fbc373fe2d066cb0d9335",
    " measurementId": "G-28W8T1MN18"
}

const app = initializeApp(firebaseConfig);
export default getDatabase(app);