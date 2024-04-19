module.exports = {
    async pagInicialGet(req, res) {
        res.render('../views/index');
    },

    async loginGet(req, res) {
        res.render('../views/login');
    },

    async signinGet(req, res) {
        res.render('../views/signin');
    },

    async controlGet(req, res) {
        res.render('../views/control');
    }
}
