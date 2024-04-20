global.currentUser;
const user = require("../models/users");

module.exports = {
    async checkLogin(req, res){
        const email = req.body.email;
        const password = req.body.password;
        let resultado = true;

        const findedPerson = await user.findOne({
            raw: true,
            attributes: ['IDUser', 'Email', 'Password'],
            where: {Email: email, Password: password}
        });

        if(findedPerson){
            console.log("Login Efetuado")
            res.redirect('/control')
            currentUser = findedPerson.IDUser;
            console.log("User: ");
            console.log(currentUser);
        }
        else{
            resultado = false
            console.log("Senha Incorreta")
            res.render("../views/login", {resultado});
        }
        
        
    }
}