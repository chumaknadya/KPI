const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const modules  = require("./module/animals.js");
const fileUpload = require('express-fileupload');
let  mainroutes = require('./routes/mainroutes');
let form = require('./routes/form');
let app = express();
let paginate = require('express-paginate');

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');
//paths for static files
app.use('/public',express.static(__dirname + '/public'));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(fileUpload());
app.use('/', mainroutes);
app.use('/',form);

app.use((req, res) => {
	res.send('Not Found');
});


const PORT = 3001;
app.listen(PORT, () => console.log(`server started at ${PORT}`));
