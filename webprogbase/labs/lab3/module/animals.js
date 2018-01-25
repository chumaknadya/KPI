
function Animal(id,breed,description, picture,facts) {
    return {
        id,
        breed,
        description,
        picture,
        facts
    }
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
        return new Promise(function(resolve, reject) {
            getArrayOfAnimalsFromFile('depository/animals.json')
                .then(animals => {
                    animals.push(x);
                    writeToFile('depository/animals.json',animals);
                    resolve(animals);
                })
                .catch(err=>  {
                    reject(err);
                });
        });
            
    }
    
        
    //отримати списком всі об'єкти зі сховища
    function getAll() {
        return new Promise(function(resolve, reject) {
            getArrayOfAnimalsFromFile('depository/animals.json')
                .then(data => {
                    resolve(data);
                })
                .catch(err=>  {
                    reject(err);
                });
        });
    } 
    //отримати елемент зі сховища за ідентифікатором
    function getById(x_id) {
        return new Promise(function(resolve, reject) {
            getArrayOfAnimalsFromFile('depository/animals.json')
                .then(animals => {
                    resolve(animals.find(animal => animal.id === x_id));
                 })
                .catch(err=>  {
                    reject(err);
                });
        });
   }  
    
   // видалити елемент зі сховища за ідентифікатором
   function remove(x_id) {
        return new Promise(function(resolve, reject) {
            getArrayOfAnimalsFromFile('depository/animals.json')
                .then(animals => {
                    delete animals[animals.indexOf(animals.find(animal =>{ if (animal.id === x_id) return animal;}))];
                    let filterArr = animals.filter(function(val){
                        return Boolean(val);  
                    });
                    writeToFile('depository/animals.json',filterArr);
                    resolve(animals);
                })
                .catch(err=>  {
                     reject(err);
                });
          
        });
   }
       

   module.exports = {
    create,
    getAll,
    getById,
    remove,
    pushToArray

   };