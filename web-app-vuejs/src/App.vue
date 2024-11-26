<script setup>
import { RouterLink, RouterView } from 'vue-router'
</script>

<template>
  <div class="app-layout">
    <nav class="sidebar">
      <div class="navbar-logo">
        <img src="./assets/logo.png" alt="Logo" />
      </div>
      <ul>
        <li>
          <RouterLink to="/">
            <span class="icon">🏠</span>
            <span class="text">Home</span>
          </RouterLink>
        </li>
        <li>
          <RouterLink to="/page2">
            <span class="icon">📄</span>
            <span class="text">Page 2</span>
          </RouterLink>
        </li>
      </ul>
    </nav>
    <main class="content">
      <RouterView />
    </main>
  </div>
</template>

<style scoped>
/* Reset the body margin */
body {
  margin: 0;
}

.app-layout {
  display: flex;
  height: 100vh;
  font-family: Arial, sans-serif;
}

.navbar-logo img {
  max-width: 150px; /* Adjust size as needed */
  height: auto;
  margin-bottom: 1rem;
  margin: 10px;
  margin-left: 1rem;
}

.sidebar {
  width: 250px;
  background-color: #cacaca;
  color: white;
  display: flex;
  flex-direction: column;
  padding: 1rem 0;
  box-shadow: 2px 0 5px rgba(0, 0, 0, 0.1);
}

.sidebar ul {
  list-style: none;
  padding: 0;
  margin: 0;
}

.sidebar ul li {
  margin: 0.5rem 0;
}

.sidebar ul li a {
  display: flex;
  align-items: center;
  gap: 10px;
  padding: 0.8rem 1rem;
  color: rgb(0, 0, 0);
  text-decoration: none;
  border-radius: 4px;
  transition: background-color 0.3s, transform 0.2s;
}

.sidebar ul li a:hover {
  background-color: #696969;
  transform: scale(1.05);
}

.sidebar ul li a .icon {
  font-size: 1.2rem;
}

.sidebar ul li a .text {
  font-size: 1rem;
}

.sidebar ul li a.router-link-active {
  background-color: #777777;
  font-weight: bold;
}

.content {
  flex-grow: 1;
  padding: 1rem;
  background-color: #f4f4f8;
  overflow-y: auto;
}
</style>
