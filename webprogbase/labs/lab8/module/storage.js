
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
    let regExp = x_breed +'%';
    console.log(regExp)
    let animalsByBreed =  await db.query("SELECT * from maininformation  WHERE breed LIKE $1 ", [regExp])
    console.log(animalsByBreed)
    return animalsByBreed;
}
create = async function (x_breed,x_description,x_picture,x_facts,x_picture_type,x_picture_name) {
    let sql = format("INSERT INTO maininformation(breed,description,facts,picture,picture_type,picture_name) VALUES ($1,$2,$3,$4,$5,$6)");
    //console.log(sql)
    let newAnimal = await db.query(sql,[x_breed,x_description,x_facts,x_picture,x_picture_type,x_picture_name]);
    return true;
}  
identityUsernameCheck = async function (username) {
    let checkUsername = await db.query("SELECT * from users WHERE username=$1", username);
    //console.log(checkUsername);
    return checkUsername;
}
createUser = async function (role,username,password) {
    let sql = format("INSERT INTO users(role,username,password) VALUES ($1,$2,$3)");
    console.log(sql)
    let newAnimal = await db.query(sql,[role,username,password]);
    return true;
}  
getUserById = async function (x_id) {
    let user = await db.query('SELECT * from users  WHERE user_id=$1',[x_id]);
    //console.log("---------------")
    //console.log(user)
    return user.length > 0 ? user[0]: null;
}
getUserByUsername = async function(x_username) {
    let regExp = x_username +'%';
    let user = await db.query('SELECT * from users  WHERE username LIKE $1',[regExp]);
    return user.length > 0 ? user : null;
}
getUserByLoginAndPasshash = async function (username, hash) {
    let sql = format("SELECT * from users WHERE username='%s' AND password='%s'",username,hash);
    console.log(sql);
    let getUserByLoginAndHash = await db.query(sql);
     //console.log("-------")
    //console.log(getUserByLoginAndHash)
    return getUserByLoginAndHash.length > 0 ? getUserByLoginAndHash[0] : null;
}
getUsers = async function() {
    let users = await db.query("SELECT * from users WHERE role='user'");
    //console.log(users);
    return users.length > 0 ? users : null;;
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
    getUsers,
    getUserByUsername
};