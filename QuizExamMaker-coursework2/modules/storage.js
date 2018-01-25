
let format = require('pg-format');
const pgp = require('pg-promise')({});
const config = 'postgres://nadya:1234@localhost:5432/quizExamMaker';
const db = pgp(config);
//const db = pgp(process.env.DATABASE_URL);
let cloudinary = require('cloudinary');

cloudinary.config({
    cloud_name: 'dtydyfk3a',
    api_key: '893735837756529',
    api_secret: 'ZWMf40UVGhihFAIzA0s0OlQWnTg'
});
function loadImage(mimetype, buffer, id) {
    return new Promise((resolve, reject) => {
        cloudinary.v2.uploader.upload(`data:${mimetype};base64,${buffer.toString('base64')}`, { public_id: id }, (err, result) => {
            resolve(result.secure_url);
        });
    });
}

identityUsernameCheck = async function (username) {
     let checkUsername = await db.query("SELECT * from users WHERE username=$1", username);
     console.log(checkUsername);
     return checkUsername;
}
createUser = async function (username,role,email, password) {
    let avatar_url = "https://res.cloudinary.com/dtydyfk3a/image/upload/default_avatar_nqadov"
    let sql = format("INSERT INTO users(username,role,email, password,avatar_url) VALUES ($1,$2,$3,$4,$5)");
    console.log(sql)
    let newUser = await db.query(sql,[username,role,email, password,avatar_url]);
    return true;
}  
getUserById = async function (x_id) {
    let user = await db.query('SELECT * from users  WHERE user_id=$1',[x_id]);
    //console.log("---------------")
    //console.log(user)
    return user.length > 0 ? user[0]: null;
}
getUserByLoginAndPasshash = async function (username, hash) {
    let sql = format("SELECT * from users WHERE username=$1 AND password=$2");
    console.log(sql);
    let getUserByLoginAndHash = await db.query(sql,[username,hash]);
     //console.log("-------")
    console.log(getUserByLoginAndHash)
    return getUserByLoginAndHash[0];
}
getUsers = async function() {
     let users = await db.query("SELECT * from users WHERE role='teacher' OR role='student'");
     console.log(users);
     return users;
}

setAvatar = async function(avatar,avatar_type,username){
    let x_avatar_url = (await loadImage(avatar_type,avatar));
    let sql = format("UPDATE users SET avatar_url=$1  WHERE username='"+ username+"'")
    console.log(sql);
    let newAvatar = await db.query(sql,[x_avatar_url]);
    return true;
}
createTest = async function(test_name,user_id){
    let sql = format("INSERT INTO test (test_name,user_id) VALUES ($1,$2) ")
    console.log(sql);
    let newTest = await db.query(sql,[test_name,user_id]);
    return true;
}
getMaxId = async function() {
    let sql = "SELECT MAX(id) as id FROM test"
    console.log(sql);
    let maxId = await db.query(sql);
    return maxId[0].id;
}
getMaxFromQuestion = async function() {
    let sql = "SELECT MAX(id) as id FROM question"
    console.log(sql);
    let maxId = await db.query(sql);
    return maxId[0].id;
}
createQuestion = async function(test_id,question_body,question_name,question_type) {
    let sql = format("INSERT INTO question(test_id,question_body,question_name,question_type) VALUES ($1,$2,$3,$4)")
    console.log(sql);
    let newQuestion = await db.query(sql,[test_id,question_body,question_name,question_type]);
    return true;
}
getAllTests = async function() {
     let tests = await db.query('SELECT * from test')
     return tests;
}
getTestById = async function(id) {
    let test = await db.query('SELECT * from test  WHERE id=$1 AND test_status= $2 ',[id,"Active"]);
    return test.length > 0 ? test[0]: null;
}
getQuestionByTestId = async function(test_id) {
    let questionsByTestId = await db.query('SELECT * from question  WHERE test_id=$1',[test_id]);
    console.log(questionsByTestId);
    return questionsByTestId.length > 0 ? questionsByTestId: null;
}
removeTestById = async function(id) {
    let testDelete = await db.query('DELETE  from test  WHERE id=$1',[id]);
    return true;
}
getAvatar = async function(username) {
    let sql = format("Select avatar_url from users WHERE username='"+ username+"'");
    let avatar = await db.query(sql);
    console.log(avatar[0]);
    return avatar[0];
}
searchTestByName = async function(name) {
    let regExp = name +'%';
    console.log(regExp)
    let testByName = await db.query('SELECT * from test  WHERE test_status=$1 AND test_name LIKE $2 ',["Active",regExp]);
   // let testByName = await db.query('SELECT * from test  WHERE  test_name LIKE $1 ',[regExp]);
    console.log(testByName);
    return testByName;
}
getCorrectAnswer1 = async function(id) {
     let correct =  await db.query('SELECT first_answer_correct from question  WHERE id=$1',[id]);
     return correct[0].first_answer_correct;
}
getCorrectAnswer2 = async function(id) {
    let correct =  await db.query('SELECT second_answer_correct from question  WHERE id=$1',[id]);
    return correct[0].second_answer_correct;
}
getCorrectAnswer3 = async function(id) {
    let correct =  await db.query('SELECT third_answer_correct from question  WHERE id=$1',[id]);
    return correct[0].third_answer_correct;   
}
createAnswer = async function(question_id,answer_body,isCorrect) {
    let sql = format("INSERT INTO answer(question_id,answer_body,iscorrect) VALUES ($1,$2,$3)")
    console.log(sql);
    let newAnswer = await db.query(sql,[question_id,answer_body,isCorrect]);
    return true;
}
getQuestionById = async function(id) {
    let question = await db.query('SELECT * from question WHERE id=$1',[id]);
    return question;

}
getAnswersByQuestionId = async function (id){
 let answers = await db.query('SELECT * from answer WHERE question_id=$1',[id])
 console.log(answers)
 return answers;

}
setTimeLimitForTest = async function(test_limit,test_id,test_status) {
   // UPDATE users SET avatar_url=$1  WHERE username=
    let sql= format('UPDATE test SET test_limit=$1,test_status = $2 WHERE id=$3');
    let setTestLimit =  await db.query(sql,[test_limit,test_status,test_id]);
    return true;
}
getTimeByTestId = async function(test_id) {
    let sql = format("SELECT test_limit from test  WHERE id=$1");
    let time = await db.query(sql,[test_id]);
    console.log(time)
    return time
}
setResultTable = async function(result,user_id,test_id) {
    let sql= format('INSERT INTO result(result,user_id,test_id) VALUES($1,$2,$3)');
    let setResult =  await db.query(sql,[result,user_id,test_id]);
    return true;
}
getTestByUserId = async function(user_id) {
    let test = await db.query('SELECT * from test  WHERE user_id=$1 AND test_status=$2',[user_id,"Active"]);
    console.log(test)
    return test;
}
getResultTable = async function() {
    let results = await db.query('SELECT * from result')
    return results;
}
getUserNameById = async function (id) {
    let user = await db.query('SELECT username from users WHERE user_id=$1',[id])
    return user;
}
createMarkTable = async function(user_id,mark) {
    let create = await db.query('INSERT INTO mark (user_id,mark) VALUES($1,$2)',[user_id,mark]);
    return true;
}
module.exports = {
    identityUsernameCheck,
    createUser,
    getUserById,
    getUserByLoginAndPasshash,
    getUsers,
    setAvatar,
    createTest,
    getMaxId,
    createQuestion,
    getAllTests,
    getTestById,
    getQuestionByTestId,
    removeTestById,
    getAvatar,
    searchTestByName,
    getCorrectAnswer1,
    getCorrectAnswer2,
    getCorrectAnswer3,
    createAnswer,
    getMaxFromQuestion,
    getQuestionById,
    getAnswersByQuestionId,
    setTimeLimitForTest,
    getTimeByTestId,
    setResultTable,
    getTestByUserId,
    getResultTable,
    getUserNameById,
    createMarkTable
};