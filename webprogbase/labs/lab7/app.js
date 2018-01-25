const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const storage = require("./module/storage.js");
const func = require("./module/func.js")
const fileUpload = require('express-fileupload');
let  mainroutes = require('./routes/mainroutes');
let auth = require ('./routes/auth');
let form = require('./routes/form');
let api = require('./routes/api')
// new imports
const cookieParser = require('cookie-parser');
const session = require('express-session');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;
let paginate = require('express-paginate');
const serverSalt = "45%sAlT_";
let app = express();

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

// new middleware
app.get('/',(req,res)=>{
    res.render('index',{user: req.user});
})
app.get('/login',(req, res) =>{
    res.render('login', {user: req.user})
});
app.post('/login',
   passport.authenticate('local', {
       successRedirect: '/',
       failureRedirect: '/login',
}));

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

app.use('/', mainroutes);
app.use('/',form);
app.use('/',auth);
app.use('/',api);
app.use((req, res) => {
	res.send('Not Found');
});




const PORT = 3000;
app.listen(PORT, () => console.log(`server started at ${PORT}`));
