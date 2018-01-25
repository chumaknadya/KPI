var express = require('express');
var router = express.Router();
const animalsStorage = require("../module/animalsStorage.js");

router.get('/', (req, res) => {
    
    res.render('index');
});
router.get('/animals/:id(\\d+)',(req, res) => {
    animalsStorage.getById(parseInt(req.params.id))
        .then(animal => {
               if(!animal) res.sendStatus(404);
               res.render('animal',{animal});
        })
});
router.get('/animals', (req, res, next) => {
     animalsStorage.getAll()
        .then(animals => {
            if(!animals) res.sendStatus(404);
            res.render('animals',{animals});
        })
});
module.exports = router;