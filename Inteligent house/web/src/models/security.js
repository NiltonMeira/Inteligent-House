const Sequelize = require('sequelize');
const database = require('../config/db');

const security = database.define('Security', {
    IDSecurity: {
        type: Sequelize.INTEGER,
        autoIncrement: true,
        allowNull: false,
        primaryKey: true
    },
    Alarm: {
        type: Sequelize.BOOLEAN,
        allowNull: false
    },
    Gate: {
        type: Sequelize.BOOLEAN,
        allowNull: false
    },
    SoundAlarm: {
        type: Sequelize.BOOLEAN,
        allowNull: false
    },
    Door: {
        type: Sequelize.BOOLEAN,
        allowNull: false
    }
});

module.exports = security;    