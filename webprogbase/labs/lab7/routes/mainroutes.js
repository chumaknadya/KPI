var express = require('express');
var router = express.Router();
const storage = require("../module/storage.js");
const func = require("../module/func.js");
router.get('/animals/:id(\\d+)',func.checkAuth,(req, res) => {
    storage.getById(parseInt(req.params.id))
    .then(animal => {
           if(animal.length == 0) res.sendStatus(404);
           res.render('animal',{animal,user: req.user });
    })
    .catch(err=> {
        console.log(err)
        res.sendStatus(500) 
    });
});
router.get('/animals', (req, res, next) => {
    storage.getAll()
        .then(animals => {
            res.render('animals',{animals,user: req.user});
        })
        .catch(err=> {
            console.log(err)
            res.sendStatus(500) 
        });
});

module.exports = router;