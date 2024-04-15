// Importação
const Sequelize = require('sequelize');
const database = require('../config/db');

// Criando a tabela Sala
const users = database.define('Users', {
    IDUser: {
    type: Sequelize.INTEGER,
    autoIncrement: true,
    allowNull: false,
    primaryKey: true
    },
    Name: {
    type: Sequelize.STRING(50),
    allowNull: false
    },
    Email: {
    type: Sequelize.STRING(50),
    allowNull: false
    },
    Password: {
    type: Sequelize.STRING(50),
    allowNull: false
    }
});

// Exportando essa tabela
module.exports = users;