const { where } = require('sequelize');
const lighting = require('../models/lighting');
const security = require('../models/security');

module.exports = {
    async lightingInsert(req, res) {
        const currrentId = 1;
        const findedLight = await lighting.findOne({
            raw: true,
            attributes: ['IDLighting'],
            where: {IDLighting: currrentId}
        });
        // Recebe as informações do front-end
        const dados = req.body; 
        console.log(dados);
        // Criando sala no banco de dados

        if (findedLight)
        {
            await lighting.update({
                FullHouse: dados.full_house === 'on',
                Room: dados.main_room === 'on',
                Bedroom: dados.bedroom === 'on',
                Kitchen: dados.kitchen === 'on'
            },{
                where:
                {
                    IDLighting: currrentId
                }
            });
        }

        else{

            await lighting.create({
                FullHouse: dados.full_house === 'on',
                Room: dados.main_room === 'on',
                Bedroom: dados.bedroom === 'on',
                Kitchen: dados.kitchen === 'on'
            });
        }
        // Redirecionar para a página principal
        res.redirect('/control');
    },

    async securityInsert(req, res) {
        const currrentId = 1;
        const findedSec = await security.findOne({
            raw: true,
            attributes: ['IDSecurity'],
            where: {IDSecurity: currrentId}
        });
        // Recebe as informações do front-end
        const dados = req.body; 
        console.log(dados);
        // Criando sala no banco de dados

        if (findedSec)
        {
            await security.update({
                Alarm: dados.alarm === 'on',
                Room: dados.door === 'on',
                Bedroom: dados.gate === 'on',
                Kitchen: dados.sound_alarm === 'on'
            },{
                where:
                {
                    IDSecurity: currrentId
                }
            });
        }

        else{

            await security.create({
                FullHouse: dados.alarm === 'on',
                Room: dados.door === 'on',
                Bedroom: dados.gate === 'on',
                Kitchen: dados.sound_alarm === 'on'
            });
        }
        // Redirecionar para a página principal
        res.redirect('/control');
    }
}  