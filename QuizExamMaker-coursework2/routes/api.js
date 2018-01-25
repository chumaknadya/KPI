var express = require('express');
const apiRouter = express.Router();
const storage = require("../modules/storage.js");
const func = require("../modules/func.js")
const fs    = require('fs');
const serverSalt = "45%sAlT_";
const crypto = require('crypto');
let randomstring = require("randomstring");

apiRouter.post('/api/v1/test/create/textinput',async(req, res) => {
    console.log("text")
    console.log(req.body.question)
    let test_id = await storage.getMaxId();
    await storage.createQuestion(test_id,req.body.question,req.body.question_name,req.body.question_type)
    res.json({response:1});
})
apiRouter.post('/api/v1/test/create/multichoice',async(req, res) => {
    console.log("multi")
    console.log(req.body.question)
    console.log(req.body.answerBody)
    let test_id = await storage.getMaxId();
    await storage.createQuestion(test_id,req.body.question,req.body.question_name,req.body.question_type,req.body.question_type)
    let answers = req.body.answerBody.split(',');
    let answersCheck = req.body.answerCheck.split(',')
    let question_id = await storage.getMaxFromQuestion();
    for(let i = 0; i < answersCheck.length; i++) {
        console.log( req.body.answerBody[i])
        console.log(answersCheck[i])
        //await storage.createAnswer(question_id,answers[i],answersCheck[i])
        await storage.createAnswer(question_id,answers[i])
    }
    res.json({response:1});
})
apiRouter.post('/api/v1/test/create/dropdown',async(req, res) => {
    console.log("drop")
    console.log(req.body.question)
    console.log(req.body.answerBody)
    let test_id = await storage.getMaxId();
    await storage.createQuestion(test_id,req.body.question,req.body.question_name,req.body.question_type)
    let answers = req.body.answerBody.split(',');
    let answersCheck = req.body.answerCheck.split(',')
    let question_id = await storage.getMaxFromQuestion();
    for(let i = 0; i < answersCheck.length; i++) {
        console.log(answers[i])
        console.log(answersCheck[i])
        //await storage.createAnswer(question_id,answers[i],answersCheck[i])
        await storage.createAnswer(question_id,answers[i])
    }
    res.json({response:1});
})
apiRouter.get('/api/v1/test/textinput',async(req, res) => {
    let question_id = await storage.getMaxFromQuestion();
    let question = await storage.getQuestionById(question_id)
    res.json(question);
})
apiRouter.get('/api/v1/test/multiply',async(req, res) => {
    let question_id = await storage.getMaxFromQuestion();
    let data= [];
    let question = await storage.getQuestionById(question_id)
    let answers = await storage.getAnswersByQuestionId(question[0].id)
    data.push({"id":question[0].id})
    data.push({"question_body":question[0].question_body})
    
    for (let i = 0; i < answers.length; i++) {
        data.push({"answer_body":answers[i].answer_body})
    }
    
    res.json(data);
})
apiRouter.get('/api/v1/tests', async(req, res, next) => {
    let tests = await storage.searchTestByName(req.query.name);
    res.json(tests)
});
apiRouter.get('/api/v1/amount',async(req,res,next) => {
    let tests = await storage.searchTestByName(req.query.name);
    res.json(tests.length)
});

apiRouter.post('/api/v1/test/save',async(req,res,next) => {
    console.log(req.body.test_limit)
    console.log(req.body.test_status)
    let test_id = await storage.getMaxId();
    let success = await storage.setTimeLimitForTest(req.body.test_limit,test_id,req.body.test_status); 
    res.json({response:1});
})
apiRouter.post('/api/v1/testTime',async(req,res,next) => {
    
    let time = await storage.getTimeByTestId(req.body.id);
    res.json(time);
})
apiRouter.post('/api/v1/questions',async(req,res,next) => {

    let result = await storage.getQuestionByTestId(req.body.id);
    res.json(result)

});
apiRouter.post('/api/v1/result',async(req,res,next) => {
    console.log(req.body.data)
    //let name = req.body.name;
    let name = randomstring.generate(12);
    fs.writeFile("./storage/"+name +".pdf",req.body.data, function(err) {
        if(err) {
            return console.log(err);
        }
        storage.setResultTable(name+".pdf",req.body.user_id,req.body.test_id)
            .then(res)
            .catch(e=> console.log(e))
        console.log("File saved successfully!");
    });
    res.json({response:1})

})
apiRouter.post('/api/v1/setmark',async(req,res,next) => {

    await storage.createMarkTable(req.body.user_id,req.body.mark);
    res.json({response:1})
})
module.exports = apiRouter;