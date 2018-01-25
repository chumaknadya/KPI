
function Animal(id,breed,description, picture,facts) {
    return {
        id,
        breed,
        description,
        picture,
        facts
    }
  }
  

   

function idGeneration() {
    const fs = require('fs');
    let content = fs.readFileSync('./depository/animals.json',"utf-8");
    let animals = [];
    pushToArray(animals,JSON.parse(content)); 
    let maxVal = animals[0].id;
    for ( let i in animals) {
        if (animals[i].id > maxVal) 
            maxVal = animals[i].id;
    }      
    return (maxVal + 1);
}


    function pushToArray(array,data) {
        for (let i in data) {
            array.push(data[i]);
         }
    }
    function writeToFile(filename,data) {
        fs.writeFile(filename, JSON.stringify(data,null, 4), 'utf8', (err) => {
            if (err) {
                console.error(err);
                return;
            }
        });
    }

    const fs = require('fs');
    function getArrayOfAnimalsFromFile(filename) {
         return new Promise((resolve, reject) => {
            fs.readFile(filename, (err, data) => {
                if(err) reject(err);
                else { 
                    let animals = [];
                    pushToArray(animals,JSON.parse(data)); 
                    resolve(animals);
                 }
            });
         });
    }  

    //додати у сховище новий елемент
    function create(x) {
        return  getArrayOfAnimalsFromFile('./depository/animals.json')
                .then(animals => {
                    animals.push(x);
                    writeToFile('./depository/animals.json',animals);
                    return animals;
                });
    }
    
        
    //отримати списком всі об'єкти зі сховища
    function getAll() {
        return getArrayOfAnimalsFromFile('./depository/animals.json');
    } 
    //отримати елемент зі сховища за ідентифікатором
    function getById(x_id) {
        return getArrayOfAnimalsFromFile('depository/animals.json')
                .then(animals => animals.find(animal => animal.id === x_id));
    }  
    
   // видалити елемент зі сховища за ідентифікатором
   function remove(x_id) {
        return getArrayOfAnimalsFromFile('./depository/animals.json')
                .then(animals => {
                    delete animals[animals.indexOf(animals.find(animal =>{ if (animal.id === x_id) return animal;}))];
                    let filterArr = animals.filter(function(val){
                        return Boolean(val);  
                    });
                    writeToFile('./depository/animals.json',filterArr);
                });
   }
 
 function arrayFilter(array, condition){
    let filterArr = [];
    for (let i in array) {
           if(array[i].breed === condition) {
           filterArr.push(array[i]);
        }
    }
    return filterArr;
    }

    function searchByBreed(x_breed) {
        return getArrayOfAnimalsFromFile('./depository/animals.json')
        .then(animals => {
                return arrayFilter(animals,x_breed);
        });

    }

   module.exports = {
    create,
    getAll,
    getById,
    remove,
    pushToArray,
    Animal,
    idGeneration,
    searchByBreed

   };