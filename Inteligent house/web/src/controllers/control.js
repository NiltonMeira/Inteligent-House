const lighting = require('../models/lighting');
const security = require('../models/security');

module.exports = {
    async users(req, res){
    res.render('../views/index');
    },

    async lightingInsert(req, res){
    // Recebe as informações do front-end
    const dados = req.body;
    console.log(dados);
    // Criando sala no banco de dados
    await lighting.create({
    FullHouse: dados.full_house,
    Room: dados.room,
    Bedroom: dados.bedroom,
    Kitchen: dados.kitchen
    });
     // Redirecionar para a página principal
     res.redirect('/control');
    }
    }  