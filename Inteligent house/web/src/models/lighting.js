const Sequelize = require('sequelize');
const database = require('../config/db');
const houses = require('../models/houses');

const lighting = database.define('Lighting', {
    IDLighting: {
        type: Sequelize.INTEGER,
        autoIncrement: true,
        allowNull: false,
        primaryKey: true
    },
    FullHouse: {
        type: Sequelize.BOOLEAN,
        allowNull: false
    },
    Room: {
        type: Sequelize.BOOLEAN,
        
        allowNull: false
    },
    Bedroom: {
        type: Sequelize.BOOLEAN,
        allowNull: false
    },
    Kitchen: {
        type: Sequelize.BOOLEAN,
        allowNull: false
    }
});

module.exports = lighting;    