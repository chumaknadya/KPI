

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
            getArrayOfAnimalsFromFile('animals.json')
                .then(animals => {
                    animals.push(x);
                    writeToFile('animals.json',animals);
                    resolve(animals);
                })
                .catch(err=>  {
                    reject(err);
                });
        });
            
    }
    
        
    //отримати списком всі об'єкти зі сховища
    function getAll() {
        return getArrayOfAnimalsFromFile('animals.json');
    } 
    //отримати елемент зі сховища за ідентифікатором
    function getById(x_id) {
        return getArrayOfAnimalsFromFile('animals.json')
            .then(animals => animals.find(animal => animal.id === x_id));
   }  
    //оновити дані елемента у сховищі
    // function update(x_id,x_name, x_breed, x_birth, x_lifetime) {
    //     return new Promise(function(resolve, reject) {
    //         getArrayOfAnimalsFromFile('animals.json')
    //             .then(animals => {
    //                 let index = animals.indexOf(animals.find(animal =>{ if (animal.id === x_id) return animal}));
    //                 animals[index].name = x_name ||  animals[index].name;
    //                 animals[index].breed = x_breed ||  animals[index].breed;
    //                 animals[index].birth  = x_birth ||  animals[index].birth;
    //                 animals[index].lifetime = x_lifetime ||  animals[index].lifetime;
    //                 writeToFile('animals.json',animals);
    //                 resolve(animals[index]);
    //             })
    //             .catch(err=>  {
    //                 reject(err);
    //             });

    //     });
    // }
     function update(x_id,value,fieldValue) {
        return new Promise(function(resolve, reject) {
            getArrayOfAnimalsFromFile('animals.json')
                .then(animals => {
                    let index = animals.indexOf(animals.find(animal =>{ if (animal.id === x_id) return animal;}));
                    animals[index][fieldValue] = value ||  animals[index].fieldValue;
                    writeToFile('animals.json',animals);
                    resolve(animals[index]);
                })
                .catch(err=>  {
                    reject(err);
                });

        });
    }
   // видалити елемент зі сховища за ідентифікатором
   function remove(x_id) {
        return new Promise(function(resolve, reject) {
            getArrayOfAnimalsFromFile('animals.json')
                .then(animals => {
                    delete animals[animals.indexOf(animals.find(animal =>{ if (animal.id === x_id) return animal;}))];
                    let filterArr = animals.filter(function(val){
                        return Boolean(val);  
                    });
                    writeToFile('animals.json',filterArr);
                    resolve(animals);
                })
                .catch(err=>  {
                     reject(err);
                });
          
        });
   }
       

   module.exports = {
    create: create,
    getAll: getAll,
    getById: getById,
    update: update,
    remove: remove,
    pushToArray: pushToArray

   };