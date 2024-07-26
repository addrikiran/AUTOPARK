import { getAuth, signInWithEmailAndPassword } from "https://www.gstatic.com/firebasejs/10.12.0/firebase-auth.js";

// Initialize Firebase Auth
const auth = getAuth();

document.getElementById('loginForm').addEventListener('submit', async function (e) {
  e.preventDefault(); // Prevent the default form submission

  const email = document.getElementById('email').value;
  const password = document.getElementById('password').value;

  try {
    // Sign in the user with Firebase Auth
    const userCredential = await signInWithEmailAndPassword(auth, email, password);
    const user = userCredential.user;

    if (user) {
      console.log('User details:', user);
      alert('Login successful!');
      window.location.href = 'main.html'; // Redirect to the main page
    }
  } catch (error) {
    console.error('Error: ', error);
    alert(error.message);
  }
});
