var express = require('express');
const apiRouter = express.Router();
const storage = require("../module/storage.js");
const func = require("../module/func.js")
var auth = require('basic-auth')
const serverSalt = "45%sAlT_";
const crypto = require('crypto');
function isAppropriateURL(element, index, array) {
    if(element == "breed" || element =="page") {
        return true;
    }
}
function isAppropriateUrlUser(element, index, array) {
    if(element == "username" || element =="page") {
        return true;
    }
}
apiRouter.get('/api/v1/animals/:id(\\d+)',async(req, res) => {
    let user = auth(req);
    if(!user) res.status(401).json({ message: "Requires authentication"});
    let hash = func.sha512(user.pass, serverSalt).passwordHash;
    let identity = await storage.getUserByLoginAndPasshash(user.name,hash);
    console.log(identity);
    if (identity != null) {
        storage.getById(parseInt(req.params.id))
            .then(animal => {
                if(animal == null) res.status(404).json({message: "Resource not found, but it may be available in the future" });
                res.json(animal);
            })
            .catch(err => res.sendStatus(500).json({ error: err }));
    }else res.status(401).json({ message: "Requires authentication"});
});

apiRouter.get('/api/v1/animals', async(req, res, next) => {
    let user = auth(req);
    if(!user) res.status(401).json({ message: "Requires authentication"});
    let hash = func.sha512(user.pass, serverSalt).passwordHash;
    let identity = await storage.getUserByLoginAndPasshash(user.name,hash);
    if (identity != null) {
            // let animals = await storage.getAll();
            // if(Object.keys(req.query).length != 0 && req.query.breed) {
            //      animals = await storage.searchByBreed(req.query.breed);
            // } 
            // if(Object.keys(req.query).every(isAppropriateURL)){
            //     console.log("Page #"+req.query.page||1);
            //     let currentPage = 1;
            //     if(req.query.page) currentPage = parseInt(req.query.page);
            //     if(animals == null || animals.slice((currentPage-1)*3, currentPage*3).length == 0) 
            //         res.status(404).json({ message: "Resource not found, but it may be available in the future" });
            //     else res.json(animals.slice((currentPage-1)*3, currentPage*3));  
            // } else res.status(404).json({ message: "Resource not found, but it may be available in the future" });
            animals = await storage.searchByBreed(req.query.breed);
            res.json(animals)
    }else res.status(401).json({ message: "Requires authentication"});
});
apiRouter.get('/api/v1/users',async(req, res) => {
    let user = auth(req);
    if(!user) res.status(401).json({ message: "Requires authentication"});
    let hash = func.sha512(user.pass, serverSalt).passwordHash;
    let identity = await storage.getUserByLoginAndPasshash(user.name,hash);
    if (identity != null) {
        if(identity.role == "admin"){
                let users = await storage.getUsers();
                if(Object.keys(req.query).length != 0 && req.query.username) {
                    users = await storage.getUserByUsername(req.query.username);
                } 
                if(Object.keys(req.query).every(isAppropriateUrlUser)){
                    console.log("Page #"+req.query.page||1);
                    let currentPage = 1;
                    if(req.query.page) currentPage = parseInt(req.query.page);
                    if(users == null || users.slice((currentPage-1)*6, currentPage*6).length == 0) 
                        res.status(404).json({ message: "Resource not found, but it may be available in the future" });
                    res.json(users.slice((currentPage-1)*6, currentPage*6));      
                } else res.status(404).json({ message: "Resource not found, but it may be available in the future" });
        } else res.status(403).json({ message: "No access to the resource"});
    } else res.status(401).json({ message: "Requires authentication"});
    
});
apiRouter.get('/api/v1/animals/search',async(req, res, next) => {
    if(Object.keys(req.query).length === 0) res.status(400).json({ message: "There is no params"}); 
    console.log("breed " + req.query.breed);
    let user = auth(req);
    if(!user) res.status(401).json({ message: "Requires authentication"});
    let hash = func.sha512(user.pass, serverSalt).passwordHash;
    let identity = await storage.getUserByLoginAndPasshash(user.name,hash);
    if (identity != null) {
        storage.searchByBreed(req.query.breed)
            .then(animals => {
                    console.log("Page #"+req.query.page||1);
                    let currentPage = 1;
                    if(req.query.page) {
                        currentPage = parseInt(req.query.page);
                    } 
                    if(animals == null || animals.slice((currentPage-1)*6, currentPage*6).length == 0) 
                        res.status(404).json({ message: "Resource not found, but it may be available in the future" });
                    else res.json(animals.slice((currentPage-1)*3, currentPage*3));      
            })
            .catch(err => res.status(500).json({ error: err }));
    }else res.status(401).json({ message: "Requires authentication"});
});
apiRouter.post('/api/v1/animals/:id(\\d+)',async(req,res,next) => {
    let user = auth(req);
    if(!user) res.status(401).json({ message: "Requires authentication"});
    let hash = func.sha512(user.pass, serverSalt).passwordHash;
    let identity = await storage.getUserByLoginAndPasshash(user.name,hash);
    if (identity != null) {
        console.log(parseInt(req.params.id));
        storage.remove(parseInt(req.params.id))
            .then(result => res.json({ response: 1 }))
            .catch(err => res.status(404).json({ error: err }));
    }else  res.status(401).json({ message: "Requires authentication"});
    
});
apiRouter.post('/api/v1/animals/create',async(req,res,next) => {
    if(Object.keys(req.body).length === 0) res.status(400).json({ message: "There is no params"}); 
    let arrayOfFacts=[];
    arrayOfFacts.push(req.body.fact1,req.body.fact2,req.body.fact3,req.body.fact4,req.body.fact5,req.body.fact6,req.body.fact7)
    if(!req.files) res.status(400).json({ message: "Input fields do not satisfy the rules"}); 
    let image = new Buffer(req.files.picture.data).toString('base64');
    let picture_type = req.files.picture.name.split(".");
    let user = auth(req);
    if(!user) res.status(401).json({ message: "Requires authentication"});
    let hash = func.sha512(user.pass, serverSalt).passwordHash;
    let identity = await storage.getUserByLoginAndPasshash(user.name,hash);
    if (identity != null) {
        storage.create(req.body.breed,req.body.description,image,arrayOfFacts,picture_type[1])
            .then( result => {
                    let image = req.files.picture;
                    let imageName = image.name;
                    image.mv('./public/images/'+ imageName, function(err) {
                        if (err) return res.sendStatus(500);
                            res.json({ response: 1 });    
                    });
                 
            })
            .catch(err => res.status(500).json({ error: err }));
    }else res.status(401).json({ message: "Requires authentication"});
   
});
apiRouter.get('/api/v1/amount',async(req,res,next) => {
    let animals = await storage.searchByBreed(req.query.breed);
    res.json(animals.length)
});
apiRouter.get('/api/v1',(req,res,next) => {
    let routes ={
        animals_url:"localhost:3000/api/v1/animals",
        animals_search_url:"localhost:3000/api/v1/animals/search",
        animals_create_url:"localhost:3000/api/v1/animals/create",
        animals_delete_url:"localhost:3000/api/v1/animals/delete/{animal_id}",
        current_animal_url:"localhost:3000/api/v1/animals/{animal_id}",
        users_url:"localhost:3000/api/v1/users",
        register_url:"localhost:3000/api/v1/users",
    }
   res.json(routes)
});
apiRouter.get('/docs/api/v1',(req,res,next) => {
    res.render('docs')
});
apiRouter.post('/api/v1/register',async(req, res) => {
    if(Object.keys(req.body).length === 0) res.status(400).json({ message: "There is no params"}); 
    let username = req.body.username;
    let pass = req.body.pass;
    let pass2 = req.body.pass2;
    let password = func.sha512(pass, serverSalt).passwordHash;
    let role = "user";
    if(pass === pass2){
        storage.identityUsernameCheck(username)
            .then(result => {
                if (result == 0) {
                    storage.createUser(role,username,password)
                        .then(() => {
                            res.json({ response: 1 })
                        })
                } else res.status(406).json({ message: "This user is busy"});
            })
            .catch(err => console.log(err))
    } else res.status(400).json({ message: "Input fields do not satisfy the rules"});
           
  
});
apiRouter.post('/api/v1/login', async (req, res) => {
    if(!req.body.username || !req.body.password)  res.status(400).json({ message: "There is no params"}); 
    let hash = func.sha512(req.body.password, serverSalt).passwordHash;
    let identity = await storage.getUserByLoginAndPasshash(req.body.username,hash);
    if(identity) res.json(identity)
    else res.json({ message:"there is no such user" })
});
module.exports = apiRouter;