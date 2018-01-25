var express = require('express');
var router = express.Router();
const modules  = require("../module/animals.js");



router.get('/animals/form', (req, res, next) => {
    let animals = req.query;
    res.render('createAnimal',{animals});
});

router.post('/animals/form', (req,res,next) => {
   let arrayOfFacts=[];
   arrayOfFacts.push(req.body.fact1,req.body.fact2,req.body.fact3,req.body.fact4,req.body.fact5,req.body.fact6,req.body.fact7)
   let animal = modules.Animal(modules.idGeneration(),req.body.breed,req.body.description,"../public/images/"+req.files.picture.name,arrayOfFacts);
    modules.create(animal)
         .then(animals =>console.log(animals.id))
   if(req.files) {
        let image = req.files.picture;
        let imageName = image.name;
        image.mv('./public/images/'+ imageName, function(err) {
            if (err) return res.sendStatus(500);
            res.redirect('/');
        });
    }  
});
router.post('/animals/:id',(req,res,next) => {
    console.log(req.body.id);
    modules.remove(parseInt(req.body.id))
    .then(animals => res.redirect('/'))
    .catch(err=>res.sendStatus(500));


});


router.get('/animals/search', function(req, res, next) {
     let animals = req.query;
     res.render('search',{animals});

});
router.get('/search',function(req, res, next) {

        modules.searchByBreed(req.query.breed)
         .then(animals => {
            console.log("breed " + req.query.breed);
            console.log("Page #"+req.query.page||1);
              let link =`search?breed=${req.query.breed}&`;
              console.log("------");
              console.log(animals);
              console.log("------");

            let currentPage = 1;
            if(req.query.page) {
                currentPage = parseInt(req.query.page);
            }
            console.log("CurrentPage "+ currentPage);
            console.log(  animals.slice((currentPage-1)*1, currentPage*1));
              res.render('filterArr',{
                    animals: animals.slice((currentPage-1)*1, currentPage*1),
                    length:animals.length,
                    currentPage: currentPage,
                    pageCount: Math.ceil(animals.length / 1),
                    link:link

                });

        })
});
module.exports = router;
