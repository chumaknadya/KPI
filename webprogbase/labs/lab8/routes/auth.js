let express = require('express');
let router = express.Router();
const storage = require("../module/storage.js");
const func = require("../module/func.js")
const passport = require('passport');
const serverSalt = "45%sAlT_";


router.get('/register',(req, res) => {
    res.render('register');
});
router.post('/register',(req, res) => {
    let username = req.body.username;
    let pass = req.body.pass;
    let pass2 = req.body.pass2;
    let password = func.sha512(req.body.pass, serverSalt).passwordHash;
    let role = "user";
    if(pass === pass2){
        storage.identityUsernameCheck(username)
            .then(result => {
                if (result == 0) {
                    storage.createUser(role,username,password)
                        .then(() => {
                            res.redirect('/');
                        })
                } else res.render('register');
            })
    } else res.render('register');
           
  
});

router.get('/logout',func.checkAuth,(req, res) => {
    req.logout();
    res.redirect('/');
});
router.get('/admin',func.checkAuth,func.checkAdmin,(req, res) => {
    storage.getUsers()
        .then(users => {
            res.render('admin', {
                user: req.user,
                users: users
            });
        })
        .catch(() => res.render('500'));
});
router.get('/profile',func.checkAuth,(req, res) => {
    res.end('User profile page')
});


module.exports = router;