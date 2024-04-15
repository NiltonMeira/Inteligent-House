
const Sequelize = require('sequelize');
const database = require('../config/db');
const users = require('../models/users');

const houses = database.define('Houses', {
    IDHouse: {
    type: Sequelize.INTEGER,
    autoIncrement: true,
    allowNull: false,
    primaryKey: true
    },
    Name: {
    type: Sequelize.STRING(50),
    allowNull: false
    },
    Address: {
    type: Sequelize.STRING(50),
    allowNull: false
    }
});

houses.belongsTo(users, {
    foreignKey: 'IDUser'
});

module.exports = houses;