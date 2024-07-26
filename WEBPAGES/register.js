// register.js

import { getAuth, createUserWithEmailAndPassword } from "https://www.gstatic.com/firebasejs/10.12.0/firebase-auth.js";
import { getFirestore, doc, setDoc } from "https://www.gstatic.com/firebasejs/10.12.0/firebase-firestore.js";

// Ensure Firebase is initialized
const { auth, db } = window.firebaseConfig;

document.getElementById('registerForm').addEventListener('submit', async function (e) {
  e.preventDefault(); // Prevent the default form submission

  const name = document.getElementById('name').value;
  const email = document.getElementById('email').value;
  const password = document.getElementById('password').value;

  try {
    // Register user with Firebase Auth
    const userCredential = await createUserWithEmailAndPassword(auth, email, password);
    const user = userCredential.user;

    // Save additional user info in Firestore
    await setDoc(doc(db, 'users', user.uid), {
      name: name,
      email: email
    });

    alert('User registered successfully!');
    window.location.href = 'login.html'; // Redirect to login page
  } catch (error) {
    console.error('Error: ', error);
    alert(error.message);
  }
});
