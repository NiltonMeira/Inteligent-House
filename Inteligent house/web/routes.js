// Iniciando Route do Express
const express = require('express');
const route = express.Router();
// Importando os Controllers
const home = require('./src/controllers/home');
const cadastro = require('./src/controllers/cadastro');
const login = require('./src/controllers/login')
const control = require('./src/controllers/control')

// Iniciando as rotas
route.get('/', home.pagInicialGet);
route.post('/cadastro', cadastro.usuarioInsert);

route.get('/login', home.loginGet);
route.post('/login', login. checkLogin);

route.get('/signIn', home.signinGet);

route.get('/control', home.controlGet);
route.post('/controlLight', control.lightingInsert);

module.exports = route;