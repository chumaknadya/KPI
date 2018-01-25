let express = require('express');
let router = express.Router();
const storage = require("../modules/storage.js");
const fs    = require('fs');
const func = require("../modules/func.js")
router.get('/tests/create/design', (req, res, next) => {
      res.render('test_design')
})

router.get('/tests',func.checkAuth, (req, res, next) => {
    storage.getAllTests() 
        .then(tests=>{
            res.render('tests',{user:req.user});
        })
        .catch(err=>{
            console.log(err);
            res.sendStatus(500);
        })
});
router.get('/tests/create',func.checkAuth,(req, res, next) => {
    res.render('createTest');
});
router.post('/tests/create',(req, res, next) => {
    console.log(req.user.user_id)
    console.log(req.body.testName);
    storage.createTest(req.body.testName,req.user.user_id)
        .then(result => res.render('test_design'))
        .catch(err=>{
            console.log(err);
            res.sendStatus(500);
        });
    
});


router.get('/tests/:id(\\d+)',func.checkAuth,async(req, res, next) => {
    console.log(req.params.id)
    // storage.getTestById(parseInt(req.params.id))
    //    .then(test => {
    //       console.log(test);
    //       storage.getQuestionByTestId(test.id) 
    //         .then(questions => {
    //             console.log(questions)
    //             let answers = [];
    //             let data;
    //             for ( let i = 0; i < questions.length; i++) {
    //                 data = await storage.getAnswersByQuestionId(questions[i].id);
    //                 answers.push(data)
    //             }
    //             console.log(answers)
    //             //let answers = await storage.getAnswersByQuestionId();
    //             res.render('test_view',{test,questions});
    //         })
    //         .catch(err=> {
    //             console.log(err);
    //             res.sendStatus(500) 
    //         });
          
    //    })
    //    .catch(err => {
    //        console.log(err);
    //        res.sendStatus(500);
    //    });
    try{
        let test = await storage.getTestById(parseInt(req.params.id));
        let questions = await  storage.getQuestionByTestId(test.id) 
        let answers = [];
        let data;
        for ( let i = 0; i < questions.length; i++) {
            data = await storage.getAnswersByQuestionId(questions[i].id);
            console.log("daaaataaaa")
            for(let i = 0; i < data.length; i++) {
               //console.log(data[i])
                answers.push(data[i])
            }
            //answers.push(data)
        }
        console.log(answers)
        res.render('test_view',{test,questions,answers,
        user:req.user});
    }catch(e) {
        console.log(e);
        res.sendStatus(500);
    }
    
});
router.post('/tests/:id',(req, res, next) => {
    console.log("------------");
    console.log(req.body.id);
    storage.removeTestById(parseInt(req.body.id))
        .then(result => res.redirect('/'))
        .catch(err=> {
            console.log(err);
            res.sendStatus(500) 
        });
});

router.get('/results',func.checkAuth,async(req, res, next) => {
    try{
       let tests =  await storage.getTestByUserId(req.user.user_id)
       let result = await storage.getResultTable();
       let sortRes = [];
       for (let i = 0 ; i < tests.length; i ++) {
            for(let j = 0;j < result.length; j ++) {
                if(tests[i].id == result[j].test_id) {
                    sortRes.push(result[j])
                }
            }
       }
       let user;
       let arrayOfUsers =[];
       for (let i = 0; i < sortRes.length; i ++) {
            user = await storage.getUserNameById(sortRes[i].user_id)
            arrayOfUsers.push(user[0])
       }
      // console.log(arrayOfUsers)
       //console.log(sortRes)
       res.render('result',{
           result:sortRes,
           users:arrayOfUsers
       })
    }
    catch(e) {
        console.log(e)
        res.sendStatus(500);
    }
       
   
});
router.get('/tests/pdf',func.checkAuth,(req, res, next) => {
    console.log(req.query.name)
    var stream = fs.createReadStream('./storage/'+req.query.name);
    stream.on('open', function () {
        let filename = encodeURIComponent(req.query.name);
        res.setHeader('Content-disposition', 'inline; filename="' + filename + '"');
        res.setHeader('Content-type', 'application/pdf');
        stream.pipe(res);
    });
    stream.on('error', function(err) {
        res.end(err);
    });   
});


module.exports = router;