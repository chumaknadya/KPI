

let model = {
    animals: [],
    filterString: "",
    page : 1,
    pageCount: 1,
    range: 3,
    currentPage: 1
};
 function getPageCount(){
    let xhttp = new XMLHttpRequest();
    xhttp.open("GET", `/api/v1/amount?breed=${model.filterString}`, true);
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            let count = this.response;
            model.pageCount =  Math.ceil(count /3)
        }
    }
    xhttp.send();
   
}
window.addEventListener('load', function () {
        getAnimals();
        let inputEl = document.getElementById('filter_string');
        inputEl.addEventListener('input', function (e) {
            model.filterString = e.target.value;
            //console.log(e.target.value)
            getAnimals();
        });
       inputEl.value = model.filterString;
       
});

async function getAnimals() {
        let xhttp = new XMLHttpRequest();
        this.animals = [];
        // задати опції запиту до веб-сервера (GET /get_data)

        xhttp.open("GET", `/api/v1/animals?breed=${model.filterString}&page=${model.page}`, true);
        getPageCount();
        console.log(`/api/v1/animals?breed=${model.filterString}&page=${model.page}`)  
        xhttp.setRequestHeader("Authorization", "Basic " + btoa(App.getState().login + ":" + App.getState().password));
        xhttp.onreadystatechange = function() {
            if (this.readyState == 4 && this.status == 200) {
                let animalObj = JSON.parse(this.response);
                let parsedAnimals = animalObj.slice((model.page-1)*3, model.page*3)
                model.animals = parsedAnimals;
               // model.animals = animalObj;
                renderRequest();                
            } 
          };
          // відправити запит
          xhttp.send();
}


function renderRequest() {
   console.log(model.animals)
   document.getElementById('items').innerHTML=
        renderTemplate('animals-list', {
            animals: model.animals,
            filterString: model.filterString
        }); 
    addPagination(); 
}


function renderTemplate(id, args) {
    const template = document.getElementById('template-' + id).innerHTML;
    if (template) {
        console.log("Download template");
        return Mustache.render(template, args)
    }
}
function addPagination() {
       
    console.log("Animals length " + model.animals.length)
    let pagination = document.getElementById('myPagination')
    if(model.animals.length != 0) {
    console.log(model.pageCount)
    let pagination = document.getElementById('myPagination')
         // clear container
    while (pagination.hasChildNodes()) {
        pagination.removeChild(pagination.lastChild);
    }

    // pagination
    let paginationEl = document.createElement('div')
    paginationEl.className = 'pagination';

    // first page
    let firstEl = document.createElement('li')
    firstEl.className = 'page-item';
    let linkEl = document.createElement('a')
    linkEl.className = 'page-link';
    let linkText = document.createTextNode(String('<<'));
    linkEl.appendChild(linkText);
    if (model.page == 1) {
        firstEl.className += ' disabled';
    } else {
        linkEl.addEventListener('click', (event) => {
            console.log(" go to first page.Current page was " + model.page)
            model.page = 1;
            getAnimals()
        });
    }
    firstEl.appendChild(linkEl);
    paginationEl.appendChild(firstEl);

    //prev page
    let prevEl = document.createElement('li')
    prevEl.className = 'page-item';
    linkEl = document.createElement('a')
    linkEl.className = 'page-link';
    linkText = document.createTextNode(String('<'));
    linkEl.appendChild(linkText);
    if (model.page == 1) {
        prevEl.className += ' disabled';
    } else {
        linkEl.addEventListener('click', (event) => {
            console.log(" go to prev page.Current page was " + model.page)
            model.page = model.page -1
            getAnimals()
        });
    }
    prevEl.appendChild(linkEl);
    paginationEl.appendChild(prevEl);

    // page
    for (let i = Math.max(1, Number(model.page - model.range));
         i <= Number(model.page) + Number(model.range) && i <= model.pageCount;
         i++) {
        let pageEl = document.createElement('li')
        pageEl.className = 'page-item';

        let linkEl = document.createElement('a')
        linkEl.className = 'page-link';
        let linkText = document.createTextNode(String(i));
        linkEl.appendChild(linkText);
        if (model.page == i) {
            pageEl.className += ' active';
        } else {
            linkEl.addEventListener('click', (event) => {
                model.page = i;
                getAnimals()
            });
        }

        pageEl.appendChild(linkEl);
        paginationEl.appendChild(pageEl);
    }

    // next page
    let nextEl = document.createElement('li')
    nextEl.className = 'page-item';

    linkEl = document.createElement('a')
    linkEl.className = 'page-link';
    linkText = document.createTextNode(String(">"));
    linkEl.appendChild(linkText);
    if (model.page == model.pageCount) {
        nextEl.className += ' disabled';
    } else {
        linkEl.addEventListener('click', (event) => {
            console.log(" go to next page .Current page was :" + model.page)
            model.page = model.page + 1;
            getAnimals()
        });
    }

    nextEl.appendChild(linkEl);
    paginationEl.appendChild(nextEl);

    // last page
    let lastEl = document.createElement('li')
    lastEl.className = 'page-item';

    linkEl = document.createElement('a')
    linkEl.className = 'page-link';
    linkText = document.createTextNode(String(">>"));
    linkEl.appendChild(linkText);
    if (model.page == model.pageCount) {
        lastEl.className += ' disabled';
    } else {
        linkEl.addEventListener('click', (event) => {
            console.log(" go to last page. Current page was : " + model.page)
            model.page = model.pageCount
            getAnimals()
        });
    }

    lastEl.appendChild(linkEl);
    paginationEl.appendChild(lastEl);

    pagination.appendChild(paginationEl);
     } else {
        while (pagination.hasChildNodes()) {
            pagination.removeChild(pagination.lastChild);
        }
    }
}