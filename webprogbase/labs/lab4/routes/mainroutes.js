var express = require('express');
var router = express.Router();
const modules  = require("../module/animals.js");

router.get('/', (req, res) => {
    res.render('index');
});
router.get('/animals/:id(\\d+)',(req, res) => {
    modules.getById(parseInt(req.params.id))
      .then(animal => {
          if (!animal) {
             res.sendStatus(404);
          } else {
            res.render('animal',{animal});
          }
      })
      .catch(err =>res.sendStatus(500) );
    });
router.get('/animals', (req, res, next) => {
  
    modules.getAll()
      .then( animals => {
         res.render('animals',{animals});
      })
      .catch(err => res.sendStatus(500));
});

module.exports = router;