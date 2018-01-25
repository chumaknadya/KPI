
const crypto = require('crypto');

function sha512(password, salt){
    const hash = crypto.createHmac('sha512', salt);
    hash.update(password);
    const value = hash.digest('hex');
    return {
        salt: salt,
        passwordHash: value
    };
};
function checkAuth(req, res, next) {
    if (!req.user) return res.redirect('/register'); // 'Not authorized'
    next();  // пропускати далі тільки аутентифікованих
}

function checkAdmin(req, res, next) {
    if (!req.user) res.redirect('/register'); // 'Not authorized'
    else if (req.user.role !== 'admin') res.render('403'); // 'Forbidden'
    else next();  // пропускати далі тільки аутентифікованих із роллю 'admin'
}
module.exports = {
    sha512,
    checkAuth,
    checkAdmin

}