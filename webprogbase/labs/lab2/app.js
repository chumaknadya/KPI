
function Animal(id,name, breed, birth, lifetime) {
	return {
        id,
        name,
        breed,
        birth,
        lifetime
	};
}
function print(array) {
    for (let i in array) {
        console.log(array[i]);
    }
}
let isoformat = '^\\d{4}-\\d{2}-\\d{2}' +        // Match YYYY-MM-DD
                '((T\\d{2}:\\d{2}(:\\d{2})?)' +  // Match THH:mm:ss
                '(\\.\\d{1,6})?' +               // Match .sssss
                '(Z|(\\+|-)\\d{2}:\\d{2})?)?$';  // Time zone (Z or +hh:mm)


let matcher = new RegExp(isoformat);
function isDate (val) {
    return typeof val === 'string' &&
           matcher.test(val) &&
           !isNaN(Date.parse(val));
}
function validateISOstrng(val) {
    if(isDate(val)) return val;
    return null;
    
}
function existField(field) {
    if(field === "name" || field === "breed" ||
       field === "birth" || field === "lifetime") {
        return true;
    }
    return false;
}
// function caseUpdate() {
//     read({prompt: "Введіть індекс: "}, function (er, id) {
//         if (ifIdExist(parseInt(id))){
//             read({prompt: "Ім'я: " }, function (er, name) {
//                 read({prompt: "Порода: "}, function (er, breed) {
//                     read({prompt: "Дата народження(2011-10-05T14:48:00.000Z): "}, function (er, birth) {
//                         read({prompt: "Тривалість життя: "}, function (er, lifetime) {
//                             func.update(parseInt(id),name, breed,validateISOstrng(birth), Number(lifetime))
//                                 .then(data => {
//                                     console.log(data);
//                                     main();
//                                  })
//                                 .catch(err => console.log(err));
//                         });
//                      });
//                 });
//             });
//         }else{ 
//               console.log("Не існує такого індексу.Спробуйту ще раз"); 
//               caseUpdate();
//         }
//     });

// }
 
function caseUpdate() {
    read({prompt: "Введіть індекс: "}, function (er, id) {
        if (ifIdExist(parseInt(id))){
            read({prompt: "Введіть поле,яке ви хочете змінити: " }, function (er, field) {
                if(existField(field)) {
                    read({prompt: field + ": "}, function (er, value) {
                        func.update(parseInt(id),value,field)
                            .then(data => {
                                console.log(data);
                                main();
                            })
                            .catch(err => console.log(err));
                         });
                }else {
                    console.log("Ви ввели невірне поле,спробуйте ще раз"); 
                    caseUpdate();
                }
            });
        }else{ 
              console.log("Не існує такого індексу.Спробуйте ще раз"); 
              caseUpdate();
        }
    });

}
function caseGetAll(){
    func.getAll()     
        .then(data => {
             print(data);
             main();
        })
        .catch(err => console.log(err));
}
function caseRemove() {
    read({prompt: "Введіть індекс: "}, function (er, id) {
        if(ifIdExist(parseInt(id))) {
            func.remove(parseInt(id))     
                .then(data => {
                    print(data);
                    main();
                })
                .catch(err => console.log(err));
        } else {
            console.log("Не існує такого індексу.Спробуйте ще раз");
            caseRemove();
        }
        
    });
}

function  caseGetByIndex(){
    read({prompt: "Введіть індекс: "}, function (er, id) {
        func.getById(parseInt(id))  
            .then(data => { 
                    if(!ifIdExist(data.id)) throw er;
                    console.log(data);
                    main();
                })
            .catch(err => {
                console.log(err.name +" (Не існує такого індексу)");
                caseGetByIndex();
            });
        
    });
   
}

function caseCreate(){
    
    read({prompt: "Ім'я: " }, function (er, name) {
        read({prompt: "Порода: "}, function (er, breed) {
          read({prompt: "Дата народження(2017-09-30T21:40:00): "}, function (er, birth) {
            read({prompt: "Тривалість життя: "}, function (er, lifetime) {
                    func.create (new Animal(idGeneration(), name, breed,validateISOstrng(birth), parseInt(lifetime)))
                        .then(data =>  {
                               print(data);
                               main();
                         })
                        .catch(err=>console.log(err));
            });
          });
       });
    });

}



function switchChoice(choice) {
    
    switch(choice) {
        case "create": {
            caseCreate();
        }break;
        case "update":{
              caseUpdate();
        }break;
        case "remove":{
             caseRemove();
        }break;
        case "getAll":{
             caseGetAll();
             
        }break;
        case "getByIndex":{
            caseGetByIndex();
        }break;
        case "q":{
            console.log("Exit");
        }break;
        default: {
            console.log("Спробуйте ще раз");
            main();
        }
       
    }
}

function ifIdExist(x_id){
    let content = fs.readFileSync('animals.json',"utf-8");
    let animals = [];
    func.pushToArray(animals,JSON.parse(content)); 
    return animals.find(animal => animal.id === x_id);
}

function idGeneration() {
    let content = fs.readFileSync('animals.json',"utf-8");
    let animals = [];
    func.pushToArray(animals,JSON.parse(content)); 
    let maxVal = animals[0].id;
    for ( let i in animals) {
        if (animals[i].id > maxVal) 
            maxVal = animals[i].id;
    }      
    return (maxVal + 1);
}
function main () {
    read({prompt: "Оберіть з списку дії(create,update,remove,getAll,getByIndex): "}, function (er, choice) {
         switchChoice(choice);
    });
}
const fs = require('fs');
const func = require('./animals.js');
const read = require('read');

main();














   








