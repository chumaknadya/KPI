var express = require('express');
var router = express.Router();
const animalsStorage = require("../module/animalsStorage.js");


router.get('/animals/form', (req, res, next) => {
    let animals = req.query;
    res.render('createAnimal',{animals});
});

router.post('/animals/form', (req,res,next) => {
    //src="data:image/<%=i.picture_type%>;base64,<%=i.picture%>"
    //"<%=i.picture%>"
     let image = new Buffer(req.files.picture.data).toString('base64');
     let picture_type = req.files.picture.name.split(".");
   //"../public/images/"+req.files.picture.name
    let arrayOfFacts=[];
    arrayOfFacts.push(req.body.fact1,req.body.fact2,req.body.fact3,req.body.fact4,req.body.fact5,req.body.fact6,req.body.fact7)
    animalsStorage.create(req.body.breed,req.body.description,image,arrayOfFacts,picture_type[1])
        .then( result => {
            if(result) {
                res.redirect('/');
            //     if(req.files) {
            //         let image = req.files.picture;
            //         let imageName = image.name;
            //         image.mv('./public/images/'+ imageName, function(err) {
            //         if (err) return res.sendStatus(500);
            //             res.redirect('/');    
            //         });
            //     } 
            } else throw(err);
           

        })
        .catch(err => {
                console.log(err);
                res.sendStatus(500);
        });
   
});
router.post('/animals/:id',(req,res,next) => {
    console.log(req.body.id);
    animalsStorage.remove(parseInt(req.body.id))
        .then(result => {
            if(result) res.redirect('/')
            else trow(err);
        })
        .catch(err=>{
            console.log(err);
            res.sendStatus(505);
        });
       
});
router.get('/animals/search', function(req, res, next) {
    let animals = req.query;
    res.render('search',{animals});
 
});
router.get('/search',function(req, res, next) {
    console.log("breed " + req.query.breed);
    animalsStorage.searchByBreed(req.query.breed)
        .then(animals => {
                console.log("Page #"+req.query.page||1);
                let link =`search?breed=${req.query.breed}&`;
                let currentPage = 1;
                if(req.query.page) {
                    currentPage = parseInt(req.query.page);
                }
                res.render('filterArr',{
                    animals: animals.slice((currentPage-1)*1, currentPage*1),
                    length: animals.length,
                    currentPage: currentPage,
                    pageCount: Math.ceil(animals.length / 1),
                    link:link
                });
        })
        .catch(err => {
            console.log(err);
            res.sendStatus(500);
        })
});
module.exports = router;