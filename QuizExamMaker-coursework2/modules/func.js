
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
    if (!req.user) res.sendStatus(401); // 'Not authorized'
    else if (req.user.role !== 'administrator') res.render('403'); // 'Forbidden'
    else next();  // пропускати далі тільки аутентифікованих із роллю 'admin'
}
function checkTeacher(){
    if (!req.user) res.redirect('/register'); // 'Not authorized'
    else if (req.user.role !== 'teacher') res.render('403'); // 'Forbidden'
    else next();  
}
function checkTeacherOrAdmin(){
    if (!req.user) res.redirect('/register'); // 'Not authorized'
    else if (req.user.role !== 'teacher' || req.user.role !== 'administrator') res.render('403'); // 'Forbidden'
    else next();  
}
module.exports = {
    sha512,
    checkAuth,
    checkAdmin,
    checkTeacher,
    checkTeacherOrAdmin

}