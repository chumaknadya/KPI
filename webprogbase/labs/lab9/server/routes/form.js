let express = require('express');
let router = express.Router();
const func = require("../module/func.js");
const storage = require("../module/storage.js");


router.get('/animals/form',func.checkAuth, (req, res, next) => {
    let animals = req.query;
    res.render('createAnimal',{animals});
});

router.post('/animals/form',(req,res,next) => {
    let arrayOfFacts=[];
    arrayOfFacts.push(req.body.fact1,req.body.fact2,req.body.fact3,req.body.fact4,req.body.fact5,req.body.fact6,req.body.fact7)
    let image = new Buffer(req.files.picture.data).toString('base64');
    let picture_type = req.files.picture.name.split(".");
    storage.create(req.body.breed,req.body.description,image,arrayOfFacts,picture_type[1],picture_type[0])
        .then( result => {
            if(req.files) {
                let image = req.files.picture;
                let imageName = image.name;
                console.log(imageName)
                image.mv('./public/images/'+ imageName, function(err) {
                    if (err) return res.render('500');
                        res.redirect('/');    
                    });
            }  
        })
        .catch(err => {
                console.log(err);
                res.render('500');
        });
   
});
router.post('/animals/:id',func.checkAuth,(req,res,next) => {
    console.log(req.body.id);
    storage.remove(parseInt(req.body.id))
        .then(result =>res.redirect('/'))
        .catch(err=> {
            console.log(err);
            res.render('500') 
        });
    
});
router.get('/animals/search',func.checkAuth, function(req, res, next) {
    let animals = req.query;
    res.render('search',{animals,user:req.user});
 
});
router.get('/search',func.checkAuth,function(req, res, next) {
    console.log("breed " + req.query.breed);
    storage.searchByBreed(req.query.breed)
        .then(animals => {
                console.log("Page #"+req.query.page||1);
                let link =`search?breed=${req.query.breed}&`;
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
        .catch(err => {
            console.log(err);
            res.render('500');
        })
});



module.exports = router;