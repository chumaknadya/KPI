var express = require('express');
var router = express.Router();
const storage = require("../module/storage.js");
const func = require("../module/func.js");
const serverSalt = "45%sAlT_";
router.get('/animals/:id(\\d+)',func.checkAuth,(req, res) => {
    console.log(req.params.id)
    storage.getById(parseInt(req.params.id))
    .then(animal => {
           if(animal.length == 0) res.render(404);
          
           res.render('animal',{animal,user: req.user });
    })
    .catch(err=> {
        console.log(err)
        res.render(500)
    });
});
router.get('/animals', (req, res, next) => {
    storage.getAll()
        .then(animals => {
            console.log("Page #"+req.query.page||1);
            let link =`/animals?`;
            let currentPage = 1;
            if(req.query.page) {
                currentPage = parseInt(req.query.page);
            }
            if(animals == null || animals.slice((currentPage-1)*3, currentPage*3).length == 0) 
                res.render('404');
            res.render('animals',{
                animals: animals.slice((currentPage-1)*3, currentPage*3),
                length:animals.length,
                currentPage: currentPage,
                pageCount: Math.ceil(animals.length /3),
                link:link,
                user:req.user
            });
            
        })
        .catch(err=> {
            console.log(err)
            res.render(500)
        });
});

module.exports = router;