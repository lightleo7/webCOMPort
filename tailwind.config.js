/** @type {import('tailwindcss').Config} */
module.exports = {
	darkMode: 'class',
  content: [
    "./*.{html,js}",
    "./node_modules/flowbite/**/*.js"  // Добавьте эту строку
  ],
  theme: {
    extend: {},
  },
  plugins: [
    require('flowbite/plugin')  // Добавьте плагин Flowbite
  ],
}