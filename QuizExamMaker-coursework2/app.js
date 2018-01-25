const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const storage = require("./modules/storage.js");
const func = require("./modules/func.js")
const fileUpload = require('express-fileupload');
let  tests = require('./routes/tests');
let api = require('./routes/api')
var mustache = require('mustache');
// new imports
const cookieParser = require('cookie-parser');
const session = require('express-session');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;
let paginate = require('express-paginate');
const serverSalt = "45%sAlT_";
let app = express();
require('dotenv').config();
app.use(cookieParser());
app.use(session({
	secret: "Some_secret^string",
	resave: false,
	saveUninitialized: true
}));
app.use(passport.initialize());
app.use(passport.session());

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');
//paths for static files
app.use('/public',express.static(__dirname + '/public'));
app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(fileUpload());

passport.serializeUser(function(user, done) {
    done(null, user.user_id);
});
passport.deserializeUser(function(id, done) {
	storage.getUserById(id)
   	    .then(user => {
            done(user ? null : false, user)
        })
        .catch(err=>{
            console.log(err);
        });
});

passport.use(new LocalStrategy((username, password, done) => {
    let hash = func.sha512(password, serverSalt).passwordHash;
    console.log("-------")
    console.log(username, password);
    storage.getUserByLoginAndPasshash(username, hash)
        .then(user => {
            done(user ? null : false, user);
        })
        .catch(err=>{
            console.log(err)
            
        })
}));
// new middleware
app.get('/',(req,res)=>{
    res.render('index',{user: req.user});
});
app.get('/users',func.checkAuth,func.checkAdmin,(req,res)=>{
    storage.getUsers()
        .then(users => {
            res.render('users',{users});
        })
        .catch(err=>{
            conole.log(err);
            res.senfStatus(500);
        })
   
});
app.get('/register',(req, res) =>{
    res.render('register', {user: req.user})
});
app.post('/register',(req, res) => {
    console.log(req.body);
    let username = req.body.username;
    let pass = req.body.password;
    let role = req.body.role;
    let email = req.body.email;
    let password = func.sha512(req.body.password, serverSalt).passwordHash;
    storage.identityUsernameCheck(username)
        .then(result => {
             if (result == 0) { 
                storage.createUser(username,role,email, password)
                    .then(() => {
                         res.redirect('/');
                    })
                    .catch(err=>{
                        console.log(err);
                        res.sendStatus(500);
                    })
            } else res.render('register');
        })
        .catch(err => {
            console.log(err);
            res.sendStatus(500);
        })
 })
   

app.get('/login',(req, res) =>{
    res.render('login', {user: req.user})
});
app.post('/login',
   passport.authenticate('local', {
       successRedirect: '/',
       failureRedirect: '/login',
}));
app.get('/logout',func.checkAuth,(req, res) => {
    req.logout();
    res.redirect('/');
})

app.get('/profile',func.checkAuth,(req, res) =>{
    storage.getAvatar(req.user.username)
        .then(result => {
            storage.getTestByUserId(parseInt(req.user.user_id))
            .then(tests=>{
                console.log("teeestss")
                console.log(tests)
                res.render('profile', {
                    user: req.user,
                    result,tests})
            })
            .catch(e => {
                res.sendStatus(500)
                console.log(e)
            })
         
        })
        .catch(err=> {
            console.log(err);
            res.sendStatus(500);
        })
   
});
app.post('/profile',func.checkAuth,(req, res) =>{
    console.log(req.user.username)
    let avatar = new Buffer(req.files.picture.data).toString('base64');
    let avatar_type = req.files.picture.name.split(".");
    storage.setAvatar(avatar,avatar_type[1],req.user.username)
        .then(results => res.redirect('/'))
        .catch(err=>{
            console.log(err);
            res.sendStatus(500);
        })       
});
app.use('/',api);



app.use('/', tests);
app.use((req, res) => {
	res.send('Not Found');
});



let port = process.env.PORT;
app.listen(port, () => console.log('up!'));