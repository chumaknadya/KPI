const express = require('express');
const path = require('path');

const modules  = require("./module/animals.js");

let app = express();


// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');
//paths for static files
app.use('/public',express.static(__dirname + '/public'));


   
  

app.get('/', (req, res) => {
    res.render('index')
});

app.get('/animals/:id(\\d+)',(req, res) => {
    modules.getById(parseInt(req.params.id))
      .then(animal => {
          if (!animal) {
             res.sendStatus(404);
          } else {
            res.render('animal',{animal});
          }
      })
      .catch(err => console.log(err));
    });
app.get('/animals', (req, res, next) => {
  
   modules.getAll()
      .then( animals => {
         res.render('animals',{animals});
      })
      .catch(err => console.log(err));
});



app.use((req, res) => {
	res.send('Not Found');
});

const PORT = 3000;
app.listen(PORT, () => console.log(`server started at ${PORT}`));
