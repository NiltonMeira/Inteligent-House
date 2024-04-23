const Sequelize = require('sequelize');
const database = require('../config/db');
const houses = require('../models/houses');

const sensors = database.define('Lighting', {
    IDSensors: {
        type: Sequelize.INTEGER,
        autoIncrement: true,
        allowNull: false,
        primaryKey: true
    },
    Temperature: {
        type: Sequelize.DOUBLE,
        allowNull: false
    },
    Humidity: {
        type: Sequelize.DOUBLE,
        allowNull: false
    }
});

module.exports = sensors;    