const users = require('../models/users');

module.exports = {
    async users(req, res){
    res.render('../views/index');
    },

    async usuarioInsert(req, res){
    // Recebe as informações do front-end
    const dados = req.body;
    console.log(dados);
    // Criando sala no banco de dados
    await users.create({
    Name: dados.name,
    Email: dados.email,
    Cpf: dados.cpf,
    Password: dados.password 
    });
    // Redirecionar para a página principal
    res.redirect('/control');
    }
    }  