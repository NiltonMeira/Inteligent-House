// Iniciando Route do Express
const express = require('express');
const route = express.Router();
// Importando os Controllers
const home = require('./src/controllers/home');

// Iniciando as rotas
route.get('/', home.pagInicialGet);

route.get('/login', home.loginGet);

route.get('/signIn', home.signinGet);

route.get('/control', home.controlGet);

module.exports = route;