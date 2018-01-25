
let format = require('pg-format');
const pgp = require('pg-promise')({});
const config = 'postgres://nadya:1234@localhost:5432/animals';
const db = pgp(config);
function Animal(id,breed,description, picture,facts) {
    return {
        id,
        breed,
        description,
        picture,
        facts
    }
  }

getAll = async function (){
    let animals = await db.query('SELECT * from maininformation');
     return animals.length > 0 ? animals : null;
}
getById = async function (x_id) {
    let animals = await db.query('SELECT * from maininformation  WHERE id=$1',[x_id]);
    return animals.length > 0 ? animals[0]: null;
}
 remove = async function (x_id) {
    let animalDelete = await db.query('DELETE  from maininformation  WHERE id=$1',[x_id]);
    return true;
}
searchByBreed = async function (x_breed){
    let animalsByBreed =  await db.query('SELECT * from maininformation  WHERE breed=$1', [x_breed])
    return animalsByBreed;
}
create = async function (x_breed,x_description,x_picture,x_facts,x_picture_type) {
    let sql = format("INSERT INTO maininformation(breed,description,facts,picture,picture_type) VALUES ('%s','%s','{%s}','%s','%s')",
    x_breed,x_description,x_facts,x_picture,x_picture_type);
    //console.log(sql)
    let newAnimal = await db.query(sql);
    return true;
}  
identityUsernameCheck = async function (username) {
    let checkUsername = await db.query("SELECT * from users WHERE username=$1", username);
    //console.log(checkUsername);
    return checkUsername;
}
createUser = async function (role,username,password) {
    let sql = format("INSERT INTO users(role,username,password) VALUES ('%s','%s','%s')",role,username,password);
    console.log(sql)
    let newAnimal = await db.query(sql);
    return true;
}  
getUserById = async function (x_id) {
    let user = await db.query('SELECT * from users  WHERE user_id=$1',[x_id]);
    //console.log("---------------")
    //console.log(user)
    return user.length > 0 ? user[0]: null;
}
getUserByLoginAndPasshash = async function (username, hash) {
    let sql = format("SELECT * from users WHERE username='%s' AND password='%s'",username,hash);
    console.log(sql);
    let getUserByLoginAndHash = await db.query(sql);
     //console.log("-------")
    //console.log(getUserByLoginAndHash)
    return getUserByLoginAndHash[0];
}
getUsers = async function() {
    let users = await db.query("SELECT * from users WHERE role='user'");
    //console.log(users);
    return users;
}
module.exports = {
    getAll,
    getById,
    Animal,
    remove,
    searchByBreed,
    create,
    identityUsernameCheck,
    createUser,
    getUserById,
    getUserByLoginAndPasshash,
    getUsers
};