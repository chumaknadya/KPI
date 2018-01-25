
let format = require('pg-format');

const pgp = require('pg-promise')({});
//const config = 'postgres://nadya:1234@localhost:5432/animals';

const db = pgp(process.env.DATABASE_URL);
//const db = pgp(config);


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
    let animal = await db.query('SELECT * from maininformation  WHERE id=$1',[x_id]);
    return animal.length > 0 ? animal[0]: null;
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
    console.log(sql)
    let newAnimal = await db.query(sql);
    return true;
}
module.exports = {
    getAll,
    getById,
    Animal,
    remove,
    searchByBreed,
    create
};
